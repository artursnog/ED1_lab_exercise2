#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa que utilize uma pilha para verificar se uma
sequência de parênteses está corretamente balanceada. Seu código deve
considerar os símbolos: {}, (), [].
*/

typedef struct pilha{
    char dado;
    struct pilha *prox;
}Pilha;

Pilha *criaPilha(){
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
    Pilha *pilha = criaPilha();

    char entrada[100];
    int i = 0;

    printf("Digite a sequencia de parenteses: ");
    scanf("%s", entrada);
    while(entrada[i] != '\0'){
        if(entrada[i] == '(' || entrada[i] == '{' || entrada[i] == '['){
            pilha = adicionar(pilha, entrada[i]);
        }else if(entrada[i] == ')' && pilha->dado == '('){
            pilha = remover(pilha);
        }else if(entrada[i] == '}' && pilha->dado == '{'){
            pilha = remover(pilha);
        }else if(entrada[i] == ']' && pilha->dado == '['){
            pilha = remover(pilha);
        }
        i++;
    }
    if(pilha == NULL){
        printf("Entrada Balanceada\n");
    }else{
        printf("Entrada nao Balanceada\n");
    }
    return 0;
}