#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <fstream>
#include <GL\glut.h>
#include <gl\GL.h>
#include <map>
#include <algorithm>

// dimensiune margine grila - fereastra
#define margin 0.1
// dimensiunea ferestrei in pixeli
#define dim 300

using namespace std;

int width = dim;
int height = dim;
int radius = 10;

unsigned char prevKey;

class Punct
{
public:
	Punct()
	{
		this->x = 0;
		this->y = 0;
	}

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

struct Muchie
{
	Muchie(Punct vi, Punct vf)
	{
		this->vi = vi;
		this->vf = vf;
	}

	Punct vi, vf;
};

class Poligon
{
public:
	vector<Muchie> muchii;
};

struct Intersectie
{
	Intersectie(int ymax, double xmin, double ratia)
	{
		this->ymax = ymax;
		this->xmin = xmin;
		this->ratia = ratia;
	}

	Intersectie(const Intersectie& intersectie)
	{
		this->ymax = intersectie.ymax;
		this->xmin = intersectie.xmin;
		this->ratia = intersectie.ratia;
	}

	bool operator< (const Intersectie& i)
	{
		return this->xmin < i.xmin;
	}

	int ymax;
	double xmin;
	double ratia;
};

class GrilaCarteziana
{
public:
	GrilaCarteziana(int linesGrilaCarteziana, int columnsGrilaCarteziana)
	{
		linesGrila = linesGrilaCarteziana;
		columnsGrila = columnsGrilaCarteziana;
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


		for (double i = 0; i < columnsGrila + 1; i++)
		{
			glBegin(GL_LINE_STRIP);
			glVertex2f(-1.0 / xmax, (2.0 / (double)columnsGrila * i - 1) / ymax);
			glVertex2f(1.0 / xmax, (2.0 / (double)columnsGrila * i - 1) / ymax);
			glEnd();
		}

		for (double i = 0; i < linesGrila + 1; i++)
		{
			glBegin(GL_LINE_STRIP);
			glVertex2f((2.0 / (double)linesGrila * i - 1) / xmax, -1.0 / ymax);
			glVertex2f((2.0 / (double)linesGrila * i - 1) / xmax, 1.0 / ymax);
			glEnd();
		}
	}

	void writePixel(int line, int column)
	{
		glColor3f(0.1, 0.1, 0.1); // rosu

		double min;
		if (width > height)
			min = height;
		else min = width;

		double xmax = (double)width / (double)min + margin;
		double ymax = (double)height / (double)min + margin;

		float cx = (2.0 / (double)this->columnsGrila * line - 1) / xmax;
		float cy = (2.0 / (double)this->linesGrila * column - 1) / ymax;

		double xymin;
		if (xmax > ymax)
			xymin = ymax;
		else xymin = xmax;

		float r = xymin / (linesGrila > columnsGrila ? linesGrila * 2 : columnsGrila * 2);

		int num_segments = 25;

		glBegin(GL_POLYGON);
		for (int ii = 0; ii < num_segments; ii++)
		{
			float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

			float x = r * cosf(theta);//calculate the x component
			float y = r * sinf(theta);//calculate the y component

			glVertex2f(x / xmax + cx, y / ymax + cy);//output vertex

		}
		glEnd();
	}

	void writeLine(int xBegin, int yBegin, int xEnd, int yEnd, int dots)
	{
		glColor3f(1.0, 0.1, 0.1); //rosu
		glLineWidth(4.f);

		float cxBegin, cyBegin, cxEnd, cyEnd, cx, cy;

		getXY(xBegin, yBegin, cxBegin, cyBegin);
		getXY(xEnd, yEnd, cxEnd, cyEnd);

		glBegin(GL_LINE_STRIP);
		glVertex2f(cxBegin, cyBegin);
		glVertex2f(cxEnd, cyEnd);
		glEnd();
		glLineWidth(1.f);

		std::vector<Punct> list = writeLineAlgoritm(xBegin, yBegin, xEnd, yEnd, dots);

		for (std::vector<Punct>::iterator it = list.begin(); it != list.end(); ++it) {
			writePixel(it->getX(), it->getY());
		}
	}

