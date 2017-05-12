/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

//#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, char *argv[])
{
    // If the user does not have the proper number of agruments they are probided with the program usage
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // converts the second command line arg to an integer
    int n = atoi(argv[1]);

    // if there is a third argument use it to seed drang48()
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    else
    {
        srand48((long) time(NULL));
    }

    // Print n random integers that are with in the predefined limit
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
