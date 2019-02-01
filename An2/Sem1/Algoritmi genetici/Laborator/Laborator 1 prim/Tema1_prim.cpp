#include <bits/stdc++.h>

#define dimensions 32
#define length 5
#define runs 10
#define sizes (length*dimensions)
#define A 0
#define B 31

using namespace std;

int functie (int* res)
{
    int result = 0;
    for (int i = 0; i < dimensions; i++)
        result = result + res[i]*res[i]*res[i] - 60*res[i]*res[i] + 900*res[i] + 100;
    return result;
}

int f(bool* a)
{
	int res[sizes];
	for (int i = 0; i < dimensions; i++)
	{
		res[i] = 0;
		int p = 1;
		for (int j = 0; j < length; j++)
		{
			res[i] = res[i] + p*a[i*length+j];
			p = p*2;
		}
		res[i] = res[i]* (B - A);
		res[i] = res[i]/ (p - 1);
		res[i] = res[i]+ A;
	}

    return functie (res);
}

void first_improvement (bool* v_c, bool* v_n)
{
	memcpy(v_n, v_c, sizes);
	int t = 0;
	bool found = 0;
	while (!found && ++t <= sizes)
	{
		int ind = rand() % sizes;
		v_c[ind] = 1 - v_c[ind];
		if (f (v_c) > f (v_n))
		{
			memcpy(v_n, v_c, sizes);
			found = 1;
		}
		v_c[ind] = 1 - v_c[ind];
	}
}

void best_improvement (bool* v_c, bool* v_n)
{
	memcpy(v_n, v_c, sizes);
	for (int i = 0; i<dimensions; i++)
	{
		for (int j = 0; j<length; j++)
		{
			v_c[i*length+j] = 1 - v_c[i*length+j];
			if (f (v_c) > f (v_n))
			{
				memcpy(v_n, v_c, sizes);
			}
			v_c[i*length+j] = 1 - v_c[i*length+j];
		}
	}
}

int get_random()
{
    return A + rand() / (RAND_MAX / (B - A));
}

void HillClimbing()
{
	bool vc[sizes], vn[sizes], best[sizes];
	int t = 0;

	while (++t <= runs)
	{
	    cout << "Rularea " << t << ":" << '\n' << '\n';
		bool local = false;

		//randomizing
        for (int i = 0; i < sizes; i++)
            vc[i] = get_random() % 2;

		cout << "VC: " << f(vc) << " ";
		cout << '\n' << '\n';
		//f(vc);
		while (local == false)
		{
            cout << "Local still " << local << ":" << '\n';
			//best_improvement (vc, vn);
			first_improvement (vc, vn);
			cout << "VN: " << f(vn) << " " << '\n';
			//f(vn);
			if (f(vn) > f(vc)) memcpy(vc, vn, sizes);
			else local = true;
		}
		if (f(vc) > f(best)) memcpy(best, vc, sizes);
		cout << '\n' << "Best: " << f(best) << '\n' << '\n' << '\n';
	}
	cout << "Best final: " << f(best) << '\n' << '\n';

	int res[sizes];
	for (int i = 0; i < dimensions; ++i)
	{
		res[i] = 0;
		int p = 1;
		for (j = 0; j < length; j++)
		{
			res[i] = res[i] + p*best[i*length+j];
			p = p*2;
		}
		res[i] = res[i]* (B - A);
		res[i] = res[i]/ (p - 1);
		res[i] = res[i]+ A;
	}
	for (int i = 0; i < dimensions; i++)
        cout << "x" << i+1 << " = " << res[i] << '\n';
}

int main ()
{
    srand (time (0));
    cout << fixed;

    HillClimbing();

    return 0;
}
