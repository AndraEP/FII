#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int signo)
{
    if (signo == SIGUSR1)
    {
        FILE* f = fopen ("file.txt", "w");
        fprintf (f, "Am primit semnal");
        fflush(f);
        fclose(f);
    }
    else if (signo == SIGINT)
    {
        //do nothing
    }
}

int main(int argc, char** argv)
{
    signal(SIGUSR1, sig_handler);
    signal(SIGINT, sig_handler);
    int count = 0;
    while (1)
    {
        printf ("%d %d\n", getpid(), ++count);
        fflush(stdout);
        sleep(3);
        if (count == 20) signal (SIGINT, SIG_DFL); //set to default after 60 seconds
    }
    return 0;
}
