#include <iostream>
#include <cmath>

#define MATRIX_HEIGHT 6
#define MATRIX_WIDTH 5

using namespace std;

int Matrix[MATRIX_HEIGHT][MATRIX_WIDTH];

void Circle (int* ptr, int cx, int cy, int ray)
{
	for (int i=0; i<MATRIX_HEIGHT; i++)
	{
		for (int j=0; j<MATRIX_WIDTH; j++)
		{
			if (ceil(sqrt((cx-i)*(cx-i) + (cy-j)*(cy-j))) == ray) *(ptr + i*MATRIX_WIDTH + j) = 1;
		}
	}
}

int main()
{
	Circle(&Matrix[0][0], 2, 2, 2);
	for (int i=0; i<MATRIX_HEIGHT; i++)
	{
		for (int j=0; j<MATRIX_WIDTH; j++)
		{
			cout << Matrix[i][j] << " ";
		}
		cout << "\n";
	}
}
