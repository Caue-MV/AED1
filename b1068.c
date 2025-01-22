#include <stdio.h>
#include <stdlib.h>

int main() {
    char string[1000], limpo[1000];
    int i, j;
    
    for (int k = 0; k < 10001; k++) {
        if (scanf("%999s", string) != 1) {
            break;
        }
        
        i = 0;
        j = 0;
        
        do {
            if (string[i] == ')' && j > 0 && limpo[j - 1] == '(') {
                j--;
            }
            else if (string[i] == '(' || string[i] == ')') {
                limpo[j] = string[i];
                j++;
            }
            i++;
        } while (string[i] != '\0');
        
        if(j==0){
            printf("correct\n");
        }else{
            printf("incorrect\n");
        }
    }
    
    return 0;
}