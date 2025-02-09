#include <stdio.h>

int main()
{
    float input;
    scanf("%f", &input);
    if (input <= 25 && input >= 0)
    {
        printf("Intervalo [0,25]\n");
    }
    else if (input <= 50 && input > 0)
    {
        printf("Intervalo (25,50]\n");
    }
    else if (input <= 75 && input > 0)
    {
        printf("Intervalo (50,75]\n");
    }
    else if (input <= 100 && input > 0)
    {
        printf("Intervalo (75,100]\n");
    }
    else
    {
        printf("Fora de intervalo\n");
    }
    return 0;
}