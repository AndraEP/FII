//slave

#include <string.h>

int main (int argc, char** argv)
{
    int a, b;
    char semn;
    if (argc < 2) exit (1); //incorrect usage
    a = atoi (argv[1]);
    b = atoi (argv[2]);
    semn = argv[3][0];
    if (semn == '+')
    {
        exit (a+b);
    }
    else if (semn == '-')
    {
        exit (a-b);
    }
}



//master

#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    int codterm, op1, op2;
    char arg1[10], arg2[10], semn[10];
    if (fork() == 0) execlp ("gcc", "gcc", "slave.c", "-w", "-o", "slave", NULL);
    wait (NULL);
    while (1)
    {
        scanf ("%d%d %s", &op1, &op2, &semn);
        sprintf (arg1, "%d", op1);
        sprintf (arg2, "%d", op2);
        if (fork() == 0) execl ("slave", "slave", arg1, arg2, semn, NULL);
        wait (&codterm);
        printf ("Rezultat: %d\n", WEXITSTATUS (codterm));
    }
}
