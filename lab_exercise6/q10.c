#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Implemente uma fila de prioridade, onde elementos com maior prioridade
são atendidos primeiro.
● Cada elemento terá um valor associado à sua prioridade.
● O elemento com a maior prioridade deve ser removido antes dos demais.
● Caso dois elementos tenham a mesma prioridade, o primeiro a chegar é
atendido primeiro (FIFO).*/

typedef struct fila{
    char dado[100];
    int prioridade;
    struct fila *prox;
}Fila;

Fila *criaFila(){
    return NULL;
}

Fila *adicionar(Fila *fila, char dado[], int prioridade){
    Fila *novo = (Fila*)malloc(sizeof(Fila));
    strcpy(novo->dado, dado);
    novo->prioridade = prioridade;
    novo->prox = NULL;

    if (fila == NULL || prioridade > fila->prioridade) {
        novo->prox = fila;
        return novo;
    }

    Fila *aux = fila;
    while (aux->prox != NULL && aux->prox->prioridade >= prioridade) {
        aux = aux->prox;
    }
    novo->prox = aux->prox;
    aux->prox = novo;

    return fila;
}

Fila *remover(Fila *fila, char dado[], int *prioridade){
    if(fila == NULL) return NULL;
    Fila *aux = fila;
    strcpy(dado, fila->dado);
    *prioridade = fila->prioridade;
    fila = fila->prox;
    free(aux);
    return fila;
}

void imprimir(Fila *fila){
    Fila *aux = fila;
    while(aux != NULL){
        printf("Atendendo %s\n", aux->dado);
        aux = aux->prox;
    }
}

int main(){
    Fila *fila = criaFila();

    char entrada[100];
    char dado[100]; 
    int prioridade;
    
    printf("Digite o comando: ");
    scanf(" %[^\n]", entrada);
    while(strcmp(entrada, "sair") != 0){
        if(strcmp(entrada, "Adicionar") == 0){
            scanf(" \"%[^\"]\" com prioridade %d", dado, &prioridade);
            fila = adicionar(fila, dado, prioridade);
            imprimir(fila); 
        } else if(strcmp(entrada, "Atender") == 0){
            if(fila != NULL){
                fila = remover(fila, dado, &prioridade);
                printf("Atendendo %s\n", dado);
                printf("Fila atualizada:\n");
                imprimir(fila); 
            } else {
                printf("Fila vazia. Nenhum elemento para atender.\n");
            }
        } else {
            printf("Comando inválido. Use 'Adicionar \"Nome\" com prioridade X' ou 'Atender'.\n");
        }
        printf("Digite o comando: ");
        scanf(" %[^\n]", entrada);
    }
    return 0;
}