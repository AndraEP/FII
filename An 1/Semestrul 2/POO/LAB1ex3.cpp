#include <iostream>
#include <cstring>

#define RESULT_MAX_SIZE 10

using namespace std;

char* strrevLINUX (char* s)
{
	int n = strlen(s);
	for (int i=0; i<n/2; i++)
	{
		swap (s[i], s[n-i-1]);
	}
	return s;
}

bool Convert (unsigned int number, unsigned int toBase, char* result, unsigned int resultMaxSize)
{
	char s[RESULT_MAX_SIZE];
	if (toBase<2 || toBase>16) return 0;
	int k = -1;
	while (number)
	{
		++k;
		if (k+1>resultMaxSize) return 0;
		s[k] = number % toBase;
		number /= toBase;
		if (s[k]>9) s[k] = s[k]-10+'A';
		else s[k] = s[k]+'0';
	}
	s[k+1]=0;
	if (strlen(s) == 0) return 0;
	strrevLINUX(s);
	strcpy(result, s);
	return 1;
}

int main ()
{
	char rez[RESULT_MAX_SIZE];
	cout << Convert (255, 16, rez, RESULT_MAX_SIZE);
	cout << "\n" << rez;
}
