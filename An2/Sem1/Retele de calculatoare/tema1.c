#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <time.h>

#define MAX_ARRAY 500
#define MSG1 "Hi! I am parent!"
#define MSG2 "Hello parent, I am child."

char msg[MAX_ARRAY];

void login (char* result, char* message_username)
{
	char username[MAX_ARRAY], message [MAX_ARRAY];
	memset (username, 0, strlen (username));
	int ok = 0;
	FILE* fin = fopen ("config.ini", "r");

	//there is data in the config.ini file
	if (fin != NULL)
	{
		//the file is searched until the end of it
		while (fgets (username, MAX_ARRAY, fin) != NULL)
		{
            		username[strlen(username) - 1] = 0;
			
			//a mach has been found
			if (strcmp (message_username, username) == 0)
			{	
				ok = 1; 
				break;
			}
		}
		
		if (ok == 1)
		{
			strcpy (message, "Success! The username has been found.\n");
		}
		else
		{
			strcpy (message, "Error! The username has not been found. Try another one!\n");
		}
	}
	else 
		strcpy (message, "File config.ini can't be read!\n");
	sprintf (result, "%s", message);
}

void find_file (char* current_path, char* result, char* myfind_name)
{
	char name_dir[MAX_ARRAY];
	char erropen[] = "Error while opening";
	char errfind[] = "File does not exist";
	DIR* dir;
	struct dirent* director; //data about dir
	struct stat file; //data about file

	//file does not exist
	if ((stat (current_path, &file)) < 0)
	{
		printf("%s\n", errfind);
		return;
	}
	else
	{
        	if (S_ISDIR(file.st_mode))
       		{
   	        	dir = opendir(current_path); 
            		
			//error while trying to read further
  	        	if (dir == 0)
	                {
        		        printf("%s\n", erropen);
        		        return;
                        }
                	
			//we can read into it so we are going deeper
                	while ((director = readdir (dir)) != NULL)
                	{ 
                		if ((strcmp (director->d_name, ".") != 0) && (strcmp (director->d_name, "..") != 0))
                    		{	
                        		sprintf (name_dir, "%s/%s", current_path, director->d_name);
                        		
					if (strcmp (director->d_name, myfind_name) == 0)
                        		{
						strcat (result, name_dir); strcat(result, "\n");
                                    	}
					
					find_file (name_dir, result, myfind_name);
					
                    		}
                	}
			closedir(dir);
        	}
	}
}

void stat_file (char* result, char* mystat_name)
{
	char copy [MAX_ARRAY], message [MAX_ARRAY];
	char errfind[] = "File does not exist!";
	struct stat file;

    	if ((stat (mystat_name, &file)) < 0)    
        {
		printf ("%s\n", errfind);
		return;
	}
	else 
	{
		//Writing the data of the file 
		sprintf (copy, "Details about file... \n\nFile size: \t%lu\nNumber of links: \t%lu\nFile serial number: \t%lu\nLast accessed: \t%s\nLast modified: \t%s\nFile permissions: \t", file.st_size, file.st_nlink, file.st_ino, ctime (&file.st_atime), ctime (&file.st_mtime));

		strcpy (message, copy);

		if (S_ISDIR(file.st_mode))
			strcat (message, "d");
		else strcat (message, "-");

		if (file.st_mode && S_IRUSR)
			strcat (message, "r");
		else strcat (message, "-");
	
		if (file.st_mode && S_IWUSR)
			strcat (message, "w");
		else strcat (message, "-");
	
		if (file.st_mode && S_IXUSR)
			strcat (message, "x");
		else strcat (message, "-");
	
		if (file.st_mode && S_IRGRP)
			strcat (message, "r");
		else strcat (message, "-");
	
		if (file.st_mode && S_IWGRP)
			strcat (message, "w");
		else strcat (message, "-");
	
		if (file.st_mode && S_IXGRP)
			strcat (message, "x");
		else strcat (message, "-");
	
		if (file.st_mode && S_IROTH)
			strcat (message, "r");
		else strcat (message, "-");
	
		if (file.st_mode && S_IWOTH)
			strcat (message, "w");
		else strcat (message, "-");
	
		if (file.st_mode && S_IXOTH)
			strcat (message, "x");
		else strcat (message, "-");
	
		strcat (message, "\n");
	
		if (S_ISLNK (file.st_mode))
			strcat (message, "The file is a symbolic link.");
		else if (S_ISSOCK (file.st_mode))
			strcat (message, "The file is a socket.");
		else if (S_ISDIR (file.st_mode))
			strcat (message, "The file is a directory.");
		else if (S_ISFIFO (file.st_mode))
			strcat (message, "The file is a FIFO.");
		else if (S_ISREG (file.st_mode))
			strcat (message, "The file is a regular one.");
		else if (S_ISCHR (file.st_mode))
			strcat (message, "The file is a character device.");
		else if (S_ISBLK (file.st_mode))
			strcat (message, "The file is a block device.");
		else strcat (message, "Couldn't find the file type!");
	}
	strcat (message, "\n");
	strcpy (result, message);
}

int quit_program (char* result, char* message)
{
	strcpy (result, message);
}

