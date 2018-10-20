//ex1

#include <stdio.h>

void dialog (char* this, char* other)
{
    FILE *f1, *f2;
    char s[256], flag[256];
    f1 = fopen (this, "r");
    while (!feof (f1))
    {
        do
        {
            f2 = fopen ("selector.txt", "r");
            fgets (flag, 256, f2);
            fclose (f2);
        } while (strcmp (flag, this));
        fgets (s, 256, f1);
        s[strcspn(s, "\n")] = 0; //smecheria da? da ma da
        printf ("%s (%s)\n", s, this);
        f2 = fopen ("selector.txt", "w");
        fprintf (f2, "%s", other);
        fclose (f2);
    }
}

int main()
{
    FILE *f = fopen ("selector.txt", "w");
    fprintf (f, "fisier1.txt");
    fclose (f);
    int pid;
    pid = fork();
    if (pid == -1)
    {
        perror ("Eroare la fork");
        exit (-1);
    }
    if (pid == 0)
    {
        dialog ("fisier1.txt", "fisier2.txt");
    }
    else
    {
        dialog ("fisier2.txt", "fisier1.txt");
    }
    return 0;
}


//ex2

#include <stdio.h>
#include <stdbool.h>

void master_init (int n, char *f1, char *f2)
{
    int pid1, pid2;
    pid1 = fork();
    if (pid1 == -1)
    {
        perror ("Eroare la fork");
        exit (-1);
    }
    if (pid1 == 0)
    {
        slave_work (n, f1, 0);
        exit (0);
    }
    wait();
    pid2 = fork();
    if (pid2 == -1)
    {
        perror ("Eroare la fork");
        exit (-1);
    }
    if (pid2 == 0)
    {
        slave_work (n, f2, 1);
        exit (0);
    }
    wait();
}

void master_finish (int n, char *f1, char *f2)
{
    FILE *file1, *file2;
    int x, y, i;
    char c;
    file1 = fopen (f1, "r");
    file2 = fopen (f2, "r");
    for (i=1; i<=n; i++)
    {
        fscanf (file1, "%d %d ", &x, &y);
        fscanf (file2, "%c ", &c);
        if (c == '+') printf ("%d + %d = %d\n", x, y, x + y);
        else if (c == '-') printf ("%d - %d = %d\n", x, y, x - y);
        else if (c == '*') printf ("%d * %d = %d\n", x, y, x * y);
        else if (c == '/') printf ("%d / %d = %d\n", x, y, x / y);
    }
    fclose (file1);
    fclose (file2);
}

void slave_work (int n, char* file, bool usage)
{
    FILE *f;
    int i, x, y;
    char c;
    if (usage == 0)
    {
        printf("Introduceti %d perechi de operanzi:\n", n);
        f = fopen (file, "w");
        for (i=1; i<=n; i++)
        {
            scanf ("\n%d %d", &x, &y);
            fprintf (f, "%d %d ", x, y);
        }
        fclose (f);
    }
    else if (usage == 1)
    {
        printf ("Introduceti %d operatori:\n", n);
        f = fopen (file, "w");
        for (i=1; i<=n; i++)
        {
            scanf ("\n%c", &c);
            fprintf (f, "%c ", c);
        }
        fclose (f);
    }
}

int main (int argc, char** argv)
{
    int  n;
    const char *f1 = "operanzi.bin";
    const char *f2 = "operatori.txt";
    remove (f1);
    remove (f2);
    if (argc > 1)
    {
        n = atoi (argv[1]);
    }
    else
    {
        printf ("Introduceti numarul de operatii:\n");
        scanf ("%d", &n);
    }
    master_init (n, f1, f2);
    master_finish (n, f1, f2);
    return 0;
}


//ex3

#include <stdio.h>

int main (int argc, char** argv)
{
    int n, i, pid;
    printf("Introduceti numarul de fii: ");
    scanf("%d", &n);
    printf("Sunt procesul initial cu PID-ul: %d, iar parintele meu este procesul cu PID-ul: %d.\n", getpid(), getppid());
    for (i=1; i<=n; i++)
    {
        pid = fork();
        if (pid == -1)
        {
            perror ("Eroare la fork");
            exit (-1);
        }
        if (pid == 0)
        {
            printf("Sunt procesul fiu %d, avand PID-ul: %d, iar parintele meu este procesul cu PID-ul: %d.\n", i, getpid(), getppid());
            return 0;
        }
    }
    for (i=1; i<=n; i++) wait ();
    return 0;
}


//ex4

#include <stdio.h>
#include <sys/wait.h>

