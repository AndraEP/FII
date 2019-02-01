#include <stdio.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int sockp[2];

int main()
{
    socketpair(AF_UNIX, SOCK_STREAM, 0, sockp);
    if (fork() == 0)
    {
        char a[BUFFER_SIZE];
        close(sockp[1]);
        int len;
        read(sockp[0], &len, sizeof(int));
        read(sockp[0], &a, len);
        a[len] = 0;
        strcat(a, "This is the second string.");
        len = strlen(a);
        write(sockp[0], &len, sizeof(int));
        write(sockp[0], &a, len);
        close(sockp[0]);
    }
    else
    {
        char a[BUFFER_SIZE];
        close(sockp[0]);
        strcpy(a, "This is the first string. ");
        int len = strlen(a);
        write(sockp[1], &len, sizeof(int));
        write(sockp[1], &a, len);
        read(sockp[1], &len, sizeof(int));
        read(sockp[1], &a, len);
        a[len] = 0;
        printf ("%s\n", a);
        close(sockp[1]);
    }
}