	void deseneazaCerc(int x, int y, int raza, int dots) {
		glColor3f(1.0, 0.1, 0.1); // rosu
		glLineWidth(4.f);

		double min = width > height ? height : width;

		float cx, cy;
		getXY(x, y, cx, cy);

		double xmax = (double)width / (double)min + margin;
		double ymax = (double)height / (double)min + margin;

		double xymin = xmax > ymax ? ymax : xmax;

		float rx = (2.0 / (double)columnsGrila * (x + raza) - 1) / xmax;
		float ry = (2.0 / (double)linesGrila * y - 1) / ymax;


		double r = rx - cx;

		int num_segments = 1000;
		glBegin(GL_LINE_LOOP);
		for (int ii = 0; ii < num_segments; ii++)
		{
			float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

			float x = r * cosf(theta);//calculate the x component
			float y = r * sinf(theta);//calculate the y component

			glVertex2f((double)x + cx, ((double)y + cy));//output vertex

		}
		glEnd();
		glLineWidth(1.f);

		std::vector<Punct> list = deseneazaCercAlgoritm(x, y, raza, dots);

		for (std::vector<Punct>::iterator it = list.begin(); it != list.end(); ++it) {
			writePixel(it->getX(), it->getY());
		}

	}

	std::vector<Punct> deseneazaCercAlgoritm(int xBegin, int yBegin, double raza, int dots)
	{
		std::vector<Punct> puncte;
		int x = raza;
		int y = 0;
		int d = 1 - raza;
		int dN = 3;
		int dNW = -2 * raza + 5;

		puncte.push_back(Punct(x, y));
		for (int i = 1; i <= dots / 2; i++)
		{
			puncte.push_back(Punct(x - i, y));
			puncte.push_back(Punct(x + i, y));
		}
		
		while (x > y)
		{
			if (d > 0)
			{
				// NW
				d += dNW;
				dN += 2;
				dNW += 4;
				x--;
			}
			else
			{
				// N
				d += dN;
				dN += 2;
				dNW += 2;
			}
			y++;

			puncte.push_back(Punct(x, y));
			for (int i = 1; i <= dots / 2; i++)
			{
				puncte.push_back(Punct(x - i, y));
				puncte.push_back(Punct(x + i, y));
			}
		}

		return puncte;
	}

	void deseneazaElipsa(int x, int y, int a, int b, int dots)
	{
		glColor3f(1.0, 0.1, 0.1); // rosu
		glLineWidth(4.f);

		double min;
		if (width > height)
			min = height;
		else min = width;

		float cx, cy;
		getXY(x, y, cx, cy);

		double xmax = (double)width / (double)min + margin;
		double ymax = (double)height / (double)min + margin;

		double xymin;
		if (xmax > ymax)
			xymin = ymax;
		else xymin = xmax;

		float rx = (2.0 / (double)columnsGrila * (x + a) - 1) / xmax;
		float ry = (2.0 / (double)linesGrila * (y + b) - 1) / ymax;

		double ra = rx - cx;
		double rb = ry - cy;
		int num_segments = 1000;

		glBegin(GL_LINE_LOOP);
		for (int ii = 0; ii < num_segments; ii++)
		{
			float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

			float x = ra * cosf(theta);//calculate the x component
			float y = rb * sinf(theta);//calculate the y component

			glVertex2f((double)x + cx, ((double)y + cy));//output vertex

		}
		glEnd();
		glLineWidth(1.f);

		std::vector<Punct> list = deseneazaElipsaAlgoritm(x, y, a, b, dots);

		for (std::vector<Punct>::iterator it = list.begin(); it != list.end(); ++it) {
			writePixel(it->getX(), it->getY());
		}
	}

	std::vector<Punct> deseneazaElipsaAlgoritm(int xBegin, int yBegin, double a, double b, int dots)
	{
		std::vector<Punct> puncte;

		int x = -a;
		int y = 0;

		double d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1)*(y - 1)- a * a * b * b;
		double d1;

		puncte.push_back(Punct(x + xBegin, y + yBegin));
		for (int i = x; i < 0; i++)
			puncte.push_back(Punct(x + xBegin - i, y + yBegin));