int main (int argc, char** argv)
{
    int n, i, codterm, pid;
    printf ("Introduceti numarul de procese: ");
    scanf ("%d", &n);
    for (i=1; i<n; i++)
    {
        pid = fork();
        if (pid == -1)
        {
            perror ("Eroare la fork");
            exit (-1);
        }
        if (pid != 0)
        {
            wait (&codterm);
            printf ("Sunt procesul %d, avand PID-ul: %d, parintele are PID-ul: %d, iar fiul creat are PID-ul: %d si s-a terminat cu codul: %d.\n", i, getpid(), getppid(), pid, WEXITSTATUS(codterm));
            return i;
        }
        else if (pid == 0 && i == n-1)
        {
            printf ("Sunt procesul ultim, %d din lantul de procese, avand PID-ul: %d, iar parintele meu este procesul cu PID-ul: %d.\n", n, getpid(), getppid());
            return n;
        }
    }
}


//ex5

#include <stdio.h>
#include <sys/wait.h>

int n;

void creeaza_fiu (int i)
{
    int pid, codterm;
    if (i < n)
    {
        pid = fork();
        if (pid == -1)
        {
            perror ("Eroare la fork");
            exit (-1);
        }
        if (pid != 0)
        {
            wait (&codterm);
            printf("Sunt procesul %d, avand PID-ul: %d, parintele are PID-ul: %d, iar fiul creat are PID-ul: %d si s-a terminat cu codul: %d.\n", i, getpid(), getppid(), pid, WEXITSTATUS(codterm));
            exit (i);
        }
        else
        {
            creeaza_fiu (i+1);
        }
    }
    else
    {
        printf ("Sunt procesul ultim, %d din lantul de procese, avand PID-ul: %d, iar parintele meu este procesul cu PID-ul: %d.\n", n, getpid(), getppid());
        exit (n);
    }
}

int main (int argc, char** argv)
{
    printf ("Introduceti numarul de procese: ");
    scanf ("%d", &n);
    creeaza_fiu (1);
}


//ex6

#include <stdio.h>
#include <sys/wait.h>

int n, k, count = 1;

void creeaza_fii (int i)
{   
    int pid[101], codterm[101], j;
    if (i < n)
    {
        for (j=1; j<=k; j++)
        {
            pid[j] = fork();
            if (pid[j] == -1)
            {
                perror ("Eroare la fork");
                exit (-1);
            }
            if (pid[j] == 0)
            {
                count = j;
                break;
            }
            else wait (&codterm[j]);
        }
        if (j == k+1)
        {
            printf ("Sunt procesul %d de pe nivelul %d, PID: %d, PID parinte: %d, PID fii: ", count, i, getpid(), getppid());
            for (int q=1; q<=k; q++) printf ("%d, ", pid[q]);
            printf ("si s-au terminat cu codurile: ");
            for (int q=1; q<=k; q++) printf ("%d, ", WEXITSTATUS (codterm[q]));
            printf ("\n");
            exit (count);
        }
        else
        {
            creeaza_fii (i+1);
        } 
    }
    else
    { 
        printf ("Sunt procesul fara fii %d de pe nivelul %d, PID: %d, PID parinte: %d\n", count, i, getpid(), getppid());
        exit (count);
    }
}

int main (int argc, char** argv)
{
    printf ("Introduceti numarul de fii si de nivele: ");
    scanf ("%d%d", &k, &n);
    creeaza_fii (1);
}


//ex7

#include <stdio.h>
#include <sys/wait.h>

int main (int argc, char** argv)
{
    int n, k, i, j, count = 1, codterm[101], pid[101];
    printf ("Introduceti numarul de fii si de nivele: ");
    scanf ("%d%d", &n, &k);
    for (i=1; i<n; i++)
    {
        for (j=1; j<=k; j++)
        {
            pid[j] = fork();
            if (pid[j] == -1)
	        {	            perror ("Eroare la fork");
	            exit (-1);
	        }
            if (pid[j] == 0)
            {
                count = j;
                break;
            }
            else wait (&codterm[j]);
        }
        if (j == k+1)
        {
            printf ("Sunt procesul %d de pe nivelul %d, PID: %d, PID parinte: %d, PID fii: ", count, i, getpid(), getppid());
            for (int q=1; q<=k; q++) printf ("%d, ", pid[q]);
            printf ("si s-au terminat cu codurile: ");
            for (int q=1; q<=k; q++) printf ("%d, ", WEXITSTATUS (codterm[q]));
            printf ("\n");
            return count;
        }
        else if (j < k+1 && i == n-1)
        {
            printf ("Sunt procesul fara fii %d de pe nivelul %d, PID: %d, PID parinte: %d\n", count, i, getpid(), getppid());
            return count;
        }
    }
}