void child (int socket) 
{
	if (write(socket, MSG1, sizeof(MSG1)) < 0)
		perror("Error writing child socket."); 
	
	if (read(socket, msg, MAX_ARRAY) < 0)
		perror("Error reading child socket."); 
	
	printf("Socket child: %s\n\n", msg);
}

void parent (int socket) 
{
	if (read(socket, msg, MAX_ARRAY) < 0)
		perror("Error reading parent socket."); 
        
	printf("Socket parent: %s\n", msg); 
        
	if (write(socket, MSG2, sizeof(MSG2)) < 0)
		perror("Error writing parent socket.");
}

int main (int argc, char* argv[])
{
	char message[MAX_ARRAY], current_path[MAX_ARRAY], message_username[MAX_ARRAY], result[MAX_ARRAY], myfind_name[MAX_ARRAY], mystat_name[MAX_ARRAY], msg[MAX_ARRAY];
	char log_in[] = "login username: ";
	char myfind[] = "myfind ";
	char mystat[] = "mystat ";
	char quit[] = "quit";
	int process1[2], process2[2], value = 1, len, sockp[2];
	mkfifo ("myfifo", 0600);
	pipe (process1);
    	pipe (process2);
	FILE* fin = fdopen(process1[0], "r");
	FILE* fout = fdopen(process1[1], "w");


	if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockp) < 0) 
	{ 
		printf ("%s\n", "The creation of socketpair was unsuccessful");
		exit(1);
	}

	//creating a new process
	pid_t creation_of_the_process = fork ();

	if (creation_of_the_process < 0)
		printf ("%s\n", "The creation of the child process was unsuccessful");

	if (creation_of_the_process == 0)
	{

	       	fclose (fout);
        	close (process2[0]);
		close (sockp[1]);
		child (sockp[0]);

		printf ("Type in one of the following commands:\n%s\n%s name_of_the_file\n%s name_of_the_file\n%s\n\n", log_in, myfind, mystat, quit);

		while (1)
		{ 	
			process2[1] = open ("myfifo", O_WRONLY);
			memset (message, 0, strlen (message));
			fgets (message, MAX_ARRAY, fin);
                    	message[strlen(message) - 1] = 0;
			
			if (strstr (message, log_in) != NULL)
			{
				memset (result, 0, strlen (result));
				strcpy (message_username, message + 16);
				
				login (result, message_username);
				
				//write in fifo the result
				if (process2[1] >= 0)
				{
					len = strlen(result);
					write (process2[1], &len, sizeof(int));
					write (process2[1], result, len);
				}
				else
					printf ("%s", "Failure while opening for fifo editing\n");
			}
			else
			if (strstr (message, myfind) != NULL)
			{
				memset (result, 0, strlen (result));
				strcpy (myfind_name, message + 7);
				
				if (getcwd (current_path, sizeof (current_path)) != NULL)		
					find_file (current_path, result, myfind_name);
				
				//write in fifo the result
				if (process2[1] >= 0)
				{
					len = strlen(result);
					write (process2[1], &len, sizeof(int));
					write (process2[1], result, len);
				}
				else
					printf ("%s", "Failure while opening for fifo editing\n");
			}
			else
			if (strstr (message, mystat) != NULL)
			{
				memset (result, 0, strlen (result));
				strcpy (mystat_name, message + 7);
				
				stat_file (result, mystat_name);

				//write in fifo the result
				if (process2[1] >= 0)
				{
					len = strlen(result);
					write (process2[1], &len, sizeof(int));
					write (process2[1], result, len);
				}
				else
					printf ("%s", "Failure while opening for fifo editing\n");
			}
			else
			if (strstr (message, quit) != NULL)
			{	
				memset (result, 0, strlen (result));
				
				quit_program (result, message);

				//write in fifo the result
				if (process2[1] >= 0)
				{
					len = strlen(result);
					write (process2[1], &len, sizeof(int));
					write (process2[1], result, len);
				}
				else
                    			printf ("%s", "Failure while opening for fifo editing\n");
                		break;
			}
            		else
            		{
                		memset(result, 0, strlen (result));
                		strcpy (result, "Command not found!\n");
                		
				if (process2[1] >= 0)
                		{
                    			len = strlen(result);
                    			write (process2[1], &len, sizeof(int));
                    			write (process2[1], result, len);
                		}
                		else
                    			printf ("%s", "Failure while opening for fifo editing\n");
                	}
		}
		
		fclose (fin);
		close (process2[1]);
		close (sockp[0]);
	}
	else //returning to the parent process
	{
		fclose(fin);
		close (process2[1]);
		close (sockp[0]);
		parent (sockp[1]);

		while (1)
		{
            		memset (message, 0, strlen (message));
			memset (result, 0, strlen (result));
            		
			fgets (message, MAX_ARRAY, stdin);
			message[strlen(message) - 1] = 0;

           	 	fprintf (fout, "%s\n", message);
            		fflush (fout);

            		process2[0] = open ("myfifo", O_RDONLY);
            		read(process2[0], &len, sizeof(int));
			read(process2[0], result, len);
			result[len]=0;

			if (strcmp (result, "quit") == 0)
				break;

			printf("%s\n", result);
		}

		fclose (fout);
		close (process2[0]);
		wait (NULL);
	}	
	return 0;
}
