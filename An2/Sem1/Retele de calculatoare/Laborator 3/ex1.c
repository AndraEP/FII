#include <stdio.h>

_Bool is_prime(int x)
{
    if (x < 2) return 0;
    else if (x % 2 == 0 && x != 2) return 0;
    else for (int d = 3; d * d <= x; d += 2) if (x % d == 0) return 0;
    return 1;
}

int p[2];

int main()
{
    pipe (p);
    FILE* fin = fdopen (p[0], "r");
    FILE* fout = fdopen (p[1], "w");
    if (fork() == 0)
    {
        //P1
        int nr;
        const char* answer;
        fscanf (fin, "%d", &nr);
        fclose (fin);
        if (is_prime(nr)) answer = "yes";
        else answer = "no";
        fprintf(fout, "%s", answer);
        fflush(fout);
        fclose(fout);
    }
    else
    {
        //P0
        int nr;
        char answer[4];
        scanf("%d", &nr);
        fprintf(fout, "%d ", nr);
        fflush(fout);
        fclose(fout);
        wait(NULL); //optional
        fscanf(fin, "%s", answer);
        fclose(fin);
        printf("%s", answer);
    }
    return 0;
}
