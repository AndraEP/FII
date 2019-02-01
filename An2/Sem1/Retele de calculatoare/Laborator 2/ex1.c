#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int p[2];

int main()
{
    pipe (p);
    FILE* fin = fdopen (p[0], "r");
    FILE* fout = fdopen (p[1], "w");
    int pid;
    
    if ((pid = fork()) == 0)
    {
        //P1
        fclose (fout);
        char mesaj[500];
        fscanf (fin, "%s", mesaj);
        printf ("%s", mesaj);
        fclose (fin);
    }
    else
    {
        //P0
        fclose (fin);
        if (pid % 2 == 0)
        {
            fprintf(fout, "fortune");
            fflush(fout);
            fclose(fout);
            wait(NULL);
        }
        else
        {
            printf("lost");
            exit(0);
        }
    }
    return 0;
}
