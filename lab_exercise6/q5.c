#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Crie um programa que simule um sistema de desfazer e refazer utilizando
duas pilhas.
● O usuário pode digitar comandos e o programa os armazenará.
● O comando "desfazer" deve remover a última ação realizada.
● O comando "refazer" deve reaplicar a última ação desfeita.
*/

typedef struct pilha{
    char dado[100];
    struct pilha *prox;
}Pilha;

Pilha *criaPilha(){
    return NULL;
}

Pilha *adicionar(Pilha *pilha, char dado[]){
    Pilha *novo = (Pilha*)malloc(sizeof(Pilha));
    strcpy(novo->dado, dado);
    novo->prox = pilha;
    return novo;
}

Pilha *remover(Pilha *pilha, char dado[]){
    if (pilha == NULL) return NULL;
    Pilha *aux = pilha;
    strcpy(dado, pilha->dado);
    pilha = pilha->prox;
    free(aux);
    return pilha;
}

void imprimir(Pilha *pilha){
    Pilha *aux = pilha;
    while(aux != NULL){
        printf("%s\n", aux->dado);
        aux = aux->prox;
    }
}

int main(){
    Pilha *pilha = criaPilha();
    Pilha *pilhaRefazer = criaPilha();

    char entrada[100];
    char dado[100]; 

    printf("Digite o comando: ");
    scanf(" %[^\n]", entrada);
    while(strcmp(entrada, "sair") != 0){
        if(strcmp(entrada, "desfazer") == 0){
            if (pilha != NULL) {
                pilha = remover(pilha, dado);
                pilhaRefazer = adicionar(pilhaRefazer, dado);
                printf("Acao desfeita: \"%s\"\n", dado);
            } else {
                printf("Nada para desfazer.\n");
            }
        } else if(strcmp(entrada, "refazer") == 0){
            if (pilhaRefazer != NULL) {
                pilhaRefazer = remover(pilhaRefazer, dado);
                pilha = adicionar(pilha, dado);
                printf("Acao refeita: \"%s\"\n", dado);
            } else {
                printf("Nada para refazer.\n");
            }
        } else {
            pilha = adicionar(pilha, entrada);
            
            while (pilhaRefazer != NULL) {
                pilhaRefazer = remover(pilhaRefazer, dado);
            }
        }
        imprimir(pilha);
        printf("Digite o comando: ");
        scanf(" %[^\n]", entrada);
    }
    return 0;
}