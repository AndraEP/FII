#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PORT 2024
#define max 100
extern int errno;

int main (int argc, char* argv[])
{
  struct sockaddr_in server;	// structura folosita de server
  struct sockaddr_in from;	
  char msgin[max];		//mesajul primit de la client 
  char msgout[max];             //mesaj de raspuns pentru client
  char linie[max];
  char* key, * comanda;
  int sd;			//descriptorul de socket 

  /* crearea unui socket */
  if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror ("[server] Eroare la socket().\n");
      return errno;
    }
  
  /* umplem structura folosita de server */
    server.sin_family = AF_INET;	
    server.sin_addr.s_addr = htonl (INADDR_ANY);
    server.sin_port = htons (PORT);
  
  /* atasam socketul */
  if (bind (sd, (struct sockaddr *) &server, sizeof (struct sockaddr)) == -1)
    {
      perror ("[server] Eroare la bind().\n");
      return errno;
    }

  /* pregatirea structurilor de date */
  bzero (&server, sizeof (server));
  bzero (&from, sizeof (from));

  /* punem serverul sa asculte daca vin clienti sa se conecteze */
  if (listen (sd, 5) == -1)
    {
      perror ("[server] Eroare la listen().\n");
      return errno;
    }

  printf ("[server] Asteptam la portul %d ...\n", PORT);
  fflush (stdout);

  //acceptare client
  int client = accept (sd, NULL, NULL);
  if (client < 0)
    {
      perror ("[server] Eroare la accept().\n");
    }
 
  while (1)
    {

      int gasit = 0, inchis = 0;

      printf ("[server] Asteptam mesajul ...\n");
      fflush (stdout);

      memset (msgin, 0, sizeof(msgin));

      if (read (client, msgin, sizeof(msgin)) <= 0)
	{
	  printf ("[server] Eroare la read() de la client.\n");
	}
      else printf ("[server] Mesajul a fost receptionat...%s\n", msgin);

      /*pregatim mesajul de raspuns */
      memset(msgout, 0, sizeof (msgout));
      strcat(msgout,"Hello ");
      strcat(msgout,msgin);

      FILE* fin = fopen("text.txt", "r");
      while (!gasit && fscanf(fin, "%s", linie) != EOF)
        {
          char* p = strchr(linie, ':');
          *p = 0;
          key = linie;
          comanda = p + 1;
          if (strcmp(key, msgin) == 0) 
             gasit = 1;
        }
      fclose(fin);

      if (gasit)
        {
          strcpy(msgout, "Comanda executata.");
          if (fork() == 0) execlp(comanda, comanda, NULL);
          wait(NULL);
        }
        else
        {
          strcpy(msgout, "Unknown key.");
          inchis = 1;
        }

      printf("[server] Trimitem mesajul inapoi...%s\n",msgout);      
      
      /* returnam mesajul clientului */
      if (write (client, msgout, sizeof(msgout)) <= 0)
	{
	  printf ("[server] Eroare la write() catre client.\n");
	}
      else
	printf ("[server] Mesajul a fost trasmis cu succes.\n");

      if (inchis == 1)
        {
           close (client);
	   break;
	}
    }
    close (sd);
}
