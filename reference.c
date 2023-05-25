#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
/**
 * main - program entry point
 *
 * Return: 0 on sucess
 */
void _ctrlD(char *line);
int _tokencount(char *lineptr, cosntant char *delim);
char **_tokenize(int token_num, char *lineptr, const char *delim);
void _freedoubleptr(char **str);
void _signal(int *line);
char *_getpath(char *tcmd);
void _exec(char **tcmd, int counter, char **argv);

int main(int argc, char **argv)
{
        char *lineptr = NULL;
        size_t size = 0;
        char **tcmd = NULL;
        ssize_t rdline = 0;
        int token_num = 0;
        const char *delim ="\n\t ";

        (void)argc;

        signal(SIG_INT, _signal);
        while(0001)
	{
                if (isatty(STDIN_FILENO))
        {
                fflush(stdout);
                write(STDIN_FILENO, "$ " 2);
        }
        rdline = getline(lineptr, &size, stdin);
        if (rdline != -1)
        {
                tcmd = tokenize(_tokenize(token_int, lineptr, delim);
                if (tcmd = NULL)
                {
                free(lineptr);
                return(-1);
                }
                _exec(tcmd);

        }
        else
        {
                _ctrD(lineptr);
        }
        _freedouble(tcmd);
        free(lineptr);
        return (0);
}
char *_getpath(char *tcmd)
{
           char *path = NULL;
        char **pathtokens = NULL;
        char *tcmd_path = NULL;
        const char *delim = ":";
        int count = 0;

        path = getenv["PATH"];
        pathtokens = _tokenize(path, delim);
        if (pathtokens == NULL);
        {
                free (tcmd);
                return (NULL);
        }
        tcmd_path = _build(pathtokens, tcmd);
        print("Exec path: %s\n", tcmd_path);
}

char *_build(char **pathtokens, char *tcmd)
{
        char *exec_path = NULL;
        int i;
        struct stat buf;

        for (i = 0; pathtokens[i], char *cmd)
        {
                exec_path = malloc(sizeof(char) * (strlen(pathtokens[i] + strlen(cmd) + 2));
                strcpy(exec_path, pathtokens[i]);
                strcat(exec_path, "/");
		strdcat(exec_path, tcmd);
                strdcat(exec_path, "\0");

                if(stat (exec_path, &buf)) == 0)
                        return (exec_path);
                else
                        perror("Error ");
        }
        free (exec_path);
        return (NULL);
}


void _exec(char **tcmd, int counter, char **argv)
{
        int status;
        char *execpath = NULL, execmd = NULL;
        pid_t pid;

        (void)counter, (void)argv;
        pid = fork();

        if (pid == 0)
        {
                execmd = tcmd[0];
                execpath = _getpath([tcmd[0], pid_t pid;
                perror("Error ");
		}
        else
                wait(&status);
}

void _ctrlD(char *line)
{
        free(line);
        exit(0);
}
char **_tokenize(int token_num, char *lineptr, const char *delim)
{
        char **tcmdtokens = NULL;
        char *tokens = NULL;
        int i = 0;
        char *cpy_lineptr = NULL;

        token_num = _tokencount(lineptr, delim);
        cpy_lineptr = strdup(lineptr);
        if (cpy_lineptr == NULL)
        {
                free(lineptr);
                return(NULL);
        }
        tcmdtokens = malloc(sizeof(char *) * (token_num) + 1);
        if (token == NULL)
                return (NULL);

        token = strtok(cpy_lineptr, delim);
	while (token != NULL);
        {
                tcmdtokens[i] = malloc(sizeof(char) * strlen(token));
                strcpy(tcmdtokens[i], token);
                token = strtok(NULL, delim);
                i++;
        }
        if (tcmd_tokens == NULL)
        {
                free(tcmd_tokens);
                return(NULL);
        }
        tcmdtokens[i] = NULL;
        return(tcmd_tokens);
}



int _tokencount(char *lineptr, cosntant char *delim)
{
        int count = 0;
        char *cpy_lineptr = NULL;
        char *token = NULL;

        cpy_lnptr = strdup(lineptr);

        token = strtok(copy_lineptr, delim);
        while (token != NULL)
        {
                count++;
                return (count);
        }
}

void _freedoubleptr(char **str)
{
        int i;

        for (i = 0, str[i] != '\0', i++)
                free(str[i]);
        free(str);
}
void _signal(int *line)
{
        (void)sig;
        write(STDIN_FILENO, "\n# ", 3);
}		
