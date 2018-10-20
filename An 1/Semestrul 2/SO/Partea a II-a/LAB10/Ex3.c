#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>

int main (int argc, int** argv)
{
    if (fork() == 0)
    {
        char* dir;
        if (argc >= 2)
        {
            dir = argv[1];
        }
        else
        {
            dir = malloc (2);
            dir = ".";
        }
        execlp ("ls", "ls", "-i", "-l", dir, NULL);
    }
    else
    {
        int codterm;
        wait (&codterm);
        errno = WEXITSTATUS (codterm);
        if (errno == 0) printf ("Comanda ls a fost executata...\n");
        else
        {
            perror ("Eroare. Cauza");
            exit (WEXITSTATUS (errno));
        }
    }
    return 0;
}
