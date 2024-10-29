#include <stdio.h>

int main(){
    int sud[9][9], n, i, i2, j, j2, k, correto, linquad, colquad;
    scanf("%d", &n);
    int resp[n];
    for(k=0; k<n; k++){
        correto = 0;
        for(i=0; i<9; i++){
            for(j=0; j<9; j++){
                sud[i][j] = 0;
            }
        }
        for(i2=0; i2<9; i2++){
            for(j2=0; j2<9; j2++){
                scanf("%d", &sud[i2][j2]);
                for(i=0; i<9; i++){
                    if(i != i2){
                        if(sud[i2][j2] == sud[i][j2]){
                            correto = 1;
                        }
                    }
                }
                for(j=0; j<9; j++){
                    if(j != j2){
                        if(sud[i2][j2] == sud[i2][j]){
                            correto = 1;
                        }
                    }
                }
                linquad = i2 / 3;
                colquad = j2 / 3;
                switch(linquad){
                    case 1:
                        linquad = 3;
                        break;
                    case 2:
                        linquad = 6;
                        break;
                }
                switch(colquad){
                    case 1:
                        colquad = 3;
                        break;
                    case 2:
                        colquad = 6;
                        break;
                }
                for(i=linquad; i<linquad+3; i++){
                    for(j=colquad; j<colquad+3; j++){
                        if(i != i2 && j != j2){
                            if(sud[i2][j2] == sud[i][j]){
                                correto = 1;
                            }
                        }
                    }
                }
            }
        }
        resp[k] = correto;
    }
    for(k=0; k<n; k++){
        printf("Instancia %d\n", k+1);
        if(resp[k] == 0){
            printf("SIM\n\n");
        }else{
            printf("NAO\n\n");
        }
    }
    return 0;
}