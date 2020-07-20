#define _CRT_SECURE_NO_WARNINGS
#include <GL\glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <gl\GL.h>


// dimensiunea linii
#define lines 15
// dimensiunea coloane
#define columns 15
// dimensiune margine grila - fereastra
#define margin 0.1
// dimensiunea ferestrei in pixeli
#define dim 300

int width = dim;
int height = dim;
int radius = 10;

unsigned char prevKey;

class Punct
{
public:
	Punct(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int getX()
	{
		return x;
	}

	void setX(int x)
	{
		this->x = x;
	}

	int getY()
	{
		return y;
	}

	void setY(int y)
	{
		this->y = y;
	}

private:
	int x, y;
};

class GrilaCarteziana
{
public:
	GrilaCarteziana(int linesGrilaCarteziana, int columnsGrilaCarteziana)
	{
		this->linesGrila = linesGrilaCarteziana;
		this->columnsGrila = columnsGrilaCarteziana;
	}

	void display()
	{
		glColor3f(0.0, 0.0, 0.0);
		
		double min;
		if (width > height)
			min = height;
		else min = width;
		
		double xmax = (double)width / (double)min + margin;
		double ymax = (double)height / (double)min + margin;

		for (double i = 0; i < columns + 1; i++)
		{
			glBegin(GL_LINE_STRIP);
			glVertex2f(-1.0 / xmax, (2.0 / (double)columns * i - 1) / ymax);
			glVertex2f(1.0 / xmax, (2.0 / (double)columns * i - 1) / ymax);
			glEnd();
		}

		for (double i = 0; i < lines + 1; i++)
		{
			glBegin(GL_LINE_STRIP);
			glVertex2f((2.0 / (double)lines * i - 1) / xmax, -1.0 / ymax);
			glVertex2f((2.0 / (double)lines * i - 1) / xmax, 1.0 / ymax);
			glEnd();
		}
	}

	void writePixel(int line, int column)
	{
		if (line > lines || column > columns || line < 0 || column < 0)
			return;

		glColor3f(0.0, 0.0, 0.0);

		double min;
		if (width > height)
			min = height;
		else min = width;

		double xmax = (double)width / (double)min + margin;
		double ymax = (double)height / (double)min + margin;

		float cx = (2.0 / (double)columns * line - 1) / xmax;
		float cy = (2.0 / (double)lines * column - 1) / ymax;

		double xymin;
		if (xmax > ymax)
			xymin = ymax;
		else xymin = xmax;

		float r;
		if (lines > columns)
			r = xymin / (columns * 2);
		else r = xymin / (lines * 2);

		int num_segments = 25;

		glBegin(GL_POLYGON);
		for (int i = 0; i < num_segments; i++)
		{
			float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);

			float x = r * cosf(theta);
			float y = r * sinf(theta);

			glVertex2f(x / xmax + cx, y / ymax + cy);
		}
		glEnd();
	}

	void writeLine(int xBegin, int yBegin, int xEnd, int yEnd, int dots)
	{
		glColor3f(1.0, 0.1, 0.1);
		glLineWidth(4.f);

		float cxBegin, cyBegin, cxEnd, cyEnd, cx, cy;

		getXY(xBegin, yBegin, cxBegin, cyBegin);
		getXY(xEnd, yEnd, cxEnd, cyEnd);

		glBegin(GL_LINE_STRIP);
		glVertex2f(cxBegin, cyBegin);
		glVertex2f(cxEnd, cyEnd);
		glEnd();
		glLineWidth(1.f);

		std::vector<Punct> list = AfisareSegmentDreapta3(xBegin, yBegin, xEnd, yEnd, dots);

		for (std::vector<Punct>::iterator it = list.begin(); it != list.end(); ++it)
			writePixel(it->getX(), it->getY());
	}

