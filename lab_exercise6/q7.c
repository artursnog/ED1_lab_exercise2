#include <stdio.h>
#include <stdlib.h>
/* Declare um ponteiro para inteiro, aloque memória dinamicamente para ele e
armazene o número 100 nessa memória. Mostre o conteúdo apontado. Peça que
o usuário digite um novo número inteiro e armazene-o na memória previamente
alocada. Libere o espaço alocado dinamicamente ao final do programa.*/
int main(){
    int *p = (int*)malloc(sizeof(int));
    *p = 100;
    printf("Conteudo armazenado: %d\n", *p);
    printf("Digite novo valor para esse bloco de memória: ");
    scanf("%d", p);
    printf("Conteudo apontado: %d\n", *p);
    free(p);
    return 0;
}
