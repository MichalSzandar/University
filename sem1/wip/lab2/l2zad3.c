#include<stdio.h>
#include<math.h>

int main()
{
    double wynik = 1;
    for (double i = 1; i <= 1000; i++)
    {
        wynik*=pow(i, 0.001);
    }
    
    printf("%lf", wynik);

    return 0;
}