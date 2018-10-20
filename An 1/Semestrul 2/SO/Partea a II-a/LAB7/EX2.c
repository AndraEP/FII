#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>

void afisare_info (char* cale)
{
    struct stat st;
    struct passwd *pwd;
    char perm[10]="---------";

    if(stat (cale, &st) != 0)
    {
        fprintf (stderr, "Eroare la stat pentru %s .\t", cale);
        perror ("Cauza este");
        return;
    }
    printf ("Analizam fisierul/directorul: %s\n", cale);
    printf ("\tTipul acestui fisier: ");
    switch (st.st_mode & S_IFMT)
    {
        case S_IFSOCK: printf ("Socket\n"); break;
        case S_IFLNK : printf ("Link\n");break;
        case S_IFREG : printf ("Fisier obisnuit\n");break;
        case S_IFBLK : printf ("Block device\n"); break;
        case S_IFCHR : printf ("Character device\n"); break;
        case S_IFIFO : printf ("FIFO\n"); break;
        case S_IFDIR : printf ("Director\n"); break;
        default: printf ("Unknown file type");
    }
    printf ("\tDimensiunea: %lld octeti\n", (long long) st.st_size);

    if(S_IRUSR & st.st_mode) perm[0]='r';
    if(S_IWUSR & st.st_mode) perm[1]='w';
    if(S_IXUSR & st.st_mode) perm[2]='x';
    if(S_IRGRP & st.st_mode) perm[3]='r';
    if(S_IWGRP & st.st_mode) perm[4]='w';
    if(S_IXGRP & st.st_mode) perm[5]='x';
    if(S_IROTH & st.st_mode) perm[6]='r';
    if(S_IWOTH & st.st_mode) perm[7]='w';
    if(S_IXOTH & st.st_mode) perm[8]='x';

    printf("\tPermisiunile: %s\n", perm);

    if((pwd = getpwuid (st.st_uid)) != 0)
        printf ("\tProprietarul: %s (cu UID-ul: %ld)\n", pwd->pw_name, (long) st.st_uid);
    else
        printf ("\tProprietarul are UID-ul: %ld\n", (long) st.st_uid);    
}

void procesare_intrare (char *cale)
{
    DIR *dir;
    struct dirent *de;
    struct stat st;
    char nume[PATH_MAX];
    afisare_info (cale);
    if (stat (cale, &st) != 0)
    {
        fprintf (stderr, "Eroare la stat pentru %s .\t", cale);
        perror ("Cauza este");
        return;
    }
    if (S_ISDIR (st.st_mode) != 0)
    {
        if((dir = opendir(cale)) == 0)
        {
            fprintf (stderr, "Eroare deschidere director %s .\t", cale);
            perror ("Cauza este");
            return;
        }
        while((de = readdir (dir)) != 0)
        {
            if(strcmp (de->d_name, ".") && strcmp (de->d_name, ".."))
            {
                sprintf (nume, "%s/%s", cale, de->d_name);
                procesare_intrare (nume);
            }
        }
        closedir (dir);
    }
}

int main (int argc, char** argv)
{
    struct stat st;
    if(argc == 1)
    {
         fprintf (stderr,"Usage: %s director!\n",argv[0]);
         exit (1);
    }

    if(stat (argv[1], &st) != 0)
    {
        fprintf (stderr,"Eroare la stat pentru %s .\t", argv[1]);
        perror ("Cauza este");
        exit (2);
    }
    if (S_ISDIR (st.st_mode) == 0)
    {
        fprintf (stderr, "Eroare: %s nu este director!\n", argv[1]);
        exit(3);
    }
    printf ("Analizam directorul: %s\n", argv[1]);
    procesare_intrare (argv[1]);
    return 0;
}