		while (a * a * (y - 0.5) > b* b* (x + 1))
		{
			if (d2 >= 0)
			{
				// selectam SE
				d2 += b * b * (2 * x + 3) + a * a * (-2 * y + 2);
				x++;
				y--;
			}
			else
			{
				// selectam S
				d2 += a * a * (-2 * y + 3);
				y--;
			}

			for (int i = x; i < 0; i++)
				puncte.push_back(Punct(x + xBegin - i, y + yBegin));
		}

		d1 = b * b * (x + 1) * (x + 1) + a * a * (y - 0.5) * (y - 0.5) - a * a * b * b;
		while (y > -b)
		{
			if (d1 >= 0)
			{
				// selectam E
				d1 += b * b * (2 * x + 3);
				x++;
			}
			else
			{
				// selectam SE
				d1 += b * b * (2 * x + 3) + a * a * (-2 * y + 2);
				x++;
				y--;
			}

			for (int i = x; i < 0; i++)
				puncte.push_back(Punct(x + xBegin - i, y + yBegin));
		}
		return puncte;
	}

	std::vector<Punct> writeLineAlgoritm(int xBegin, int yBegin, int xEnd, int yEnd, int dots)
	{
		double m = ((double)yEnd - (double)yBegin) / ((double)xEnd - (double)xBegin);
		if (m > 0)
		{
			if (abs(yEnd - yBegin) < abs(xEnd - xBegin))
			{
				if (xBegin > xEnd)
					return writeLineXPositive(xEnd, yEnd, xBegin, yBegin, dots);
				else
					return writeLineXPositive(xBegin, yBegin, xEnd, yEnd, dots);
			}
			else
			{
				if (yBegin > yEnd)
					return writeLineYPositive(xEnd, yEnd, xBegin, yBegin, dots);
				else
					return writeLineYPositive(xBegin, yBegin, xEnd, yEnd, dots);
			}
		}
		else
		{
			if (abs(yEnd - yBegin) < abs(xEnd - xBegin))
			{
				if (xBegin > xEnd)
					return writeLineXNegative(xEnd, yEnd, xBegin, yBegin, dots);
				else
					return writeLineXNegative(xBegin, yBegin, xEnd, yEnd, dots);
			}
			else
			{
				if (yBegin > yEnd)
					return writeLineYNegative(xBegin, yBegin, xEnd, yEnd, dots);
				else
					return writeLineYNegative(xEnd, yEnd, xBegin, yBegin, dots);
			}
			std::vector<Punct> puncte;
			return puncte;
		}
	}

