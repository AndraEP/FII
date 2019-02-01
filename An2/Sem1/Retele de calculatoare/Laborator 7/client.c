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
#define max 100

int main (int argc, char* argv[])
{
  int sd;			//descriptorul de socket
  struct sockaddr_in server;	//structura folosita pentru conectare
  char msgin[max];		//mesajul trimis
  char msgout[max];             //mesaj de trimis
  
  //cream socketul
  if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror ("Eroare la socket().\n");
      return errno;
    }

  //umplem structura
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_port = htons (PORT);
  
  //ne conectam la server
  if (connect (sd, (struct sockaddr *) &server,sizeof (struct sockaddr)) == -1)
  {
      perror ("[client] Eroare la connect().\n");
      return errno;
  }
  
  while (1)
  {
      printf ("[client] Introdu un key:\n 1111 pentru ls,\n 2222 pentru pwd,\n 3333 pentru ps: \n\n> ");
      fflush (stdout);
      
        memset(msgout, 0, sizeof (msgout));
        read (0, msgout, sizeof (msgout));
        
        msgout[strlen(msgout) - 1] = 0;
        write (sd, msgout, sizeof (msgout));
        
        memset(msgin, 0, sizeof (msgout));
        read (sd, msgin, sizeof (msgin));
        printf ("[client] Mesajul primit de la server este: %s\n\n", msgin);
        if (strcmp(msgin, "Unknown key.") == 0) break;
    }
    close (sd);
}