	std::vector<Punct> AfisareSegmentDreapta3(int xBegin, int yBegin, int xEnd, int yEnd, int dots)
	{
		double m = ((double)yEnd - (double)yBegin) / ((double)xEnd - (double)xBegin);

		if (m > 0)
		{
			if (xBegin > xEnd)
				return writeLineUpper(xEnd, yEnd, xBegin, yBegin, dots);
			else
				return writeLineUpper(xBegin, yBegin, xEnd, yEnd, dots);
		}
		else
		{
			if (xBegin > xEnd)
				return writeLineLower(xEnd, yEnd, xBegin, yBegin, dots);
			else
				return writeLineLower(xBegin, yBegin, xEnd, yEnd, dots);
		}
		std::vector<Punct> puncte;
		return puncte;
	}

	std::vector<Punct> writeLineUpper(int xBegin, int yBegin, int xEnd, int yEnd, int dots)
	{
		std::vector<Punct> puncte;
		int dy = yEnd - yBegin;
		int dx = xEnd - xBegin;

		int d = 2 * dy - dx;
		int dE = 2 * dy;
		int dNE = 2 * (dy - dx);
		int x = xBegin, y = yBegin;

		puncte.push_back(Punct(x, y));
		for (int i = 1; i <= dots / 2; i++)
		{
			puncte.push_back(Punct(x, y - i));
			puncte.push_back(Punct(x, y + i));
		}

		while (x < xEnd)
		{
			if (d <= 0)
			{
				d += dE;
				x++;
			}
			else
			{
				d += dNE;
				x++;
				y++;
			}

			puncte.push_back(Punct(x, y));
			for (int i = 1; i <= dots / 2; i++)
			{
				puncte.push_back(Punct(x, y - i));
				puncte.push_back(Punct(x, y + i));
			}
		}
		return puncte;
	}

	std::vector<Punct> writeLineLower(int xBegin, int yBegin, int xEnd, int yEnd, int dots)
	{
		std::vector<Punct> puncte;
		int dy = yEnd - yBegin;
		int dx = xEnd - xBegin;

		int d = 2 * dy + dx;
		int dE = 2 * dy;
		int dSE = 2 * (dy + dx);
		int x = xBegin, y = yBegin;

		puncte.push_back(Punct(x, y));
		for (int i = 1; i <= dots / 2; i++)
		{
			puncte.push_back(Punct(x, y - i));
			puncte.push_back(Punct(x, y + i));
		}

		while (x < xEnd)
		{
			if (d >= 0)
			{
				d += dE;
				x++;
			}
			else
			{
				d += dSE;
				x++;
				y--;
			}

			puncte.push_back(Punct(x, y));
			for (int i = 1; i <= dots / 2; i++)
			{
				puncte.push_back(Punct(x, y - i));
				puncte.push_back(Punct(x, y + i));
			}
		}
		return puncte;
	}

private:
	int linesGrila;
	int columnsGrila;

	void getXY(int line, int column, float& resultX, float& resultY) 
	{
		double min;
		if (width > height)
			min = height;
		else min = width;

		double xmax = (double)width / (double)min + margin;
		double ymax = (double)height / (double)min + margin;

		resultX = (2.0 / (double)columns * line - 1) / xmax;
		resultY = (2.0 / (double)lines * column - 1) / ymax;
	}
};

void Init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glLineWidth(1);

	//glPointSize(4);

	glPolygonMode(GL_FRONT, GL_FILL);
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	GrilaCarteziana grilaCarteziana(lines, columns);

	grilaCarteziana.display();

	grilaCarteziana.writeLine(0, 15, 15, 10, 3);

	grilaCarteziana.writeLine(0, 0, 15, 7, 1);

	glRasterPos2d(-0.98, -0.98);
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '0');

	glRasterPos2d(-0.98, 0.92);
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'Y');

	glRasterPos2d(0.92, -0.98);
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'X');

	glFlush();
}

void Reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void KeyboardFunc(unsigned char key, int x, int y)
{
	prevKey = key;
	if (key == 27) // escape
		exit(0);
	glutPostRedisplay();
}

void MouseFunc(int button, int state, int x, int y) {}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitWindowSize(width, height);

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
