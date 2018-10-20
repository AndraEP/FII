/*
2. Scrieti un mic program C care sa execute comanda "cat -n -E /etc/passwd" folosind un apel 
din familia exec(), iar la final sa afiseze codul ei de terminare. 
*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int rez;
	if (fork()==0)
	    execlp("cat", "cat", "-n", "-E", "/etc/passwd", 0);
	else
	{
	    wait(&rez);
	    printf("%d", WEXITSTATUS(rez));
	}
}


/*
3. Fie programul C de mai jos. El contine (macar) 3 erori sintactice si o greseala logica.
Corectati-le, astfel incat programul sa poata fi executat si sa produca la executie afisarea
pe ecran de catre procesul fiu a textului primit de la parinte.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char w=0, *text;
  int p,q[2];
  pipe(q); //eroarea sintactica era q[2]
  p=fork(); //eroarea sintactica era fork(2)
  if(p==-1) exit(2);
  if(!p)
  {
    dup2(q[0],0);
    close(q[1]);
    while( read(0,&w,1) != 0)
      printf("%c",w);
    wait(NULL);
  }
  else //eroarea sintactica era elif
  {
    text="salutari!";
    write(q[1],text,strlen(text)); //eroare logica, initial q[0]
  }
  return 0;
}


/*
4. Scrieti un program C care va crea 2 procese fii si va citi de la tastatura o secventa de 
numere terminata cu CTRL+D. Numerele pozitive vor fi trimise primului fiu, iar numerele negative
vor fi trimise celui de-al doilea fiu. Fiecare fiu va calcula suma numerelor primite si va 
afisa in final identitatea lui si secventa de numere primita, iar suma secventei o va trimite
parintelui. Procesul initial va afisa la final cele doua sume primite de la fii si suma celor
doua sume.
*/