	std::vector<Punct> writeLineXPositive(int xBegin, int yBegin, int xEnd, int yEnd, int dots)
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
				/* alegem E */
				d += dE;
				x++;
			}
			else
			{
				/* alegem NE */
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

	std::vector<Punct> writeLineYPositive(int xBegin, int yBegin, int xEnd, int yEnd, int dots)
	{
		std::vector<Punct> puncte;

		int dy = yEnd - yBegin;
		int dx = xEnd - xBegin;

		int d = dy - 2 * dx;
		int dE = -2 * dx;
		int dNE = 2 * (dy - dx);
		int x = xBegin, y = yBegin;

		puncte.push_back(Punct(x, y));
		for (int i = 1; i <= dots / 2; i++)
		{
			puncte.push_back(Punct(x - i, y));
			puncte.push_back(Punct(x + i, y));
		}
		while (y < yEnd)
		{
			if (d > 0)
			{
				/* alegem S */
				d += dE;
				y++;
			}
			else
			{
				/* alegem SE */
				d += dNE;
				x++;
				y++;
			}

			puncte.push_back(Punct(x, y));
			for (int i = 1; i <= dots / 2; i++)
			{
				puncte.push_back(Punct(x - i, y));
				puncte.push_back(Punct(x + i, y));

			}
		}
		return puncte;
	}

	std::vector<Punct> writeLineXNegative(int xBegin, int yBegin, int xEnd, int yEnd, int dots)
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
				/* alegem E */
				d += dE;
				x++;
			}
			else
			{
				/* alegem SE */
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

	std::vector<Punct> writeLineYNegative(int xBegin, int yBegin, int xEnd, int yEnd, int dots)
	{
		std::vector<Punct> puncte;

		int dy = yEnd - yBegin;
		int dx = xEnd - xBegin;

		int d = dy + 2 * dx;
		int dS = 2 * dx;
		int dSE = 2 * (dy + dx);
		int x = xBegin, y = yBegin;

		puncte.push_back(Punct(x, y));
		for (int i = 1; i <= dots / 2; i++)
		{
			puncte.push_back(Punct(x - i, y));
			puncte.push_back(Punct(x + i, y));
		}

		while (y > yEnd)
		{
			if (d < 0)
			{
				/* alegem S */
				d += dS;
				y--;
			}
			else
			{
				/* alegem SE */
				d += dSE;
				x++;
				y--;
			}

			puncte.push_back(Punct(x, y));
			for (int i = 1; i <= dots / 2; i++)
			{
				puncte.push_back(Punct(x - i, y));
				puncte.push_back(Punct(x + i, y));

			}
		}
		return puncte;
	}

	void deseneazaPoligon(const char* fisier)
	{
		FILE* file;
		file = fopen(fisier, "r");

		Poligon poligon;
		int n;
		int x1, x2;

		if (file)
		{
			fscanf(file, "%d", &n);
			fscanf(file, "%d %d", &x1, &x2);
			Punct punct1(x1, x2);
			Punct initial(x1, x2);

			for (int i = 1; i < n; i++)
			{
				fscanf(file, "%d %d", &x1, &x2);

				Punct punct2(x1, x2);
				poligon.muchii.push_back(Muchie(punct1, punct2));
				punct1.setX(x1);
				punct1.setY(x2);
			}
			poligon.muchii.push_back(Muchie(punct1, initial));
		}

		float cx, cy;

		glColor3f(1.0, 0.1, 0.1); // rosu
		glLineWidth(4.f);

		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < poligon.muchii.size(); i++)
		{
			getXY(poligon.muchii.at(i).vi.getX(), poligon.muchii.at(i).vi.getY(), cx, cy);
			glVertex2f(cx, cy);
		}
		glEnd();
		glLineWidth(1.f);

		map <int, vector<Intersectie>> et, ssms;
		initializareEt(poligon, et);
		calculssm(poligon, et, ssms);
		coloreaza(ssms);
	}

	void initializareEt(Poligon poligon, map <int, vector<Intersectie>>& et)
	{
		int xm, ym, xM, yM;
		bool change;

		for (int i = 0; i < 20; i++)
		{
			vector<Intersectie> v;
			et.insert(pair<int, vector<Intersectie>>(i, v));
		}

		for (Muchie m : poligon.muchii)
		{
			if (m.vi.getY() != m.vf.getY())
			{
				ym = min(m.vi.getY(), m.vf.getY());
				yM = max(m.vi.getY(), m.vf.getY());
				xm = (ym == m.vi.getY()) ? m.vi.getX() : m.vf.getX();
				xM = (yM == m.vi.getY()) ? m.vi.getX() : m.vf.getX();
				et.find(ym)->second.push_back(Intersectie(yM, xm, (double)(xm - xM) / (ym - yM)));
			}
		}

		for (int i = 0; i < 20; i++)
		{
			vector<Intersectie> curent = et.find(i)->second;
			sort(curent.begin(), curent.end());
		}
	}

	void calculssm(Poligon poligon, map <int, vector<Intersectie>>& et, map <int, vector<Intersectie>>& finalET)
	{
		vector<Intersectie> activeSSM;

		int y, k;

		for (int i = 0; i < 20; i++)
		{
			vector<Intersectie> v;
			finalET.insert(pair<int, vector<Intersectie>>(i, v));
		}

		y = -1;
		for (int i = 0; i < 20; i++)
		{
			if (!et.find(i)->second.empty())
			{
				y = i;
				break;
			}
		}

		if (y < 0 || y>20)
			return;
		
		do
		{
			activeSSM.insert(activeSSM.end(), et.find(y)->second.begin(), et.find(y)->second.end());

			int ii = 0;
			while (ii < activeSSM.size())
			{
				if (activeSSM.at(ii).ymax == y)
					activeSSM.erase(activeSSM.begin() + ii);
				else ii++;
			}

			k = activeSSM.size();
			sort(activeSSM.begin(), activeSSM.end());

			for (auto it = activeSSM.begin(); it != activeSSM.end(); it++)
			{
				Intersectie deepCopy = Intersectie(*it);
				finalET.find(y)->second.push_back(deepCopy);
			}
			y++;

			for (int i = 0; i < activeSSM.size(); i++)
			{
				if (activeSSM.at(i).ratia != 0)
					activeSSM.at(i).xmin += activeSSM.at(i).ratia;
			}
		} while ((!activeSSM.empty() || !et.find(y)->second.empty()) && y < 20);
	}

	void coloreaza(map <int, vector<Intersectie>> ssms)
	{
		for (auto it = ssms.begin(); it != ssms.end(); it++)
		{
			// parcurgem lista de intersectii pentru fiecare dreapta de scanare
			bool paritate = false;

			int y = it->first; // dreapta de scanare y = y
			vector<Intersectie> intersectii = it->second;
			if (intersectii.size() == 0)
				// daca nu intersecteaza in niciun punct continuam
				continue;

			vector<Intersectie>::iterator curent = intersectii.begin();
			// calculam extremitatile, cea din stanga o sa fie interioara, cea din dreapta nu
			int extremitate_stanga = intersectii.begin()->xmin;
			int extremitate_dreapta = next(intersectii.end(), -1)->xmin;
			
			for (int i = 0; i < 20 && curent != intersectii.end(); i++)
			{
				// parcurgem domeniul

				// puncte de intersectie (Q/Z)xZ
				if ((int)curent->xmin != curent->xmin)
				{
					if (paritate && (int)floor(curent->xmin) == i - 1)
					{
						// intrare in poligon
						paritate = !paritate;
						curent = next(curent, 1);
					}
					else if (!paritate && (int)ceil((curent->xmin)) == i)
					{
						// iesire in poligon
						paritate = !paritate;
						curent = next(curent, 1);
					}
				}
				else
				{
					if (next(curent) != intersectii.end() && curent->xmin == next(curent)->xmin && (y != next(curent)->ymax || y != curent->ymax) && i == curent->xmin)
					{
						// punctul este varf al poligonului si nu este macar pentru o dreapta ymax
						paritate = 1;
						curent = next(curent, 2);
					}
					// extremitati
					else if (i == extremitate_stanga || i == extremitate_dreapta)
					{
						paritate = !paritate;
						curent = next(curent, 1);
					}

				}

				bool ok = false;
				while (curent != intersectii.end() && i > curent->xmin)
				{
					// daca punctul este inaintea urmatoarei intersectii
					curent = next(curent);
					ok = true;
				}

				if (ok && curent == intersectii.end())
					break;

				if (paritate)
					writePixel(i, y);
			}
		}
	}

