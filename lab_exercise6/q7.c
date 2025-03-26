#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Crie um programa que simule uma fila de impressão, onde os documentos
são enfileirados para impressão e processados na ordem de chegada.
O programa deve permitir:
● Adicionar novos documentos à fila.
● Processar a impressão (removendo o primeiro documento da fila).
● Exibir os documentos restantes na fila.
*/

typedef struct fila{
    char dado[100];
    struct fila *prox;
}Fila;

Fila *criaFila(){
    return NULL;
}

Fila *adicionar(Fila *fila, char dado[]){
    Fila *novo = (Fila*)malloc(sizeof(Fila));
    strcpy(novo->dado, dado);
    novo->prox = NULL;
    if(fila == NULL){
        return novo;
    }
    Fila *aux = fila;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    return fila;
}

Fila *remover(Fila *fila, char dado[]){
    if(fila == NULL) return NULL;
    Fila *aux = fila;
    strcpy(dado, fila->dado);
    fila = fila->prox;
    free(aux);
    return fila;
}

void imprimir(Fila *fila){
    Fila *aux = fila;
    printf("Fila atual: [");
    while(aux != NULL){
        printf("'%s'", aux->dado);
        if(aux->prox != NULL){
            printf(", ");
        }
        aux = aux->prox;
    }
    printf("]\n");
}

int main(){
    Fila *fila = criaFila();

    char entrada[100];
    char dado[100]; 
    
    printf("Digite o comando: ");
    scanf(" %[^\n]", entrada);
    while(strcmp(entrada, "sair") != 0){
        if(strcmp(entrada, "Imprimir") == 0){
            if(fila != NULL){
                fila = remover(fila, dado);
                printf("Imprimindo %s\n", dado);
            }else{
                printf("Fila vazia\n");
            }
        }else{
            char comando[100];
            sscanf(entrada, "%s \"%[^\"]\"", comando, dado);
            if(strcmp(comando, "Adicionar") == 0){
                fila = adicionar(fila, dado);
            }
        }
        imprimir(fila);
        printf("Digite o comando: ");
        scanf(" %[^\n]", entrada);
    }
    return 0;
}