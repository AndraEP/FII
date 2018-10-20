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

/*#include <stdio.h>

int main()
{
	int pid;
	pid = fork();

//	if (pid == 0)
	{
		sleep(3);
		printf("Copil %d", getpid());
		printf("\n");
	}
	else
	{
		printf("Parinte %d", pid);
		printf("\n");
	}
//

	if (pid == 0)
	{
		com ("fisier.txt", "fisier2.txt"); //com ("fiu", "parinte");
		//printf("\n");
	}
	else
	{
		com ("fisier2.txt", "fisier.txt"); //com ("parinte", "fiu");
		//printf("\n");
	}
}

void com(char *fisier, char *other)
{
	FILE *f1=fopen(fisier, "r");
	char l[250];
	char flag[20];

	while (!feof(f1))
	{
		do 
		{
			FILE *f2=fopen("fisier3.txt", "r");
			fgets(flag, 20, f2);
			close(f2);
		} while(strcmp(flag, fisier));

		fgets(l, 250, f1);
		s[strcspn(s, "\n")] = 0;
        	printf ("%s (%s)\n", s, this);
		//sleep(1);
		FILE *f2=fopen ("fisier3.txt", "w");
		fprintf("%s\n", other);
		fclose(f2);
	}

}
*/