private:
	int linesGrila;
	int columnsGrila;

	void getXY(int line, int column, float& outX, float& outY) 
	{
		double min = width > height ? height : width;

		double xmax = (double)width / (double)min + margin;
		double ymax = (double)height / (double)min + margin;

		outX = (2.0 / (double)this->columnsGrila * (double)line - 1) / xmax;
		outY = (2.0 / (double)this->linesGrila * (double)column - 1) / ymax;
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

	GrilaCarteziana grilaCarteziana1(15, 15);
	GrilaCarteziana grilaCarteziana2(26, 26);
	GrilaCarteziana grilaCarteziana3(14, 14);

	switch (prevKey)
	{
	case '1':
		grilaCarteziana1.display();
		grilaCarteziana1.deseneazaCerc(0, 0, 13, 3);
		break;
	case '2':
		grilaCarteziana2.display();
		grilaCarteziana2.deseneazaElipsa(13, 7, 13, 7, 1);
		break;
	case '3':
		grilaCarteziana3.display();
		grilaCarteziana3.deseneazaPoligon("poligon.txt");
		break;
	default:
		break;
	}

	glFlush();
	glFlush();
}

void Reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	width = w;
	height = h;

	glutDisplayFunc(Display);
}

void KeyboardFunc(unsigned char key, int x, int y)
{
	prevKey = key;
	if (key == 27) // escape
		exit(0);
	glutPostRedisplay();
}

void MouseFunc(int button, int state, int x, int y) {}

int main(int argc, char** argv) {

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