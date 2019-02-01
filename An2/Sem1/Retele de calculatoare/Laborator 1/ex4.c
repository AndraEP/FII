#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

int main (int argc, char* argv[])
{
        int lungime, separator, flag;
        char nume[500];
        struct stat fisier;

        if (argc <= 1) exit(1); //nu are destule argumente

        lungime = strlen(argv[1]);
        separator = -1;

        for (int i = 0; i < lungime; i++)
        {
                if (argv[1][i] == '/') separator = i;
        }

        strcpy (nume, argv[1] + separator + 1);
        printf ("%s", nume);

        flag = stat (argv[1], &fisier);
        if (flag != 0) exit(2);

        printf("%s\n", ctime(&fisier.st_mtime));
        return 0;
}
