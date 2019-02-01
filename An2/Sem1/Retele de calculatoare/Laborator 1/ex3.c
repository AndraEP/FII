#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

const char* tinta;

void procesare (char* cale)
{
        int ok; 
        char nume[256];
        DIR* dir;
        struct dirent* director; //memoreaza date despre director
        struct stat fisier; //memoreaza date despre un fisier

        ok = stat (cale, &fisier);
        if (ok < 0) return; //nu exista fisierul 

        if (S_ISDIR(fisier.st_mode) != 0) //se verifica daca fisierul este folder
        {
                dir = opendir(cale);
                if (dir == 0) return; //eroare la deschidere
                while (1)
                {
                        director = readdir (dir);
                        if (director == 0) break; //eroare la citire
                        if ((strcmp (director->d_name, ".") != 0) && ((strcmp (director->d_name, "..") != 0))
                        {
                                sprintf (nume, "%s %s", cale, director);
                                if (strcmp (director->d_name, tinta) == 0)
                                        printf("%s\n", nume);
                                procesare (nume);
                        }
                }
                closedir (dir);
        }
}

int main (int argc, char* argv[])
{
        int flag;
        char* cale = "/home";

        if (argc <= 1) 
                exit(1); //prea putine argumente
        
        tinta = argv[1];
        procesare (cale);
        return 0;
}

