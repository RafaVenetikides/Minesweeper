#include <stdio.h>
#include <stdlib.h>

void menu();
int criaMatriz(int level);
void mostraCampo(int campo[13][13]);
void mostraTela(char tela[13][13], int level);
void preencheCampo(int level, int campo[13][13]);
void preencheTela(int level, char tela[13][13]);
int abreCasas(int campo[13][13], char tela[13][13], int x, int y, int k);
void criaBombas(int campo[13][13], int level);

int main(){
    int level;
    int campo[13][13];
    char tela[13][13];
    int x;
    int y;
    int i;
    int j;
    int k;
    k = 0;

    menu();

    scanf("%d", &level);
    if (level >= 1 && level <= 3){
        preencheCampo(level, campo);
        preencheTela(level, tela);
        criaBombas(campo, level);

        while (k == 0){
            x = 0;
            y = 0;
            printf("Campo: \n");
            mostraCampo(campo);
            printf("Tela: \n");
            mostraTela(tela, level);

            printf("Selecione a coordenada x: ");
            scanf("%d", &x);
            printf("Selecione a coordenada y: ");
            scanf("%d", &y);

            abreCasas(campo, tela, x, y, k);
            printf("\nvalor de k: %d", k);
        }
    }
    return 0;
}

void menu(){    //Printar menu
    printf("\n | MINESWEEPER |\nFeito por: Rafael Honorio Venetikides\n");
    printf("\nSelecione a dificuldade: ");
    printf("\n    1 - I'm too young to die.\n    2 - Hurt me plenty.\n    3 - Ultra-Violence.\n    0 - Sair\n");
}

void preencheTela(int level, char tela[13][13]){  //Preenche a tela mostrada ao jogador
    int i;
    int j;
    if (level == 1){
        for (i = 0; i <= 12; i++){
            for (j = 0; j<= 12; j++){
                if (i <= 8 && j <= 8){
                    tela[i][j] = ("%s", 45);
                    }
                }
            }
        }
    if (level == 2){
        for (i = 0; i <= 12; i++){
            for (j = 0; j<= 12; j++){
                if (i <= 10 && j <= 10){
                    tela[i][j] = ("%s", 45);
                }
                }
            }
        }
    if (level == 3){
        for (i = 0; i <= 12; i++){
            for (j = 0; j<= 12; j++){
                tela[i][j] = ("%s", 45);
            }
        }
    }
}

void preencheCampo(int level, int campo[13][13]){   //Preenche o campo interpretado pelo computador
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

void mostraCampo(int campo[13][13]){  //Printa o campo interpretado pelo computador
    int i;
    int j;
    for (i = 0; i <= 12; i++){
        for (j = 0; j<= 12; j++){
            printf("[%2d]", campo[i][j]);
        }
        printf("\n");
    }
}

void mostraTela(char tela[13][13], int level){   //Printa a tela mostrada ao jogador
    int i;
    int j;
    for (i = 0; i <= 12; i++){
        for (j = 0; j<= 12; j++){
            if (level == 1){
                if (i >= 9 || j >= 9){
                printf("\0");
                }
                else{
                printf("[%1c]", tela[i][j]);
                }
            }
            if (level == 2){
                if (i >= 11 || j >= 11){
                printf("\0");
                }
                else{
                printf("[%1c]", tela[i][j]);
                }
            }
            if (level == 3){
                printf("[%1c]", tela[i][j]);
            }
        }
        printf("\n");
    }
}

int abreCasas(int campo[13][13], char tela[13][13], int x, int y, int k){   //abre a respectiva coordenada selecionada (TERMINAR)
    if (x > 13 || y > 13){
        k = 1;
        printf("\nQuebra %d\n", k);
    }
    else if (campo[x-1][y-1] != -1){
        if (campo[x-1][y-1] != 0){
            tela[x-1][y-1] = ("%s", (campo[x-1][y-1] + '0'));
        }
        else{
            tela[x-1][y-1] = ("%s", 32);
        }
    }   
}

void criaBombas(int campo[13][13], int level){  //posiciona as bombas no campo
    int bombax;
    int bombay;
    int i;
    if (level == 1){
        for (i = 0; i< 10; i++){
            bombax = rand() % 9;
            bombay = rand() % 9;
            if (campo[bombax][bombay] == -1){
                i--;
            }
            else{
                campo[bombax][bombay] = -1;
            }
        }
    }
    if (level == 2){
        for (i = 0; i< 14; i++){
            bombax = rand() % 11;
            bombay = rand() % 11;
            if (campo[bombax][bombay] == -1){
                i--;
            }
            else{
                campo[bombax][bombay] = -1;
            }
        }
    }
    if (level == 3){
        for (i = 0; i< 17; i++){
            bombax = rand() % 13;
            bombay = rand() % 13;
            if (campo[bombax][bombay] == -1){
                i--;
            }
            else{
                campo[bombax][bombay] = -1;
            }
        }
    }
}