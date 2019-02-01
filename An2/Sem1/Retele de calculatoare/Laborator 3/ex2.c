#include <stdio.h>
#include <fcntl.h>

int main()
{
    mkfifo("myfifo", 0600);
    int p[2];
    if (fork() == 0)
    {
        p[1] = open("myfifo", O_WRONLY);
        dup2 (p[1], 1);
        execlp ("cat", "cat", "prog.c", NULL);
        close (p[1]);
    }
    else
    {
        int fd = open ("file.txt", O_WRONLY | O_CREAT, 0600);
        p[0] = open("myfifo", O_RDONLY);
        dup2 (p[0], 0);
        dup2 (fd, 1);
        execlp ("grep", "grep", "include", NULL);
        close (p[0]);
    }
    return 0;
}
