#include <stdio.h>

int main(){

    //6º Crie uma variável do tipo char inicializada para o caractere 'A' e um ponteiro
    // que aponte para esta variável. Modifique a variável criada usando o ponteiro, de
    // forma que seu conteúdo agora seja 'B'. Por fim, mostre o conteúdo da variável e
    // o conteúdo apontado pelo ponteiro.
    char letra = 'A';
    char *ptrChar = &letra;
    *ptrChar = 'B';
    printf("Letra: %c\nPonteiro: %c\n", letra,*ptrChar);
    
    return 0;
}