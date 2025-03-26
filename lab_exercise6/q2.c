#include <stdio.h>
#include <stdlib.h>
/*Crie um programa que use uma pilha para inverter uma string. O usuário
deve inserir uma palavra ou frase, e o programa deve exibir o texto invertido.
*/

typedef struct pilha{
    char dado;
    struct pilha *prox;
}Pilha;

Pilha *criarPilha(){
    return NULL;
}

Pilha *adicionar(Pilha *pilha, char dado){
    Pilha *novo = (Pilha*)malloc(sizeof(Pilha));
    novo->dado = dado;
    novo->prox = pilha;
    return novo;
}

Pilha *remover(Pilha *pilha){
    Pilha *aux = pilha;
    pilha = pilha->prox;
    free(aux);
    return pilha;
}

int main(){
    Pilha *pilha = criarPilha();

    char entrada[100];
    int i = 0;

    printf("Digite a palavra ou frase: ");
    scanf("%s", entrada);
    while(entrada[i] != '\0'){
        pilha = adicionar(pilha, entrada[i]);
        i++;
    }
    while(pilha != NULL){
        printf("%c", pilha->dado);
        pilha = remover(pilha);
    }
    printf("\n");
    return 0;
}