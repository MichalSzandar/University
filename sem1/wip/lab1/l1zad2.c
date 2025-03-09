#include<stdio.h>
#include<math.h>

int main()
{
    double a, b, c, delta, x1, x2;
    scanf("%lf" , &a);
    scanf("%lf" , &b);
    scanf("%lf" , &c);
    delta = pow(b, 2) - (4*a*c);
    if(delta<0)
        printf("brak rozwiazan w zbiorze liczb rzeczywistych");
    else if(delta == 0)
    {
        x1 = -b/(2*a);
        printf("%d", x1);
    }
    else if (delta > 0)
    {
        x1 = (-b - sqrt(delta))/(2*a);
        x2 = (-b + sqrt(delta))/(2*a);
        printf("%lf \n", x1);
        printf("%lf \n", x2);
    }
    

    return 0;
}