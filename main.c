#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define DATA_REL_PATH "/.local/share/gospels-terminal/gospels.txt"

/* Compte les lignes non vides du fichier */
static int count_lines(FILE *file)
{
    char buffer[2048];
    int  count = 0;

    while (fgets(buffer, sizeof(buffer), file))
    {
        if (buffer[0] != '\n' && buffer[0] != '\0')
            count++;
    }
    return (count);
}

int main(void)
{
    const char *home;
    char        path[4096];
    char        buffer[2048];
    FILE       *gospels;
    int         total;
    int         line_random;
    int         line;

    home = getenv("HOME");
    if (home == NULL)
    {
        fprintf(stderr, "Error : HOME is not set\n");
        return (EXIT_FAILURE);
    }
    snprintf(path, sizeof(path), "%s%s", home, DATA_REL_PATH);

    gospels = fopen(path, "r");
    if (gospels == NULL)
    {
        fprintf(stderr, "Error : the file %s could not be opened\n", path);
        return (EXIT_FAILURE);
    }

    total = count_lines(gospels);
    if (total == 0)
    {
        fprintf(stderr, "Error : the file %s is empty\n", path);
        fclose(gospels);
        return (EXIT_FAILURE);
    }

    srand(time(NULL) ^ clock() ^ getpid());
    line_random = rand() % total + 1;

    rewind(gospels);
    line = 0;
    while (fgets(buffer, sizeof(buffer), gospels))
    {
        if (buffer[0] == '\n' || buffer[0] == '\0')
            continue;
        line++;
        if (line == line_random)
        {
            printf("%s", buffer);
            if (buffer[strlen(buffer) - 1] != '\n')
                printf("\n");
            break;
        }
    }
    fclose(gospels);
    return (EXIT_SUCCESS);
}
