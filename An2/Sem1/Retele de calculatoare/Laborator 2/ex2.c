#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
    if (fork() == 0)
    {
        char* dir;
        
        if (argc >= 2)
            dir = argv[1];
        else
        {
            dir = malloc (2);
            dir = ".";
        }
        
        execlp ("ls", "ls", "-a", "-l", dir, NULL);
    }
    else
    {
        int terminare;
        
        wait (&terminare);
        errno = WEXITSTATUS (terminare);
        
        if (errno == 0) printf ("ok");
        else
        {
            perror ("Eroare");
            exit (WEXITSTATUS (errno));
        }
    }
    return 0;
}
