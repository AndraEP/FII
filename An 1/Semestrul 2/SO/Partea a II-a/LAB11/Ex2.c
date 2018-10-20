#include <stdio.h>

int p1[2], p2[2];

int main()
{
    pipe (p1); pipe (p2);
    FILE* fin1 = fdopen (p1[0], "r");
    FILE* fout1 = fdopen (p1[1], "w");
    FILE* fin2 = fdopen (p2[0], "r");
    FILE* fout2 = fdopen (p2[1], "w");
    FILE* fout = fopen ("persoane.txt", "w");
    if (fork() == 0)
    {
        //P1
        fclose (fout1);
        fclose (fin2);
        int flag;
        char s[256];
        FILE* fin = fopen ("nume.txt", "r");
        while (fscanf (fin, "%s", &s) != EOF)
        {
            fscanf (fin1, "%d", &flag);
            fprintf (fout, "%s ", s);
            fflush (fout);
            fprintf (fout2, "1 ");
            fflush (fout2);
        }
        fclose (fin1);
        fclose (fout2);
    }
    else if (fork() == 0)
    {
        //P2
        fclose (fin1);
        fclose (fout2);
        int flag;
        char s[256];
        FILE *fin = fopen ("prenume.txt", "r");
        while (fscanf (fin, "%s", &s) != EOF)
        {
            fscanf (fin2, "%d", &flag);
            fprintf (fout, "%s\n", s);
            fflush (fout);
            fprintf (fout1, "1 ");
            fflush (fout1);
        }
        fclose (fout1);
        fclose (fin2);
    }
    else
    {
        fclose (fin1);
        fclose (fin2); fclose (fout2);
        fprintf (fout1, "1 ");
        fclose (fout1);
    }
    return 0;
}
