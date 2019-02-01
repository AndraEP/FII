#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>

#define PORT 2024
#define max 10000

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

extern int errno;
sqlite3* db;

static int callback_insert (void *str, int argc, char **argv, char **azColName)
{
    int i;
    char* data = (char*) str;

    for (i = 0; i < argc; i++)
    {
        if (argv[i])
            strcat (data, argv[i]);
        else
            strcat (data, "NULL");
    }
    return 0;
}

static int callback (void *str, int argc, char **argv, char **azColName)
{
    int i;
    char* data = (char*) str;

    for (i = 0; i < argc; i++)
    {
        strcat (data, azColName[i]);
        strcat (data, " = ");
        if (argv[i])
            strcat (data, argv[i]);
        else
            strcat (data, "NULL");
        strcat (data, "\n");
    }

    strcat (data, "\n");
    return 0;
}

int main (int argc, char* argv[])
{
    char msgin[max];		//mesajul primit de la client
    char msgout[max];       //mesaj de raspuns pentru client

    //no login required 
    char log_in_user[] = "login user ";
    char log_in_admin[] = "login admin ";
    char register_user[] = "register user ";
    char register_admin[] = "register admin ";
    char quit[] = "quit";
    char commands[] = "commands";

    //admin commands
    char view_users[] = "see users";
    char view_admins[] = "see admins";
    char restrict_user[] = "restricted ";
    char unrestrict_user[] = "unrestrict ";
    char delete_song[] = "delete song ";
    char delete_comment[] = "delete comment ";

    //user commands
    char comment[] = "comment ";
    char vote[] = "vote ";
    char top[] = "see top";
    char genre[] = "see top ";

    //admin + user commands
    char insertion[] = "insert ";
    char view_music[] = "see music";
    char view_com[] = "see comments";
    char view_genre[] = "see genre";

    char message[max], result[max], type[max], username[max], genre_name[max], to_add[max], song_id[max], text[max], comment_id[max];

    //database
    char* zErrMsg;
    char str[max];
    char sql[max];
    int rc = sqlite3_open ("TopMusic.db", &db);  //stabilire conexiune baza date

    if (rc)	                                    //verificare conexiune
    {
        fprintf(stderr, "error: %s\n", sqlite3_errmsg (db));
        return 0;
    }

    //server + client
    int sd;						                        //descriptor de socket

    if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)	//creare socket
    {
        perror ("[server]Eroare la socket ().\n");
        return errno;
    }

    struct sockaddr_in server;			       	        //structura folosita de server
    server.sin_family = AF_INET;		              	//stabilirea familiei de socket-uri
    server.sin_addr.s_addr = htonl (INADDR_ANY);	    //acceptam orice adresa
    server.sin_port = htons (PORT);			            //utilizam un port utilizator

    if (bind (sd, (struct sockaddr *) &server, sizeof (struct sockaddr)) == -1)	//atasare socket
    {
        perror ("[server]Eroare la bind ().\n");
        return errno;
    }

    if (listen (sd, 5) == -1)	//punem serverul sa asculte daca vin clienti sa se conecteze
    {
        perror ("[server]Eroare la listen ().\n");
        return errno;
    }

    fflush (stdout);
    printf ("[server]Waiting at port: %d...\n\n",PORT);

    while (1)
    {
        int client = accept (sd, NULL, NULL); 	//acceptam un client (stare blocanta pina la realizarea conexiunii)

        if (client < 0) 		              	//eroare la acceptarea conexiunii de la un client
        {
            perror ("[server]Eroare la accept().\n");
            continue;
        }

        //start children
        if (fork () == 0)
        {
            int ok_admin = 0;
            int ok_user = 0;
            int closing = 0;

            while (1)
            {
                //reading the message
                fflush (stdout);
                memset (msgin, 0, sizeof (msgin));
                memset (msgout, 0, sizeof (msgout));
                memset (message, 0, sizeof (message));

                if (read (client, msgin, sizeof (msgin)) <= 0)	//citire mesaj
                {
                    perror ("[server]Eroare la read () de la client.\n");
                    close (client);	// inchidem conexiunea cu clientul
                    continue;		// continuam sa ascultam
                }

                printf ("[server]Message received...\n");
                printf (ANSI_COLOR_YELLOW "%s\n" ANSI_COLOR_RESET, msgin);

                strcpy (message, msgin);

                //COMMANDS
                //no login required
                //login user
                if (strstr (message, log_in_user) != NULL)
                {
                    memset (result, 0, sizeof (result));
                    memset (type, 0, strlen (type));
                    memset (username, 0, strlen (username));

                    strcpy (username, message + 11);
                    strcpy (type, "user");
                    sql[0] = 0;
                    str[0] = 0;

                    sprintf (sql, "SELECT * FROM users WHERE name = '%s';", username);
                    rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                    if (rc != SQLITE_OK)
                    {
                        sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                        sqlite3_free (zErrMsg);
                    }
                    else if (strstr (str, username))
                    {
                        //printf ("%s", str);
                        sprintf (result, ANSI_COLOR_GREEN "Welcome user %s.\n" ANSI_COLOR_RESET, username);
                        ok_user = 1;
                        ok_admin = 0;
                    }
                    else strcpy (result, ANSI_COLOR_RED "Name does not exists! Try again or register.\n" ANSI_COLOR_RESET);
                }

                // login admin
                else if (strstr (message, log_in_admin) != NULL)
                {
                    memset (result, 0, sizeof (result));
                    memset (type, 0, strlen (type));
                    memset (username, 0, strlen (username));

                    strcpy (username, message + 12);
                    strcpy (type, "admin");
                    sql[0] = 0;
                    str[0] = 0;

                    sprintf (sql, "SELECT * FROM admins WHERE name = '%s';", username);
                    rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                    if (rc != SQLITE_OK)
                    {
                        sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                        sqlite3_free (zErrMsg);
                    }
                    else if (strstr (str, username))
                    {
                        //printf ("%s", str);
                        sprintf (result, ANSI_COLOR_GREEN "Welcome admin %s.\n" ANSI_COLOR_RESET, username);
                        ok_admin = 1;
                        ok_user = 0;
                    }
                    else strcpy (result, ANSI_COLOR_RED "Name does not exists! Try again or register.\n" ANSI_COLOR_RESET);
                }

                //register user
                else if (strstr (message, register_user) != NULL)
                {
                    memset (result, 0, sizeof (result));
                    memset (username, 0, strlen (username));

                    strcpy (username, message + 14);
                    sql[0] = 0;
                    str[0] = 0;

                    sprintf (sql, "SELECT * FROM users WHERE name = '%s';", username);
                    rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                    if (rc != SQLITE_OK)
                    {
                        sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                        sqlite3_free (zErrMsg);
                    }
                    else if (strstr (str, username))
                    {
                        strcpy (result, ANSI_COLOR_RED "Name already exists! Try another name or log in.\n" ANSI_COLOR_RESET);
                    }
                    else
                    {
                        sprintf (sql, "INSERT INTO users (name, restrict) VALUES ('%s', 1);", username);
                        rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                        if (rc != SQLITE_OK)
                        {
                            sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                            sqlite3_free (zErrMsg);
                        }
                        else
                        {
                            str[0] = 0;
                            sprintf (sql, "SELECT * FROM users;");
                            rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                            if (rc != SQLITE_OK)
                            {
                                sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                                sqlite3_free (zErrMsg);
                            }
                            else
                            {
                                //printf ("%s", str);
                                sprintf (result, ANSI_COLOR_GREEN "Done.\n" ANSI_COLOR_RESET);
                            }
                        }
                    }
                }

                //register admin
                else if (strstr (message, register_admin) != NULL)
                {
                    memset (result, 0, sizeof (result));
                    memset (username, 0, strlen (username));

                    strcpy (username, message + 15);
                    sql[0] = 0;
                    str[0] = 0;

                    sprintf (sql, "SELECT * FROM admins WHERE name = '%s';", username);
                    rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                    if (rc != SQLITE_OK)
                    {
                        sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                        sqlite3_free (zErrMsg);
                    }
                    else if (strstr (str, username))
                    {
                        strcpy (result, ANSI_COLOR_RED "Name already exists! Try another name or log in.\n" ANSI_COLOR_RESET);
                    }
                    else
                    {
                        sprintf (sql, "INSERT INTO admins (name) VALUES ('%s');", username);
                        rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                        if (rc != SQLITE_OK)
                        {
                            sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                            sqlite3_free (zErrMsg);
                        }
                        else
                        {
                            str[0] = 0;
                            sprintf (sql, "SELECT * FROM admins;");
                            rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                            if (rc != SQLITE_OK)
                            {
                                sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                                sqlite3_free (zErrMsg);
                            }
                            else
                            {
                                //printf ("%s", str);
                                sprintf (result, ANSI_COLOR_GREEN "Done.\n" ANSI_COLOR_RESET);
                            }
                        }
                    }
                }

                //quit
                else if (strcmp (message, quit) == 0)
                {
                    memset (result, 0, sizeof (result));
                    strcpy (result, "Quitting...");
                    closing = 1;
                }

                //see commands
                else if (strcmp (message, commands) == 0)
                {
                    memset (result, 0, sizeof (result));
                    strcpy (result, ANSI_COLOR_CYAN "\nType in one of the following:\n\nlogin user user_name..........Logs you in as an user\nlogin admin admin_name........Logs you in as an admin\nregister user user_name.......Registers you as an user\nregister admin admin_name.....Registers you as an admin\nquit..........................Quits you from the program\ncommands......................Helps you see the available commands\nsee users.....................Admin ONLY: Helps you see the users table\nsee admins....................Admin ONLY: Helps you see the admins table\nrestricted user_name..........Admin ONLY: Restricts an user from voting\nunrestrict user_name..........Admin ONLY: Unrestricts an user from voting\ndelete song song_id...........Admin ONLY: Deletes a song\ndelete comment comment_id.....Admin ONLY: Deletes a comment\ncomment song_id comment_add...User ONLY: Helps you add a comment to a song\nvote song_id..................User ONLY: Helps you vote a song\nsee top.......................User ONLY: Helps you see the general top\nsee top genre_name............User ONLY: Helps you see a genre's top\ninsert song_name,\n  song_description song_link\n       song_genre.............Helps an admin/user add a new song\nsee music.....................Helps an admin/user see the music table\nsee comments..................Helps an admin/user see the comments table\nsee genre.....................Helps an admin/user see the genre table\n" ANSI_COLOR_RESET);
                }

                //admin only
                //view users
                else if (strcmp (type, "admin") == 0 && strcmp (message, view_users) == 0 && ok_admin == 1)
                {
                    memset (result, 0, sizeof (result));

                    sql[0] = 0;
                    str[0] = 0;

                    sprintf (sql, "SELECT * FROM users;");
                    rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                    if (rc != SQLITE_OK)
                    {
                        sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                        sqlite3_free (zErrMsg);
                    }
                    else
                    {
                        str[strlen (str) - 1] = 0;
                        sprintf (result, ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, str);
                    }
                }

                //view admins
                else if (strcmp (type, "admin") == 0 && strcmp (message, view_admins) == 0 && ok_admin == 1)
                {
                    memset (result, 0, sizeof (result));

                    sql[0] = 0;
                    str[0] = 0;

                    sprintf (sql, "SELECT * FROM admins;");
                    rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                    if (rc != SQLITE_OK)
                    {
                        sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                        sqlite3_free (zErrMsg);
                    }
                    else
                    {
                        str[strlen (str) - 1] = 0;
                        sprintf (result, ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, str);
                    }
                }

                //restrict
                else if (strcmp (type, "admin") == 0 && strstr (message, restrict_user) != NULL && ok_admin == 1)
                {
                    memset (result, 0, sizeof (result));
                    memset (username, 0, sizeof (username));

                    strcpy (username, message + 11);
                    sql[0] = 0;
                    str[0] = 0;

                    sprintf (sql, "SELECT * FROM users WHERE name = '%s';", username);
                    rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                    if (rc != SQLITE_OK)
                    {
                        sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                        sqlite3_free (zErrMsg);
                    }
                    else if (strstr (str, username))
                    {
                        //printf ("Before restrict:\n%s", str);
                        sprintf (sql, "UPDATE users SET restrict = -1 WHERE name = '%s';", username);
                        rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                        if (rc != SQLITE_OK)
                        {
                            sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                            sqlite3_free (zErrMsg);
                        }
                        else
                        {
                            str[0] = 0;
                            sprintf (sql, "SELECT * FROM users WHERE name = '%s';", username);
                            rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                            if (rc != SQLITE_OK)
                            {
                                sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                                sqlite3_free (zErrMsg);
                            }
                            else
                            {
                                //printf ("After restrict:\n%s", str);
                                sprintf (result, ANSI_COLOR_GREEN "Done.\n" ANSI_COLOR_RESET);
                            }
                        }
                    }
                    else sprintf (result, ANSI_COLOR_RED "User name does not exist!\n" ANSI_COLOR_RESET);
                }

                //unrestrict
                else if (strcmp (type, "admin") == 0 && strstr (message, unrestrict_user) != NULL && ok_admin == 1)
                {
                    memset (result, 0, sizeof (result));
                    memset (username, 0, sizeof (username));

                    strcpy (username, message + 11);
                    sql[0] = 0;
                    str[0] = 0;

                    sprintf (sql, "SELECT * FROM users WHERE name = '%s';", username);
                    rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                    if (rc != SQLITE_OK)
                    {
                        sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                        sqlite3_free (zErrMsg);
                    }
                    else if (strstr (str, username))
                    {
                        //printf ("Before unrestrict:\n%s", str);
                        sprintf (sql, "UPDATE users SET restrict = 1 WHERE name = '%s';", username);
                        rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                        if (rc != SQLITE_OK)
                        {
                            sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                            sqlite3_free (zErrMsg);
                        }
                        else
                        {
                            str[0] = 0;
                            sprintf (sql, "SELECT * FROM users WHERE name = '%s';", username);
                            rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                            if (rc != SQLITE_OK)
                            {
                                sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                                sqlite3_free (zErrMsg);
                            }
                            else
                            {
                                //printf ("After unrestrict:\n%s", str);
                                sprintf (result, ANSI_COLOR_GREEN "Done.\n" ANSI_COLOR_RESET);
                            }
                        }
                    }
                    else sprintf (result, ANSI_COLOR_RED "User name does not exist!\n" ANSI_COLOR_RESET);
                }

                //delete song
                else if (strcmp (type, "admin") == 0 && strstr (message, delete_song) != NULL && ok_admin == 1)
                {
                    memset (result, 0, sizeof (result));
                    memset (song_id, 0, strlen (song_id));

                    strcpy (song_id, message + 12);
                    sql[0] = 0;
                    str[0] = 0;

                    sprintf (sql, "SELECT * FROM music WHERE id_song = %s;", song_id);
                    rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                    if (rc != SQLITE_OK)
                    {
                        sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                        sqlite3_free (zErrMsg);
                    }
                    else if (strstr (str, song_id))
                    {
                        //printf ("Music before delete:\n%s", str);
                        sprintf (sql, "DELETE FROM comments WHERE id_song = %s;", song_id);
                        rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                        if (rc != SQLITE_OK)
                        {
                            sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                            sqlite3_free (zErrMsg);
                        }
                        else
                        {
                            sprintf (sql, "DELETE FROM music WHERE id_song = %s;", song_id);
                            rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                            if (rc != SQLITE_OK)
                            {
                                sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                                sqlite3_free (zErrMsg);
                            }
                            else
                            {
                                sprintf (sql, "DELETE FROM genre WHERE id_song = %s;", song_id);
                                rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                                if (rc != SQLITE_OK)
                                {
                                    sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                                    sqlite3_free (zErrMsg);
                                }
                                else
                                {
                                    str[0] = 0;
                                    sprintf (sql, "SELECT * FROM music;");
                                    rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                                    if (rc != SQLITE_OK)
                                    {
                                        sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                                        sqlite3_free (zErrMsg);
                                    }
                                    else
                                    {
                                        //printf ("Music after delete:\n%s", str);
                                        str[0] = 0;
                                        sprintf (sql, "SELECT * FROM comments;");
                                        rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                                        if (rc != SQLITE_OK)
                                        {
                                            sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                                            sqlite3_free (zErrMsg);
                                        }
                                        else
                                        {
                                            //printf ("Comments after delete:\n%s", str);
                                            str[0] = 0;
                                            sprintf (sql, "SELECT * FROM genre;");
                                            rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                                            if (rc != SQLITE_OK)
                                            {
                                                sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                                                sqlite3_free (zErrMsg);
                                            }
                                            else
                                            {
                                                //printf ("Genre after delete:\n%s", str);
                                                sprintf (result, ANSI_COLOR_GREEN "Done.\n" ANSI_COLOR_RESET);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else sprintf (result, ANSI_COLOR_RED "This song does not exist!\n" ANSI_COLOR_RESET);
                }

                //delete comments
                else if (strcmp (type, "admin") == 0 && strstr (message, delete_comment) != NULL && ok_admin == 1)
                {
                    memset (result, 0, sizeof (result));
                    memset (comment_id, 0, strlen (comment_id));

                    strcpy (comment_id, message + 15);
                    sql[0] = 0;
                    str[0] = 0;

                    sprintf (sql, "SELECT * FROM comments WHERE id_com = %s;", comment_id);
                    rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                    if (rc != SQLITE_OK)
                    {
                        sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                        sqlite3_free (zErrMsg);
                    }
                    else if (strstr (str, comment_id))
                    {
                        sprintf (sql, "DELETE FROM comments WHERE id_com = %s;", comment_id);
                        rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                        if (rc != SQLITE_OK)
                        {
                            sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                            sqlite3_free (zErrMsg);
                        }
                        else sprintf (result, ANSI_COLOR_GREEN "Done.\n" ANSI_COLOR_RESET);
                    }
                    else sprintf (result, ANSI_COLOR_RED "This comment does not exist!\n" ANSI_COLOR_RESET);
                }

                //user only
                //add comment
                else if (strcmp (type, "user") == 0 && strstr (message, comment) != NULL && ok_user == 1)
                {
                    memset (result, 0, sizeof (result));
                    memset (text, 0, sizeof (text));
                    memset (to_add, 0, sizeof (to_add));
                    memset (song_id, 0, sizeof (song_id));

                    strcpy (text, message + 8);
                    char *p = strchr (text, ' ');
                    strcpy (to_add, p+1);
                    *p = 0;
                    strcpy (song_id, text);

                    sql[0] = 0;
                    str[0] = 0;

                    sprintf (sql, "SELECT * FROM music WHERE id_song = %s;", song_id);
                    rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                    if (rc != SQLITE_OK)
                    {
                        sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                        sqlite3_free (zErrMsg);
                    }
                    else if (strstr (str, song_id))
                    {
                        sprintf (sql, "INSERT INTO comments (id_song, comment) VALUES (%s, '%s');", song_id, to_add);
                        rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                        if (rc != SQLITE_OK)
                        {
                            sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                            sqlite3_free (zErrMsg);
                        }
                        else
                        {
                            str[0] = 0;
                            sprintf (sql, "SELECT * FROM comments;");
                            rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                            if (rc != SQLITE_OK)
                            {
                                sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                                sqlite3_free (zErrMsg);
                            }
                            else
                            {
                                //printf ("%s", str);
                                sprintf (result, ANSI_COLOR_GREEN "Done.\n" ANSI_COLOR_RESET);
                            }
                        }
                    }
                    else sprintf (result, ANSI_COLOR_RED "This song does not exist!\n" ANSI_COLOR_RESET);
                }

                //vote
                else if (strcmp (type, "user") == 0 && strstr (message, vote) != NULL && ok_user == 1)
                {
                    memset (song_id, 0, sizeof (song_id));
                    memset (result, 0, sizeof (result));

                    strcpy (song_id, message + 5);
                    sql[0] = 0;
                    str[0] = 0;

                    sprintf (sql, "SELECT * FROM users WHERE restrict = -1;");
                    rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                    if (rc != SQLITE_OK)
                    {
                        sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                        sqlite3_free (zErrMsg);
                    }
                    else if (strstr (str, username))
                    {
                        sprintf (result, ANSI_COLOR_RED "You have been restricted from voting.\n" ANSI_COLOR_RESET);
                    }
                    else
                    {
                        sprintf (sql, "SELECT * FROM music WHERE id_song = %s;", song_id);
                        rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                        if (rc != SQLITE_OK)
                        {
                            sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                            sqlite3_free (zErrMsg);
                        }
                        else if (strstr (str, song_id))
                        {
                            sprintf (sql, "UPDATE music SET votes = votes + 1 WHERE id_song = %s;", song_id);
                            rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                            if (rc != SQLITE_OK)
                            {
                                sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                                sqlite3_free (zErrMsg);
                            }
                            else
                            {
                                str[0] = 0;
                                sprintf (sql, "SELECT * FROM music;");
                                rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                                if (rc != SQLITE_OK)
                                {
                                    sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                                    sqlite3_free (zErrMsg);
                                }
                                else
                                {
                                    //printf ("After vote:\n%s", str);
                                    sprintf (result, ANSI_COLOR_GREEN "Done.\n" ANSI_COLOR_RESET);
                                }
                            }
                        }
                        else sprintf (result, ANSI_COLOR_RED "This song does not exist!\n" ANSI_COLOR_RESET);
                    }
                }

                //see top
                else if (strcmp (type, "user") == 0 && strcmp (message, top) == 0 && ok_user == 1)
                {
                    memset (result, 0, sizeof (result));

                    sql[0] = 0;
                    str[0] = 0;

                    sprintf (sql, "SELECT * FROM music WHERE votes != 0 ORDER BY votes DESC;");
                    rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                    if (rc != SQLITE_OK)
                    {
                        sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                        sqlite3_free (zErrMsg);
                    }
                    else
                    {
                        str[strlen (str) - 1] = 0;
                        sprintf (result, ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, str);
                    }
                }

                //see top by genre
                else if (strcmp (type, "user") == 0 && strstr (message, genre) != NULL && ok_user == 1)
                {
                    memset (genre_name, 0, sizeof (genre_name));
                    memset (result, 0, sizeof (result));

                    strcpy (genre_name, message + 8);
                    sql[0] = 0;
                    str[0] = 0;

                    sprintf (sql, "SELECT * FROM genre WHERE genre = '%s';", genre_name);
                    rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                    if (rc != SQLITE_OK)
                    {
                        sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                        sqlite3_free (zErrMsg);
                    }
                    else if (strstr (str, genre_name))
                    {
                        str[0] = 0;
                        sprintf (sql, "SELECT * FROM music WHERE id_song IN (SELECT id_song FROM genre WHERE genre = '%s') AND votes != 0 ORDER BY votes DESC;", genre_name);
                        rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                        if (rc != SQLITE_OK)
                        {
                            sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                            sqlite3_free (zErrMsg);
                        }
                        else
                        {
                            str[strlen (str) - 1] = 0;
                            sprintf (result, ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, str);
                        }
                    }
                    else sprintf (result, ANSI_COLOR_RED "This genre does not exist.\n" ANSI_COLOR_RESET);
                }

                //both admins and users
		        //insert song
                else if ((strcmp (type, "admin") == 0 || strcmp(type, "user") == 0) && strstr (message, insertion) == 0 && (ok_admin == 1 || ok_user == 1))
                {
                    char insert [5][max];
                    int commands = 0;
                    char *p = strtok (message, " ");

                    memset (insert, 0, sizeof (insert));
                    memset (result, 0, sizeof (result));
                    memset (song_id, 0, sizeof (song_id));

                    sql[0] = 0;
                    str[0] = 0;
                    
                    while (p != NULL)
                    {
                        strcpy (insert[commands], p);
                        commands ++;

                        if (commands > 5)
                        {
                            break;
                        }
                        p = strtok (NULL, " ");
                    }

                    if (commands != 5)
                        sprintf (result, ANSI_COLOR_RED "Invalid number of parameters.\n" ANSI_COLOR_RESET);
                    else
                    {
                        sprintf (sql, "SELECT * FROM music WHERE name = '%s';", insert[1]);
                        rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                        if (rc != SQLITE_OK)
                        {
                            sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                            sqlite3_free (zErrMsg);
                        }
                        else if (strstr (str, insert[1]))
                        {
                            sprintf (result, ANSI_COLOR_RED "This song name already exists.\n" ANSI_COLOR_RESET);
                        }
                        else
                        {
                            sprintf (sql, "INSERT INTO music (name, description, link, votes) VALUES ('%s', '%s', '%s', 0);", insert[1], insert[2], insert[3]);
                            rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                            if (rc != SQLITE_OK)
                            {
                                sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                                sqlite3_free (zErrMsg);
                            }
                            else
                            {
                                str[0] = 0;
                                sprintf (sql, "SELECT id_song FROM music WHERE name = '%s';", insert[1]);
                                rc = sqlite3_exec (db, sql, callback_insert, str, &zErrMsg);

                                if (rc != SQLITE_OK)
                                {
                                    sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                                    sqlite3_free (zErrMsg);
                                }
                                else
                                {
                                    strcpy (song_id, str);
                                    sprintf (sql, "INSERT INTO genre (id_song, genre) VALUES (%s, '%s');", song_id, insert[4]);
                                    rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                                    if (rc != SQLITE_OK)
                                    {
                                        sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                                        sqlite3_free (zErrMsg);
                                    }
                                    else sprintf (result, ANSI_COLOR_GREEN "Done!\n" ANSI_COLOR_RESET);
                                }
                            }
                        }
                    }
                }

                //view music
                else if ((strcmp (type, "admin") == 0 || strcmp(type, "user") == 0) && strcmp (message, view_music) == 0 && (ok_admin == 1 || ok_user == 1))
                {
                    memset (result, 0, sizeof (result));

                    sql[0] = 0;
                    str[0] = 0;

                    sprintf (sql, "SELECT * FROM music;");
                    rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                    if (rc != SQLITE_OK)
                    {
                        sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                        sqlite3_free (zErrMsg);
                    }
                    else
                    {
                        str[strlen (str) - 1] = 0;
                        sprintf (result, ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, str);
                    }
                }

                //view comments
                else if ((strcmp (type, "admin") == 0 || strcmp(type, "user") == 0) && strcmp (message, view_com) == 0 && (ok_admin == 1 || ok_user == 1))
                {
                    memset (result, 0, sizeof (result));

                    sql[0] = 0;
                    str[0] = 0;

                    sprintf (sql, "SELECT * FROM comments;");
                    rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                    if (rc != SQLITE_OK)
                    {
                        sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                        sqlite3_free (zErrMsg);
                    }
                    else
                    {
                        str[strlen (str) - 1] = 0;
                        sprintf (result, ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, str);
                    }
                }

                //view genre
                else if ((strcmp (type, "admin") == 0 || strcmp(type, "user") == 0) && strcmp (message, view_genre) == 0 && (ok_admin == 1 || ok_user == 1))
                {
                    memset (result, 0, sizeof (result));

                    sql[0] = 0;
                    str[0] = 0;

                    sprintf (sql, "SELECT * FROM genre;");
                    rc = sqlite3_exec (db, sql, callback, str, &zErrMsg);

                    if (rc != SQLITE_OK)
                    {
                        sprintf (result, ANSI_COLOR_YELLOW "SQL error: %s\n" ANSI_COLOR_RESET, zErrMsg);
                        sqlite3_free (zErrMsg);
                    }
                    else
                    {
                        str[strlen (str) - 1] = 0;
                        sprintf (result, ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, str);
                    }
                }

                //error message
                else
                {
                    memset (result, 0, sizeof (result));

                    strcpy (result, ANSI_COLOR_RED "Wrong command!\n" ANSI_COLOR_RESET);
                    strcat (result, ANSI_COLOR_YELLOW "You either typed in a wrong command, or you are not an user/admin. Try again!\n" ANSI_COLOR_RESET);
                }

                //sending the message back
                strcpy (msgout, result);
                int len_msgout = strlen (msgout);
                printf("[server]Sending the message back...\n");
                printf ("%s", msgout);

                if (write (client, msgout, len_msgout) <= 0)	//returnam mesajul clientului si continuam sa ascultam
                {
                    perror ("[server]Eroare la write() catre client.\n");
                    continue;
                }
                else printf ("[server]Message sent successfully.\n\n");

                if (closing == 1)	//inchidere conexiune cu client
                {
                    close (client);
                    break;
                }
            }
            exit(0);
        }
        else continue;
    }
    sqlite3_close(db); //inchidere baza de date
}
