#include<stdio.h>

int sumaDzielnikow(int n)
{
    int sum = 0;
    for (int i = 1; i <= n/2; i++)
        if(n%i==0)
            sum+=i;
    
    return sum;
    
}

int main()
{
    printf("liczby doskonale mniejsze od 1000: \n");

    for (int i = 1; i < 1000; i++)
    {
        if(sumaDzielnikow(i) == i)
        {
            printf("%d\n", i);
        }
    }

    printf("liczby zaprzyjaznione mniejsze od 1000: \n");

    for (int i = 1; i < 1000; i++)
    {
        int n = sumaDzielnikow(i);
        if (sumaDzielnikow(n) == i && n < i)
        {
            printf("%d ", i);
            printf("%d\n", sumaDzielnikow(i));
        }
        
    } 
    
    return 0;
}