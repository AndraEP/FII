#include <bits/stdc++.h>

#define MAX_ARRAY 10
#define dimensions 3
#define length 8
#define runs 10
#define sizes (dimensions * length)

using namespace std;

float A, B;

float dejong (float* res)
{
    float result = 0;
	for (int i = 0; i < dimensions; i++)
	{
		result = result + res[i] * res[i];
	}
	return result;
}

float schwefel (float* res)
{
    float result = 0;
	for (int i = 0; i < dimensions; i++)
	{
		result = result - res[i] * sin(sqrt(abs(res[i])));
	}
	return result;
}

float rastrigin (float* res)
{
    float result = 10*dimensions;
	for (int i = 0; i < dimensions; i++)
	{
		result = result + res[i]*res[i] - 10*cos(2*3.1415*res[i]);
	}
	return result;
}

float sixhumpcamelback (float* res)
{
    float result = (4-2.1 * res[0]*res[0] + res[0]*res[0]*res[0]*res[0]/3)*res[0]*res[0] + res[0]*res[1] + (-4 + 4*res[1]*res[1])*res[1]*res[1];
	return result;
}

float f(bool* a, int number)
{
	float res[sizes];
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
		res[i] = res[i] + A;
	}

    if (number == 1)
        return dejong(res);
    if (number == 2)
        return schwefel(res);
    if (number == 3)
        return rastrigin(res);
    if (number == 4)
        return sixhumpcamelback(res);
}

void first_improvement(bool* s, bool* s_prim, int number)
{
	memcpy (s_prim, s, sizes);
	int t = 0;
	bool found = 0;
	while (!found && ++t <= sizes)
	{
		int ind = rand() % sizes;
		s[ind] = 1-s[ind];
		if (f (s, number) < f (s_prim, number))
		{
			memcpy(s_prim, s, sizes);
			found = 1;
		}
		s[ind] = 1-s[ind];
	}
}

void best_improvement (bool* s, bool* s_prim, int number)
{
	memcpy(s_prim, s, sizes);
	for (int i = 0; i < dimensions; i++)
	{
		for (int j = 0; j < length; j++)
		{
			s[i*length+j] = 1-s[i*length+j];
			if (f (s, number) < f (s_prim, number))
			{
				memcpy (s_prim, s, sizes);
			}
			s[i*length+j] = 1-s[i*length+j];
		}
	}
}

void HillClimbing (int number)
{
	bool vc[sizes], vn[sizes], best[sizes];
	int t = 0;
	while (++t <= runs)
	{
		bool local = false;

		//randomizing
		for (i = 0; i < sizes; i++)
            	vc[i] = rand() % 2;
        	cout << "First cout: " << f (vc, number) << ", ";
        	cout << '\n';
        	int k = 0;
        	while (local == false)
		{
			first_improvement (vc, vn, number);
			//best_improvement (vc, vn, number);
			if (f (vn, number) < f (vc, number))
            		{
               			memcpy(vc, vn, sizes);
                		k++;
                		cout << "i" << k << '\n';
            		}
			else
                		local = true;
		}
		if (f (vc, number) < f (best, number))
            	memcpy(best, vc, sizes);
	}
	float res[sizes];
	for (int i = 0; i < dimensions; ++i)
	{
		res[i] = 0;
		int p = 1;
		for (int j = 0; j < length; j++)
		{
			res[i] = res[i] + p*best[i*length+j];
			p = p*2;
		}
		res[i] = res[i]* (B - A);
		res[i] = res[i]/ (p - 1);
		res[i] = res[i] + A;
	}
	for (int i = 0; i < dimensions; i++)
        cout << "x" << i+1 << " == " << res[i] << '\n';
}

void neighbour (bool* a, bool* b)
{
	memcpy(b, a, sizes);
	int ind = rand() % sizes;
	b[ind] = 1 - b[ind];
}

void SimulatedAnnealing (int number)
{
	bool vc[sizes], vn[sizes], best[sizes];
    	int t = 0;
	float T = 1;

    	for (int i = 0; i < sizes; i++)
        	vc[i] = rand() % 2;

	f (vc, number);
	while ((T = T * 0.9) >= 0.01)
	{
		while (++t <= sizes)
		{
			neighbour (vc, vn);
			if (f (vn, number) < f (vc, number))
                		memcpy(vn, vc, sizes);
            		else
			if ((1.0 * rand() / (RAND_MAX + 1)) < exp((-1.0*abs(f(vn, number) - f(vn, number))) / T))
                		memcpy (vc, vn, sizes);
		}
		f (best, number);
	}
	float res[sizes];
	for (int i = 0; i < dimensions; ++i)
	{
		res[i] = 0;
		unsigned int p = 1;
		for (int j = 0; j < length; j++)
		{
			res[i] = res[i] + p*best[i*length+j];
			p = p*2;
		}
		res[i] = res[i]* (B - A);
		res[i] = res[i]/ (p - 1);
		res[i] = res[i] + A;
	}
	for (int i = 0; i < dimensions; i++)
        cout << "x" << i+1 << " == " << res[i] << '\n';
}

int main ()
{
    srand (time (0));
    cout << fixed;

    char message [MAX_ARRAY];
    int number = 0, ok = 0;

    while (ok == 0)
    {
        cin.getline (message, MAX_ARRAY, '\n');

        if (strcmp (message, "dejong") == 0)
        {
            A = -5.12;
            B = 5.12;
            number = 1;
            HillClimbing (number);
            //SimulatedAnnealing (number);
            ok = 1;
        }
        else
        if (strcmp (message, "schwefel") == 0)
        {
            A = -500;
            B = 500;
            number = 2;
            //HillClimbing (number);
            SimulatedAnnealing (number);
            ok = 1;
        }
        else
        if (strcmp (message, "rastrigin") == 0)
        {
            A = -5.12;
            B = 5.12;
            number = 3;
            //HillClimbing (number);
            SimulatedAnnealing (number);
            ok = 1;
        }
        else
        if (strcmp (message, "sixhump") == 0)
        {
            A = -2;
            B = 2;
            number = 4;
            //HillClimbing (number);
            SimulatedAnnealing (number);
            ok = 1
        }
        else
        {
            cout << "You typed in the wrong function name. Try again!" << '\n';
            number = 0;
        }
    }
    return 0;
}
