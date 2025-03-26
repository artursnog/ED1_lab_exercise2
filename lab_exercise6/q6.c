#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Crie um programa que simule o atendimento de clientes em um banco.
Utilize uma fila para armazenar os clientes que aguardam atendimento.
● O programa deve permitir adicionar novos clientes à fila.
● Deve ser possível atender um cliente (removendo-o da fila).
● Exibir a fila atual de espera.
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
        if(strcmp(entrada, "Atender") == 0){
            if(fila != NULL){
                fila = remover(fila, dado);
                printf("Atendendo %s\n", dado);
            }else{
                printf("Fila vazia\n");
            }
        }else if(strncmp(entrada, "Adicionar", 9) == 0){
            char *token = strtok(entrada, "\"");
            token = strtok(NULL, "\"");
            if (token != NULL) {
                fila = adicionar(fila, token);
            } else {
                printf("Comando inválido. Use: Adicionar \"Nome\"\n");
            }
        } else {
            printf("Comando inválido. Use 'Adicionar \"Nome\"' ou 'Atender'.\n");
        }
        imprimir(fila);
        printf("Digite o comando: ");
        scanf(" %[^\n]", entrada);
    }
    return 0;
}