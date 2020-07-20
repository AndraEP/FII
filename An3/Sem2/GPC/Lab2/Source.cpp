#include <GL/glut.h>

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// dimensiunea ferestrei in pixeli
#define dim 300

unsigned char prevKey;
double pi = 4 * atan(1);

// concoida lui Nicomede (concoida dreptei)
// $x = a + b \cdot cos(t), y = a \cdot tg(t) + b \cdot sin(t)$. sau
// $x = a - b \cdot cos(t), y = a \cdot tg(t) - b \cdot sin(t)$. unde
// $t \in (-\pi / 2, \pi / 2)$
void Display1() {
    double xmax, ymax, xmin, ymin;
    double a = 1, b = 2;
    double ratia = 0.05;

    // calculul valorilor maxime/minime ptr. x si y
    // aceste valori vor fi folosite ulterior la scalare
    xmax = a - b - 1;
    xmin = a + b + 1;
    ymax = ymin = 0;

    for (double t = -pi / 2 + ratia; t < pi / 2; t += ratia) {
        double x1, y1, x2, y2;
        x1 = a + b * cos(t);
        xmax = (xmax < x1) ? x1 : xmax;
        xmin = (xmin > x1) ? x1 : xmin;

        x2 = a - b * cos(t);
        xmax = (xmax < x2) ? x2 : xmax;
        xmin = (xmin > x2) ? x2 : xmin;

        y1 = a * tan(t) + b * sin(t);
        ymax = (ymax < y1) ? y1 : ymax;
        ymin = (ymin > y1) ? y1 : ymin;

        y2 = a * tan(t) - b * sin(t);
        ymax = (ymax < y2) ? y2 : ymax;
        ymin = (ymin > y2) ? y2 : ymin;
    }

    xmax = (fabs(xmax) > fabs(xmin)) ? fabs(xmax) : fabs(xmin);
    ymax = (fabs(ymax) > fabs(ymin)) ? fabs(ymax) : fabs(ymin);

    // afisarea punctelor propriu-zise precedata de scalare
    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double t = -pi / 2 + ratia; t < pi / 2; t += ratia) {
        double x1, y1, x2, y2;
        x1 = (a + b * cos(t)) / xmax;
        x2 = (a - b * cos(t)) / xmax;
        y1 = (a * tan(t) + b * sin(t)) / ymax;
        y2 = (a * tan(t) - b * sin(t)) / ymax;

        glVertex2f(x1, y1);
    }
    glEnd();

    glBegin(GL_LINE_STRIP);
    for (double t = -pi / 2 + ratia; t < pi / 2; t += ratia) {
        double x1, y1, x2, y2;
        x1 = (a + b * cos(t)) / xmax;
        x2 = (a - b * cos(t)) / xmax;
        y1 = (a * tan(t) + b * sin(t)) / ymax;
        y2 = (a * tan(t) - b * sin(t)) / ymax;

        glVertex2f(x2, y2);
    }
    glEnd();
}

// graficul functiei 
// $f(x) = \bar sin(x) \bar \cdot e^{-sin(x)}, x \in \langle 0, 8 \cdot \pi \rangle$, 
void Display2() {
    double xmax = 8 * pi;
    double ymax = exp(1.1);
    double ratia = 0.05;

    // afisarea punctelor propriu-zise precedata de scalare
    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double x = 0; x < xmax; x += ratia) {
        double x1, y1;
        x1 = x / xmax;
        y1 = (fabs(sin(x)) * exp(-sin(x))) / ymax;

        glVertex2f(x1, y1);
    }
    glEnd();
}

//functia
void Display3()
{
    double ratia = 0.05;
    double xmax = 25;
    double y = 1;

    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double x = 0; x < xmax; x += ratia)
    {
        if (x > 0)
        {
            double ceil_value = ceil(x) - x;
            double floor_value = x - floor(x);

            y = (floor_value < ceil_value) ? (floor_value / x) : (ceil_value / x);
        }
        double x1, y1;
        x1 = x / xmax;
        y1 = y - ratia/2;

        glVertex2f(x1, y1);
    }
    glEnd();
}

//melcul lui pascal
void Display4()
{
    double ratia = 0.05;
    double a = 0.3;
    double b = 0.2;

    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double t = -pi + ratia; t < pi; t += ratia)
    {
        double x1 = 2 * (a * cos(t) + b) * cos(t);
        double y1 = 2 * (a * cos(t) + b) * sin(t);

        glVertex2f(x1, y1);
    }
    glEnd();
}

