#include<stdio.h>

int miesiace[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int czyPrzestepny(int rok)
{
    return ((rok%4==0 && rok%100!=0) || rok%400==0);
}

int dniOdPoczatkuEry(int dzien, int miesiac, int rok)
{
    int dni = 0;
    for (int i = 1; i < rok; i++)
    {
        if(czyPrzestepny(i))
            dni+=366;
        else
            dni+=365;
    }
    
    if(czyPrzestepny(rok))
        miesiace[1] = 29;

    for (int i = 1; i < miesiac; i++)
    {
        dni += miesiace[i-1];
    }

    dni+=dzien;   
    return dni-1; 
}

int main()
{
    int rok, miesiac, dzien;

    printf("podaj dzisiejsza date: ");
    scanf("%d %d %d", &dzien , &miesiac, &rok);
    printf("%d", dniOdPoczatkuEry(dzien, miesiac, rok));
    printf("\n");

    int rokUr, miesiacUr, dzienUr, dniOdUr;
    long long sekundyOdUr;
    printf("podaj date urodzin: ");
    scanf("%d %d %d", &dzienUr , &miesiacUr, &rokUr);
    dniOdUr = dniOdPoczatkuEry(dzien, miesiac, rok) - dniOdPoczatkuEry(dzienUr, miesiacUr, rokUr);
    sekundyOdUr = dniOdUr*24*60*60;
    printf("%d\n", dniOdUr);
    printf("%d", sekundyOdUr);
    
    return 0;
}