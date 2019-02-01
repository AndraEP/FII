#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[])
{
        char linie[500];
        if (argc <= 2) exit(1);

        FILE *f = fopen(argv[2], "r");
        if (f == 0) exit(2); //nu exista fisierul

        while (fgets(linie, sizeof(linie), f) != NULL)
        {
                if (strstr(linie, argv[1]) != NULL) printf("%s", linie$
        }

        fclose(f);
        return 0;
}
