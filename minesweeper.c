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
int criaMatriz(int);
void mostraCampo(int [LIN][COL]);
void mostraTela(char [LIN][COL], int, int);
void preencheCampo(int, int, int [LIN][COL]);
void preencheTela(int , int, int, char [LIN][COL]);
int abreCasas(int [LIN][COL], char [LIN][COL], int, int, int);
void criaBombas(int [LIN][COL], int, int, int);

int main(){
    int level;  //dificuldade selecionada
    int campo[LIN][COL] = {0};    //campo interpretado pelo computador
    char tela[LIN][COL] = {0};    //tela usada pelo usuario
    int x;  //coordenada x selecionada
    int y;  //coordenada y selecionada
    int row;
    int coll;
    int bombas;
    int k;  //booleano que mantém o jogo rodando
    k = 0;

    menu();

    scanf("%d", &level);
        if (level >= 1 && level <= 3){
        switch (level){
        case 1:
            row = 9;
            coll = 9;
            bombas = 10;
            break;
        case 2:
            row = 16;
            coll = 16;
            bombas = 40;
            break;
        case 3:
            row = 16;
            coll = 30;
            bombas = 99;
            break;
        }

        preencheCampo(row, coll, campo);
        preencheTela(level,row, coll, tela);
        criaBombas(campo, row, coll, bombas);

        while (k == 0){
            x = 0;
            y = 0;
            printf("Campo: \n");
            mostraCampo(campo);
            printf("Tela: \n");
            mostraTela(tela, row, coll);

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

void preencheTela(int level,int row, int coll, char tela[LIN][COL]){  //Preenche a tela mostrada ao jogador
    int i;  //linhas
    int j;  //colunas
    
    for (i = 0; i <= (LIN -1); i++){
        for (j = 0; j<= (COL -1); j++){
            if (i < row && j < coll){
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

void mostraTela(char tela[LIN][COL], int row, int coll){   //Printa a tela mostrada ao jogador
    int i;  //linhas
    int j;  //colunas
    int num;
    printf("     ");
    for (num = 0; num < coll; num ++){
        printf("%2d ", (num+1));
    }
    printf("\n");
    for (i = 0; i <= (LIN -1); i++){
        for (j = 0; j<= (COL -1); j++){
                if (i >= row || j >= coll){
                printf("\0");
                }
                else if (j == 0){
                    printf("%2d | [%1c]", (i+1), tela[i][j]);
                }
                else{
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

void criaBombas(int campo[LIN][COL], int row, int coll, int bombas){  //posiciona as bombas no campo
    int bombax; //coordenada x da bomba
    int bombay; //coordenada y da bomba
    int i;  //numero de bombas

    for (i = 0; i< bombas; i++){
        bombax = rand() % row;
        bombay = rand() % coll;
        if (campo[bombax][bombay] == -1){
            i--;
        }
        else{
            campo[bombax][bombay] = -1;
        }
    }
}
