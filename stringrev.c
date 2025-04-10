#include <stdio.h>
#include <stdint.h>

#define STR_MAX_SZ  512

size_t stringLen(const char* str)
{
    if(str == NULL) return 0;
    size_t len = 0;
    for(const char* s = str; *s != 0; ++s) ++len;
    return len;
}

int main(void)
{
    char str[512] = {0};
    printf("Enter String: ");

    /*
    https://en.cppreference.com/w/c/io/fgets

    char* fgets( char* restrict str, int count, FILE* restrict stream );

    str 	- 	pointer to an element of a char array
    count 	- 	maximum number of characters to write (typically the length of str)
    tream 	- 	file stream to read the data from 
    */
    fgets(str, STR_MAX_SZ - 1, stdin); // STR_MAX_SZ - 1 to accomodate '\n' (0xa)
    if(ferror(stdin))
    {
        printf("reading from stdin failed\n");
        return 1;
    }

    size_t len = stringLen(str);
    str[--len] = 0; //removing trailing '\n' (0xa) byte

    
    for(size_t i = 0, j = len - 1; i < j; ++i, --j)
    {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }

    printf("Reversed String: %s\n", str);

}
