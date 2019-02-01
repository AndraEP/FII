#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
        int uid, k;
        char* utilizator, linie[500], matrice[500][500];

        uid = getuid();
        FILE* f = fopen ("/etc/passwd", "r");
        if (f == 0) exit(1);

        while (fgets(linie, sizeof(linie), f))
        {
                utilizator = strtok(linie, ":");
                k = 0;

                while (utilizator != 0)
                {
                        strcpy(matrice[++k], utilizator);
                        utilizator = strtok(NULL, ":");
                }

                if (atoi(matrice[3]) == uid)
                {
                        printf ("%s %s", matrice[1], matrice[7]);
                        exit(0);
                }
        }
        return 0;
}
