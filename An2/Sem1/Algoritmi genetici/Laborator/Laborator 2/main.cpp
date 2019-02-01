#include <bits/stdc++.h>

#define MAX_ARRAY 25
#define dimensions 30
#define length 8
#define runs 15
#define sizes (dimensions * length)
#define population_size 10

#define cross_probab 0.3
#define mutation_probab 0.01

using namespace std;

float A, B;
bool population[population_size][sizes], new_pop[population_size][sizes];
float population_fitness[population_size], selection_probab[population_size + 1];

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

void f (bool* a, float* res)
{
    //reprezentare binara pt probleme de optimizare numerica
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
        res[i] = res[i]/ p;
        res[i] = res[i] + A;
    }
}

void eval_popfitness (int number)
{
    float res_fit[sizes];

    //se calculeaza prin inversarea functiei, functii pozitive ce necesita minimizare
    if (number == 1)
    {
        for (int i = 0; i < population_size; i++)
        {
            f (population[i], res_fit);
            population_fitness[i] = 1 / dejong (res_fit);
        }
    }
    if (number == 2)
    {
        for (int i = 0; i < population_size; i++)
        {
            f (population[i], res_fit);
            population_fitness[i] = 1 / schwefel (res_fit);
        }
    }

    if (number == 3)
    {
        for (int i = 0; i < population_size; i++)
        {
            f (population[i], res_fit);
            population_fitness[i] = 1 / rastrigin (res_fit);
        }
    }

    if (number == 4)
    {
        for (int i = 0; i < population_size; i++)
        {
            f (population[i], res_fit);
            population_fitness[i] = 1 / sixhumpcamelback (res_fit);
        }
    }
}

float eval_pop (int number)
{
    float res_eval[sizes], minim = 99999999;
    for (int i = 0; i < population_size; i++)
    {
        f (population[i], res_eval);
        if (number == 1)
            if (dejong (res_eval) < minim)
                minim = dejong (res_eval);
        if (number == 2)
            if (schwefel (res_eval) < minim)
                minim = schwefel (res_eval);
        if (number == 3)
            if (rastrigin (res_eval) < minim)
                minim = rastrigin (res_eval);
        if (number == 4)
            if (sixhumpcamelback (res_eval) < minim)
                minim = sixhumpcamelback (res_eval);
    }
    return minim;
}

void cross_over (int i1, int i2)
{
    //incrucisarea cu punct de taiere aleator
    int ind = rand () % sizes;
    for (int i = ind; i < sizes; i++)
    {
        std::swap (population[i1][i], population[i2][i]);
    }
}

void recombine ()
{
    //mutation and/or cross_over
    bool x = 0;
    int i1, i2;
    for (int i = 0; i < population_size; i++)
    {
        if ((1.0 * rand () / RAND_MAX) < cross_probab)
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
    for (int i = 0; i < population_size; i++)
    {
        for (int j = 0; j < sizes; j++)
        {
            if ((1.0 * rand () / RAND_MAX) < mutation_probab)
            {
                population[i][j] = 1 - population[i][j];
            }
        }
    }
}

void GeneticAlgorithm (int number)
{
    float Vector [100];
    float best = 99999999;
    int rulari = 0;
    int k = 0;
    while (++rulari <= runs)
    {
        //randomizing(generating) vector numbers
        for (int i = 0; i < population_size; i++)
        {
            for (int j = 0; j < sizes; ++j)
            {
                population[i][j] = rand () % 2;
            }
        }

        //choose(evaluating) best
        if (eval_pop (number) < best)
            best = eval_pop (number);

        //stop condition, iteration
        int t = 0;
        while (++t <= 100) //generation number
        {
            //starting selection
            float total = 0; //initializing total fitness
            eval_popfitness (number); //evaluating population
            selection_probab[0] = 0; //initializing selection probability

            //total fitness
            for (int i = 0; i < population_size; i++)
                total = total + population_fitness[i];
            //population fitness probability
            for (int i = 0; i < population_size; i++)
                population_fitness[i] = population_fitness[i] / total;
            //selection probability
            for (int i = 0; i < population_size; i++)
                selection_probab[i + 1] = selection_probab[i] + population_fitness[i];
            //doing selection
            for (int i = 0; i < population_size; i++)
            {
                float r = 1.0 * rand () / RAND_MAX; //generating r between (0,1]
                //going to survive
                for (int j = 0; j < population_size; j++)
                {
                    if (selection_probab[j] < r && r <= selection_probab[j + 1]) //condition
                    {
                        for (int k = 0; k < sizes; k++)
                        {
                            new_pop[i][k] = population[j][k];
                        }
                    }
                }
            }

            //actualizing population
            for (int i = 0; i < population_size; i++)
            {
                for (int j = 0; j < sizes; j++)
                {
                    population[i][j] = new_pop[i][j];
                }
            }

            //recombining
            recombine ();

            //actualizing(evaluating) best
            if (eval_pop (number) < best)
                best = eval_pop (number);
            cout << best << ", ";
        }
    }
    cout << '\n' << best;
}

int main ()
{
    srand (time (0));
    cout << fixed;

    char message [MAX_ARRAY];
    int number = 0, ok = 0;

    cout << "Type in one of the following name for a function:" << '\n' << "dejong" << '\n' << "schwefel" << '\n' << "rastrigin" << '\n' << "sixhump" << '\n';

    //choosing function
    while (ok == 0)
    {
        cin.getline (message, MAX_ARRAY, '\n');

        if (strcmp (message, "dejong") == 0)
        {
            A = -5.12;
            B = 5.12;
            number = 1;
            ok = 1;
            GeneticAlgorithm(number);
        }
        else if (strcmp (message, "schwefel") == 0)
        {
            A = -500;
            B = 500;
            number = 2;
            ok = 1;
            GeneticAlgorithm(number);
        }
        else if (strcmp (message, "rastrigin") == 0)
        {
            A = -5.12;
            B = 5.12;
            number = 3;
            ok = 1;
            GeneticAlgorithm(number);
        }
        else if (strcmp (message, "sixhump") == 0)
        {
            A = -2;
            B = 2;
            number = 4;
            ok = 1;
            GeneticAlgorithm(number);
        }
        else
        {
            cout << "You typed in the wrong function name. Try again!" << '\n';
            number = 0;
        }
    }
    return 0;
}
