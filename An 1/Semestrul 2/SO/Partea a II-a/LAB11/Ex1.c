#include <stdio.h>
#include <fcntl.h>

int p1[2], p2[2], p3[2];

int main()
{
    pipe (p1); pipe (p2); pipe (p3);
    FILE* fin1 = fdopen (p1[0], "r");
    FILE* fout1 = fdopen (p1[1], "w");
    FILE* fin2 = fdopen (p2[0], "r");
    FILE* fout2 = fdopen (p2[1], "w");
    FILE* fin3 = fdopen (p3[0], "r");
    FILE* fout3 = fdopen (p3[1], "w");
    if (fork() == 0)
    {
        //primul fiu
        fclose (fout1);
        fclose (fin2);
        fclose (fin3); fclose (fout3);
        char c;
        while (fscanf (fin1, "%c", &c) != EOF)
        {
            if (c >= 'a' && c <= 'z')
            {
                fprintf (fout2, "%c", c);
                fflush (fout2);
            }
        }
        fclose (fin1);
        fclose (fout2);
    }
    else if (fork() == 0)
    {
        //al doilea fiu
        fclose (fin1); fclose (fout1);
        fclose (fout2);
        fclose (fin3);
        int i, count = 0, viz[30] = {0};
        char c;
        FILE* fout = fopen ("statistica.txt", "w");
        while (fscanf (fin2, "%c", &c) != EOF)
        {
            viz[c - 'a' + 1]++;
        }
        fclose (fin2);
        for (i = 1; i <= 26; ++i)
        {
            if (viz[i] > 0)
            {
                fprintf (fout, "%c %d\n", 'a' + i, viz[i]);
                fflush (fout);
                count++;
            }
        }
        fclose (fout);
        fprintf (fout3, "%d", count);
        fflush (fout3);
        fclose (fout3);
    }
    else
    {
        //tatal
        fclose (fin1);
        fclose (fin2); fclose (fout2);
        fclose (fout3);
        int count;
        char c;
        FILE *fin = fopen ("date.txt", "r");
        while (fscanf (fin, "%c", &c) != EOF)
        {
            fprintf (fout1, "%c", c);
            fflush (fout1);
        }
        fclose (fin);
        fclose (fout1);
        fscanf (fin3, "%d", &count);
        fclose (fin3);
        printf ("%d", count);
    }
    return 0;
}
