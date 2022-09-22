#include <stdio.h>

void menu();
int criaMatriz(int level);
void mostraMatriz(int campo[13][13]);
void preencheMatriz(int level, int campo[13][13]);

int main(){
    int level;
    int campo[13][13];
    int i;
    int j;

    menu();

    scanf("%d", &level);

    preencheMatriz(level, campo);

    //campo = criaMatriz(level);
    mostraMatriz(campo);
    return 0;
}

void menu(){    //Printar menu
    printf("\n | MINESWEEPER |\nFeito por: Rafael Honorio Venetikides\n");
    printf("\nSelecione a dificuldade: ");
    printf("\n    1 - I'm too young to die.\n    2 - Hurt me plenty.\n    3 - Ultra-Violence.\n    0 - Sair\n");
}

void preencheMatriz(int level, int campo[13][13]){
    int i;
    int j;

            if (level == 1){
        for (i = 0; i <= 12; i++){
            for (j = 0; j<= 12; j++){
                if (i <= 8 && j <= 8){
                    campo[i][j] = 0;
                }
                else{
                    campo[i][j] = 9;
                }
            }
        }
    }
    if (level == 2){
        for (i = 0; i <= 12; i++){
            for (j = 0; j<= 12; j++){
                if (i <= 10 && j <= 10){
                    campo[i][j] = 0;
                }
                else{
                    campo[i][j] = 9;
                }
            }
        }
    }
    if (level == 3){
        for (i = 0; i <= 12; i++){
            for (j = 0; j<= 12; j++){
                campo[i][j] = 0;
            }
        }
    }
}

void mostraMatriz(int campo[13][13]){
    int i;
    int j;
    for (i = 0; i <= 12; i++){
        for (j = 0; j<= 12; j++){
            printf("[%d]", campo[i][j]);
        }
        printf("\n");
    }
}