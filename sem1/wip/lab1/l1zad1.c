#include<stdio.h>

int main()
{
    char napis[] = "ABRAKADABRA";

    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        
        for (int j = 0; j < 11-i; j++)
        {
            printf("%c ",napis[j]);
        }
        printf("\n");
    }
    

    return 0;
}