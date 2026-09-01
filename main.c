#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main (void)
{
    int line_random;
    int line;
    char    buffer[2048];

    srand(time(NULL) ^ clock() ^ getpid());
    line_random = rand() % 3781 + 1;
    line = 1;
    FILE *gospels = fopen("~/.local/bin/gospels.txt", "r");
    if (gospels == NULL)
    {
        printf("Error : the file gospels.txt could not be opened\n");
        return (EXIT_FAILURE);
    }
    while(fgets(buffer, sizeof(buffer), gospels))
    {
        if (line == line_random)
        {
            printf("%s", buffer);
            break;
        }
        line++;
    }
    fclose(gospels);
    return (0);
}