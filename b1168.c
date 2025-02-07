#include <stdio.h>

int main()
{
    int leds, n;
    char input[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        leds = 0;
        scanf("%s", input);
        {
            for (int j = 0; input[j] != '\0'; j++)
            {
                switch (input[j])
                {
                case '0':
                    leds += 6;
                    break;
                case '1':
                    leds += 2;
                    break;
                case '2':
                    leds += 5;
                    break;
                case '3':
                    leds += 5;
                    break;
                case '4':
                    leds += 4;
                    break;
                case '5':
                    leds += 5;
                    break;
                case '6':
                    leds += 6;
                    break;
                case '7':
                    leds += 3;
                    break;
                case '8':
                    leds += 7;
                    break;
                case '9':
                    leds += 6;
                    break;
                }
            }
        }
        printf("%d leds\n", leds);
    }
    return 0;
}