#include <stdio.h>

int main (int argc, char** argv)
{
    char ans[2];
    if (argc < 2) exit (1); //nu a fost dat directorul
    if (fork() == 0) execlp ("ls", "ls", "-l", argv[1], NULL);
    wait (NULL);
    printf ("Stergem directorul %s? y/n\n", argv[1]);
    scanf ("%s", &ans);
    if (ans[0] != 'y') return 0;
    if (fork() == 0) execlp ("rm", "rm", "-r", argv[1], NULL);
    wait (NULL);
    return 0;
}
