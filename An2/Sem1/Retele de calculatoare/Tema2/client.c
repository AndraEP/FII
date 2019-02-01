#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 2024
#define max 10000

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

extern int errno;

int main (int argc, char* argv[])
{
    //client + server
    int sd;			//descriptorul de socket
    struct sockaddr_in server;	//structura folosita pentru conectare
    char msgin[max];		//mesajul trimis
    char msgout[max];           //mesaj de trimis

    if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)	//creare socket
    {
        perror ("Eroare la socket().\n");
        return errno;
    }

    server.sin_family = AF_INET;			//familia socket-ului
    server.sin_addr.s_addr = inet_addr ("127.0.0.1");	//adresa IP a serverului
    server.sin_port = htons (PORT);			//portul de conectare

    if (connect (sd, (struct sockaddr *) &server, sizeof (struct sockaddr)) == -1)	//conectare la server
    {
        perror ("[client]Eroare la connect().\n");
        return errno;
    }

    printf (ANSI_COLOR_GREEN "\n\n\n\n\n--------------------------> PROGRAM STARTED <--------------------------\n\n" ANSI_COLOR_RESET);
    printf (ANSI_COLOR_CYAN "                               Hello! :)\n" ANSI_COLOR_RESET);
    printf (ANSI_COLOR_CYAN "                          Welcome to TopMusic!\n\n\n" ANSI_COLOR_RESET);
    printf (ANSI_COLOR_CYAN "                  Here are some tips before you start:\n" ANSI_COLOR_RESET);
    printf (ANSI_COLOR_CYAN "                        This color is for tips.\n" ANSI_COLOR_RESET);
    printf (ANSI_COLOR_GREEN "                     This color is for good output.\n" ANSI_COLOR_RESET);
    printf (ANSI_COLOR_RED   "                       This color is for errors.\n" ANSI_COLOR_RESET);
    printf (ANSI_COLOR_YELLOW"        This color is for database errors or for a wrong command.\n" ANSI_COLOR_RESET);
    printf ("         This color is for client errors, input or for quitting.\n\n\n");
    printf (ANSI_COLOR_CYAN "                       Now you are good to start.\n" ANSI_COLOR_RESET);
    printf (ANSI_COLOR_CYAN "           Type in 'commands' to see the available commands.\n\n\n\n\n\n" ANSI_COLOR_RESET);

    while (1)
    {
        printf (ANSI_COLOR_GREEN ">> " ANSI_COLOR_RESET);
        fflush (stdout);

        memset (msgout, 0, sizeof (msgout));
        read (0, msgout, sizeof (msgout));	//citire tastatura
        msgout[strlen (msgout) - 1] = 0;

        write (sd, msgout, sizeof (msgout));	//scriere server
        memset (msgin, 0, sizeof (msgin));
        read (sd, msgin, sizeof (msgin));	//citire server

        printf ("%s\n", msgin);

        if (strcmp (msgin, "Quitting...") == 0) break;
    }

    printf (ANSI_COLOR_GREEN "\n\n\n\n\n---------------------------> PROGRAM ENDED <---------------------------\n\n\n\n\n\n" ANSI_COLOR_RESET);
    close (sd);
    return 0;
}
