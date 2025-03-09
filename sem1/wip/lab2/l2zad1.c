#include<stdio.h>

int main()
{
    int rok;
    scanf("%d", &rok);

    if((rok%4==0 && rok%100!=0) || rok%400==0) 
    {
		printf("rok ");
        printf("%d", rok);
        printf(" jest przestepny");
    }
	else
    {
        printf("rok ");
        printf("%d", rok);
        printf(" jest zwykly");
    }
	
    return 0;
}