#include <bits/stdc++.h>

#define length 17
#define pop_size 100
#define sizes (length)
#define cross_probab 0.3
#define mutation_probab 0.01

using namespace std;

ifstream fin ("tsp.in");
ofstream fout ("tsp.out");

int pop[pop_size][sizes], newpop[pop_size][sizes], graf[length][length];
float popfit[pop_size], selection_probab[pop_size + 1];

int TSP (int* r)
{
    int cost = 0;
    for (int i = 0; i < length - 1; i++)
    {
        cost = cost + graf[r[i]][r[i + 1]];
    }
    cost = cost + graf[r[length - 1]][r[0]];
    return cost;
}

void decodare (int* a, int* res)
{
    int visited[length] = {0};
    for (int i = 0; i < length; i++)
    {
        int position = 0;
        for (int j = 0; j < length; j++)
        {
            if (visited[j] == 0)
            {
                ++position;
                if (position == a[i])
                {
                    res[i] = j;
                    visited[j] = 1;
                    break;
                }
            }
        }
    }
}

int eval_pop ()
{
    int res_eval[sizes], minim = 99999999;
    for (int i = 0; i < pop_size; ++i)
    {
        decodare (pop[i], res_eval);
        if (TSP(res_eval) < minim)
            minim = TSP(res_eval);
    }
    return minim;
}

void eval_popfitness ()
{
    int res_fit[sizes];
    for (int i = 0; i < pop_size; i++)
    {
        decodare (pop[i], res_fit); //no duplicates in res_fit
        popfit[i] = 1.0 / TSP(res_fit);
    }
}

void cross_over (int i1, int i2)
{
    int ind = rand() % sizes, a;
    for (int i = ind; i < sizes; ++i)
    {
        a = pop[i1][i];
        pop[i1][i] = pop[i2][i];
        pop[i2][i] = a;
    }
}

void recomb ()
{
    int x = 0;
    int i1, i2;
    //crossover
    for (int i = 0; i < pop_size; i++)
    {
        if ((1.0*rand () / RAND_MAX) < cross_probab)
        {
            if (x == 0)
            {
                x = 1 - x;
                i1 = i;
            }
            if (x == 1)
            {
                x = 1 - x;
                i2 = i;
                cross_over (i1, i2);
            }
        }
    }
    //mutation
    for (int i = 0; i < pop_size; i++)
    {
        for (int j = 0; j < sizes; j++)
        {
            if ((1.0*rand() / RAND_MAX) < mutation_probab)
            {
                pop[i][j] = rand() % (length - j) + 1;
            }
        }
    }
}

void GA ()
{
    int best = 99999999;
    int runs = 0;
    while (++runs <= 10) //number of runs
    {
        //randomize(generate) population
        for (int i = 0; i < pop_size; ++i)
        {
            for (int j = 0; j < sizes; ++j)
            {
                pop[i][j] = rand() % (length - j) + 1;
            }
        }

        //evaluate and choose best
        if (eval_pop() < best)
            best = eval_pop();
        //fout << eval_pop() << " ";

        int t = 0;
        while (++t <= 1000) //number of generations, start iteration, stop condition
        {
            //start selection, calculate
            float fit_total = 0;
            eval_popfitness (); //evaluate population
            selection_probab[0] = 0;

            for (int i = 0; i < pop_size; ++i) //fitness total
                fit_total = fit_total + popfit[i];
            for (int i = 0; i < pop_size; ++i) //population fitness probability
                popfit[i] = popfit[i] / fit_total;
            for (int i = 0; i < pop_size; ++i) //selection probability
                selection_probab[i + 1] = selection_probab[i] + popfit[i];

            //doing actual selection
            for (int i = 0; i < pop_size; ++i)
            {
                float r = 1.0 * rand() / RAND_MAX; //r between (0, 1]
                //going to survive
                for (int j = 0; j < pop_size; j++)
                {
                    if (selection_probab[j] < r && r <= selection_probab[j + 1]) //condition
                    {
                        for (int k = 0; k < sizes; k++)
                        {
                            newpop[i][k] = pop[j][k];
                        }
                    }
                }
            }
            //actualizing population
            for (int i = 0; i < pop_size; i++)
            {
                for (int j = 0; j < sizes; j++)
                {
                    pop[i][j] = newpop[i][j];
                }
            }
            recomb ();
            if (eval_pop() < best)
                best = eval_pop();
            //fout << eval_pop() << " ";
        }
        //fout << " ";
    }
    fout << best;
}

int main()
{
    srand (time (0));
    cout << fixed;

    char message [256];
    int ok = 0;

    while (ok == 0)
    {
        cin.getline(message, 256, '\n');

        if (strcmp (message, "tsp") == 0)
        {
            ok = 1;
            for (int i = 0; i < length; ++i)
            {
                for (int j = 0; j < length; ++j)
                {
                    fin >> graf[i][j];
                }
            }
            GA ();
        }
        else
        {
            cout << "You typed in the wrong function name. Try again!" << '\n';
        }
    }
    return 0;
}
