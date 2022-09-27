/*
Facil = 9x9 (10 bombas)
Médio = 16x16(40 bombas)
Dificil = 16x30(99 bombas)
*/

#include <stdio.h>
#include <stdlib.h>
#define LIN 16
#define COL 30

void menu();
int criaMatriz(int level);
void mostraCampo(int campo[LIN][COL]);
void mostraTela(char tela[LIN][COL], int level);
void preencheCampo(int, int, int campo[LIN][COL]);
void preencheTela(int level, char tela[LIN][COL]);
int abreCasas(int campo[LIN][COL], char tela[LIN][COL], int x, int y, int k);
void criaBombas(int campo[LIN][COL], int level);

int main(){
    int level;  //dificuldade selecionada
    int campo[LIN][COL] = {0};    //campo interpretado pelo computador
    char tela[LIN][COL] = {0};    //tela usada pelo usuario
    int x;  //coordenada x selecionada
    int y;  //coordenada y selecionada
    int row;
    int coll;
    int k;  //booleano que mantém o jogo rodando
    k = 0;

    menu();

    scanf("%d", &level);
        if (level >= 1 && level <= 3){
        switch (level){
        case 1:
            row = 9;
            coll = 9;
            break;
        case 2:
            row = 16;
            coll = 16;
            break;
        case 3:
            row = 16;
            coll = 30;
            break;
        }

        preencheCampo(row, coll, campo);
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
            if (x > row-1 || y > coll-1){
                exit(1);
            }

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

void preencheTela(int level, char tela[LIN][COL]){  //Preenche a tela mostrada ao jogador
    int i;  //linhas
    int j;  //colunas
    if (level == 1){
        for (i = 0; i <= (LIN -1); i++){
            for (j = 0; j<= (COL -1); j++){
                if (i <= 8 && j <= 8){
                    tela[i][j] = ("%s", 45);
                    }
                }
            }
        }
    if (level == 2){
        for (i = 0; i <= (LIN -1); i++){
            for (j = 0; j<= (COL -1); j++){
                if (i <= 15 && j <= 15){
                    tela[i][j] = ("%s", 45);
                }
                }
            }
        }
    if (level == 3){
        for (i = 0; i <= (LIN -1); i++){
            for (j = 0; j<= (COL -1); j++){
                tela[i][j] = ("%s", 45);
            }
        }
    }
}

void preencheCampo(int row, int coll, int campo[LIN][COL]){   //Preenche o campo interpretado pelo computador
    int i;  //linhas
    int j;  //colunas
    int l, c;

        for (i = 0; i <= (LIN -1); i++){
            for (j = 0; j<= (COL -1); j++){
                if (i < row && j < coll){
                    campo[i][j] = 0;
                }
                else{
                    campo[i][j] = 9;
                }
            }
        }
}

void mostraCampo(int campo[LIN][COL]){  //Printa o campo interpretado pelo computador
    int i;  //linhas
    int j;  //colunas
    for (i = 0; i <= (LIN -1); i++){
        for (j = 0; j<= (COL -1); j++){
            printf("[%2d]", campo[i][j]);
        }
        printf("\n");
    }
}

void mostraTela(char tela[LIN][COL], int level){   //Printa a tela mostrada ao jogador
    int i;  //linhas
    int j;  //colunas
    for (i = 0; i <= (LIN -1); i++){
        for (j = 0; j<= (COL -1); j++){
            if (level == 1){
                if (i >= 9 || j >= 9){
                printf("\0");
                }
                else{
                printf("[%1c]", tela[i][j]);
                }
            }
            if (level == 2){
                if (i >= 16 || j >= 16){
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

int abreCasas(int campo[LIN][COL], char tela[LIN][COL], int x, int y, int k){   //abre a respectiva coordenada selecionada (TERMINAR)
    if (campo[x-1][y-1] != -1){
        if (campo[x-1][y-1] != 0){
            tela[x-1][y-1] = ("%s", (campo[x-1][y-1] + '0'));
        }
        else{
            tela[x-1][y-1] = ("%s", 32);
        }
    }   
}

void criaBombas(int campo[LIN][COL], int level){  //posiciona as bombas no campo
    int bombax; //coordenada x da bomba
    int bombay; //coordenada y da bomba
    int i;  //numero de bombas
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
        for (i = 0; i< 40; i++){
            bombax = rand() % 16;
            bombay = rand() % 16;
            if (campo[bombax][bombay] == -1){
                i--;
            }
            else{
                campo[bombax][bombay] = -1;
            }
        }
    }
    if (level == 3){
        for (i = 0; i< 99; i++){
            bombax = rand() % 16;
            bombay = rand() % 30;
            if (campo[bombax][bombay] == -1){
                i--;
            }
            else{
                campo[bombax][bombay] = -1;
            }
        }
    }
}