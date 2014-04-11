/*
 * =====================================================================================
 *
 *       Filename:  hash.c
 *
 *    Description:  
 *
 *        Version:  0.1
 *        Created:  03/21/14 11:09:01
 *       Revision:  none
 *       Compiler:  Clang
 *
 *         Author:  Matthew Pherigo (mwp), hybrid120@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char* pass;
    do {    
    pass = getpass("Give me a password: ");
    } while(pass == NULL);

    unsigned long long seed;
    FILE *f;

    f = fopen("/dev/random", "r");
    fread(&seed, sizeof(seed), 1, f);
    fclose(f);

    char* sseed = malloc(1024 * sizeof(char));
    sprintf(sseed, "$2b$%llu", seed);

    char* enc = crypt(pass, sseed);
    printf("\n%s\n", enc);
}
