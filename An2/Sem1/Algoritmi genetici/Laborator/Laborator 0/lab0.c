#include <bits/stdc++.h>

using namespace std;

double get_random(double limita_minima, double limita_maxima)
{
    return limita_minima + rand() / (RAND_MAX / (limita_maxima - limita_minima));
}

int main()
{
    cout << fixed;
    int rulari = 1000000, numar_var = 2, i, j;
    double limita_minima = -10, limita_maxima = 10, x[3], rezultat, min_functie = 1000000, max_functie = -1000000, xmin[3], xmax[3];

    for (i = 0; i < rulari; i++)
    {
        for (j = 1; j <= numar_var; j++)
            x[j] = get_random(limita_minima, limita_maxima);
        rezultat = (x[1] + 2 * x[2] - 7) * (x[1] + 2 * x[2] - 7) + (2 * x[1] + x[2] - 5) * (2 * x[1] + x[2] - 5);
        if (rezultat <= min_functie)
        {
            min_functie = rezultat;
            cout << "Minimul functiei este: " << min_functie <<'\n';
            for (j = 1; j <= numar_var; j++)
            {
                xmin[j] = x[j];
                cout<<"xmin "<<j<<" este "<<xmin[j]<<'\n';
            }
            cout << '\n';
        }
        if (rezultat >= max_functie)
        {
            max_functie = rezultat;
            cout << "Maximul functiei este: " << max_functie <<'\n';
            for (j = 1; j <= numar_var; j++)
            {
                xmax[j] = x[j];
                cout<<"xmax "<<j<<" este "<<xmax[j]<<'\n';
            }
            cout << '\n';
        }
    }

    cout << "Minimul functiei: " << min_functie << '\n';
    for (j = 1; j <= numar_var; j++)
        cout << "x" << j << " = " << xmin[j] << '\n';
    cout << '\n';

    cout << "Maximul functiei: " << max_functie << '\n';
    for (j = 1; j <= numar_var; j++)
        cout << "x" << j << " = " << xmax[j] << '\n';
    
    return 0;
}
