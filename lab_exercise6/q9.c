#include <stdio.h>

/*Implemente uma fila circular com tamanho fixo(Array Estático).
● Ao adicionar um novo elemento quando a fila está cheia, o primeiro
elemento deve ser sobrescrito.
● Teste sua implementação enfileirando e desenfileirando elementos.*/

typedef struct fila{
    int dados[5];
    int inicio, fim;
    int tamanho;
}Fila;

Fila criarFila(){
    Fila fila;
    fila.inicio = 0;
    fila.fim = 0;
    fila.tamanho = 0;
    return fila;
}

Fila enfileirar(Fila fila, int dado){
    if(fila.tamanho == 5){
        fila.dados[fila.inicio] = dado;
        fila.inicio = (fila.inicio + 1) % 5;
    }else{
        fila.dados[fila.fim] = dado;
        fila.fim = (fila.fim + 1) % 5;
        fila.tamanho++;
    }
    return fila;
}

Fila desenfileirar(Fila fila){
    if(fila.tamanho == 0){
        return fila;
    }
    fila.inicio = (fila.inicio + 1) % 5;
    fila.tamanho--;
    return fila;
}

void imprimir(Fila fila){
    int i = fila.inicio;
    for(int j = 0; j < fila.tamanho; j++){
        printf("%d ", fila.dados[i]);
        i = (i + 1) % 5;
    }
    printf("\n");
}

int main(){
    Fila fila = criarFila();

    fila = enfileirar(fila, 1);
    fila = enfileirar(fila, 2);
    fila = enfileirar(fila, 3);
    fila = enfileirar(fila, 4);
    fila = enfileirar(fila, 5);
    imprimir(fila);

    fila = enfileirar(fila, 6);
    imprimir(fila);

    fila = desenfileirar(fila);
    imprimir(fila);

    fila = enfileirar(fila, 7);
    imprimir(fila);

    return 0;
}
