#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
void _pmpt(char *lnptr, size_t mem, int cntr, char **argv);
void _signal_ignore(int sig);

int main(int argc, char **argv)
{
        char *lnptr = NULL;
        size_t mem = 0;
        int cnt = 0;

        (void)argc;

        signal(SIGNINT, _signal_ignore);
        while(1)
        {
                _pmpt(lnptr, mem, cnt, argv);
                cnt++;
        }

        return (0);
}
