#include "funs.h"
#include<stdio.h>

int palindrom(char napis[])
{
    int n = sizeof(napis);

    for (int i = 0; i < n/2 - 1; i++)
        if(napis[i] != napis[n-1-i] )
            return 0;
    
    return 1;
}