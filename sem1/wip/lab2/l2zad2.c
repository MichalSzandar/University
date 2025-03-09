#include<stdio.h>

int main()
{
    double suma = 0;
    int mianownik = 0;

    while(suma<=10)
    {
        mianownik++;
        suma+=1/(double)mianownik;
    }
    printf("%d", mianownik);

    return 0;
}