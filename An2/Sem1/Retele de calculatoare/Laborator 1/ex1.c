#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
        int i, j=0;
        char linie[500][500];

        if (argc <= 1) exit(1); //nu exista argumente suficiente

        FILE *f = fopen(argv[1], "r");
        if (f == 0) exit(2);

        while (fgets(linie[j++], sizeof(linie), f) != NULL); //se incr$
        for (i = j-1; i >= 0; i--) printf("%s", linie[i]);

        fclose(f);
        return 0;
}
