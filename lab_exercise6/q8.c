#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Implemente um escalonador de processos baseado no algoritmo
Round-Robin utilizando filas.
● Cada processo tem um tempo de execução.
● Cada processo recebe um quantum de tempo fixo.
● Se um processo não for concluído dentro do quantum, ele retorna ao final
da fila.
*/

typedef struct fila{
    char dado[100];
    int tempo;
    struct fila *prox;
}Fila;

Fila *criaFila(){
    return NULL;
}

Fila *adicionar(Fila *fila, char dado[], int tempo){
    Fila *novo = (Fila*)malloc(sizeof(Fila));
    strcpy(novo->dado, dado);
    novo->tempo = tempo;
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

Fila *remover(Fila *fila, char dado[], int *tempo){
    if(fila == NULL) return NULL;
    Fila *aux = fila;
    strcpy(dado, fila->dado);
    *tempo = fila->tempo;
    fila = fila->prox;
    free(aux);
    return fila;
}

void executar(Fila **fila, int quantum) {
    char dado[100];
    int tempo;

    while (*fila != NULL) {
        *fila = remover(*fila, dado, &tempo);
        if (tempo > quantum) {
            printf("Executando %s por %ds\n", dado, quantum);
            tempo -= quantum;
            *fila = adicionar(*fila, dado, tempo);
        } else {
            printf("Executando %s por %ds (finalizado)\n", dado, tempo);
        }
    }
}

int main(){
    Fila *fila = criaFila();

    char entrada[100];
    char dado[100]; 
    int tempo;
    int quantum = 0;
    
    printf("Digite o comando: ");
    scanf(" %[^\n]", entrada);
    while(strcmp(entrada, "sair") != 0){
        if(strcmp(entrada, "Adicionar") == 0){
            scanf(" \"%[^\"]\" (tempo: %ds)", dado, &tempo);
            fila = adicionar(fila, dado, tempo);
            if (quantum > 0) {
                executar(&fila, quantum);
            }
        } else if(strcmp(entrada, "Quantum:") == 0){
            scanf(" %ds", &quantum);
            if (fila != NULL) { 
                executar(&fila, quantum);
            }
        } else {
            printf("Comando inválido. Use 'Adicionar \"Nome\" (tempo: Xs)' ou 'Quantum: Xs'.\n");
        }
        printf("Digite o comando: ");
        scanf(" %[^\n]", entrada);
    }
    return 0;
}
