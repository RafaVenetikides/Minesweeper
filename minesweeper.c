#include <stdio.h>

void menu();
char * criaMatriz(int level);
void mostraMatriz(char *campo, int level);

int main(){
    int level;
    char *campo;
    menu();
    scanf("%d", &level);
    if (level > 0 && level < 4){
    campo = criaMatriz(level);
    printf("%c", *campo);
    mostraMatriz(campo, level);
    }
    return 0;
}

void menu(){    //Printar menu
    printf("\n | MINESWEEPER |\nFeito por: Rafael Honorio Venetikides\n");
    printf("\nSelecione a dificuldade: ");
    printf("\n    1 - I'm too young to die.\n    2 - Hurt me plenty.\n    3 - Ultra-Violence.\n    0 - Sair\n");
}

char * criaMatriz(int level){
    if (level == 1){
        static char campo[7][7];
        return campo;
    }
    else if (level == 2){
        static char campo[9][9];
        return campo;
    }
    else if(level == 3){
        static char campo[11][11];
        return campo;
    }
}

void mostraMatriz(char *campo, int level){
    int i;
    if (level = 1){
        for (i = 0; i < (7*7); i++){
            printf("%c", *(campo + i));
            if (((i+1) % 7 )== 0){
                printf("\n");
            }
        } 
    }
    
}