//trisectoarea
void Display5()
{
    double ratia = 0.005;
    double a = 0.2;
    double y[300], x[300];

    glColor3f(0.0, 0.0, 1.0); // albastru
    glBegin(GL_LINE_STRIP);
    int n = 0;
    for (double t = -(pi / 2) + ratia; t < -(pi / 6); t += ratia)
    {
        double x1 = a / (4 * cos(t) * cos(t) - 3);
        double y1 = (a * tan(t)) / (4 * cos(t) * cos(t) - 3);
        x[n] = x1;
        y[n] = y1;
        n += 1;

        glVertex2f(x1, y1);
    }
    glEnd();

    
    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_TRIANGLES);
    for (int i = 1; i < n - 1; i += 3)
    {
        if (i > n / 4 && i < 3 * n / 4) continue;

        glVertex2f(-1.0, 1.0);
        glVertex2f(x[i], y[i]);
        glVertex2f(x[i + 1], y[i + 1]);
    }
    glEnd();

}

//cicloida
void Display6()
{
    double ratia = 0.05;
    double a = 0.1;
    double b = 0.2;
    
    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double t = -(4 * pi) + ratia; t < pi * 4; t += ratia)
    {
        double x1 = a * t - b * sin(t);
        double y1 = a - b * cos(t);

        glVertex2f(x1, y1);
    }
    glEnd();
}

//epicicloida
void Display7()
{
    double ratia = 0.05;
    double R = 0.1;
    double r = 0.3;
    double fraction = r / R;

    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double t = 0 + ratia; t < pi * 2; t += ratia)
    {
        double x1 = (R + r) * cos(fraction * t) - r * cos(t + fraction * t);
        double y1 = (R + r) * sin(fraction * t) - r * sin(t + fraction * t);

        glVertex2f(x1, y1);
    }
    glEnd();
}

//hipocicloida
void Display8()
{
    double ratia = 0.05;
    double R = 0.1;
    double r = 0.3;
    double fraction = r / R;

    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double t = 0 + ratia; t < pi * 2; t += ratia)
    {
        double x1 = (R - r) * cos(fraction * t) - r * cos(t - fraction * t);
        double y1 = (R - r) * sin(fraction * t) - r * sin(t - fraction * t);

        glVertex2f(x1, y1);
    }
    glEnd();
}

//bernoulli
void Display9()
{
    double ratia = 0.005;
    double a = 0.4;


    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double t = pi / 4 - ratia; t > -(pi / 4); t -= ratia)
    {
        double x1 = (a * sqrt(2 * cos(2 * t))) * cos(t);
        double y1 = (a * sqrt(2 * cos(2 * t))) * sin(t);

        glVertex2f(x1, y1);
    }

    for (double t = -(pi / 4) + ratia; t < pi / 4; t += ratia)
    {
        double x1 = (-(a * sqrt(2 * cos(2 * t)))) * cos(t);
        double y1 = (-(a * sqrt(2 * cos(2 * t)))) * sin(t);

        glVertex2f(x1, y1);
    }
    glEnd();
}

//spirala
void Display10()
{
    double ratia = 0.05;
    double a = 0.02;


    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double t = 0 + ratia; t < pi * 10000; t += ratia)
    {
        double x1 = (a * exp(1 + t)) * cos(t);
        double y1 = (a * exp(1 + t)) * sin(t);

        glVertex2f(x1, y1);
    }

    glEnd();
}

void Init(void) {

    glClearColor(1.0, 1.0, 1.0, 1.0);

    glColor3f(1,0.1,0.1);

    glLineWidth(1);

    glPointSize(0.5);

    glPolygonMode(GL_FRONT, GL_LINE);
}

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    switch (prevKey) {
    case '1':
        Display1();
        break;
    case '2':
        Display2();
        break;
    case '3':
        Display3();
        break;
    case '4':
        Display4();
        break;
    case '5':
        Display5();
        break;
    case '6':
        Display6();
        break;
    case '7':
        Display7();
        break;
    case '8':
        Display8();
        break;
    case '9':
        Display9();
        break;
    case '0':
        Display10();
        break;
    default:
        break;
    }

    glFlush();
}

void Reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void KeyboardFunc(unsigned char key, int x, int y) {
    prevKey = key;
    if (key == 27) // escape
        exit(0);
    glutPostRedisplay();
}

void MouseFunc(int button, int state, int x, int y) {
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitWindowSize(dim, dim);

    glutInitWindowPosition(100, 100);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutCreateWindow(argv[0]);

    Init();

    glutReshapeFunc(Reshape);

    glutKeyboardFunc(KeyboardFunc);

    glutMouseFunc(MouseFunc);

    glutDisplayFunc(Display);

    glutMainLoop();

    return 0;
}