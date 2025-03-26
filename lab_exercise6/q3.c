#include <stdio.h>
#include <stdlib.h>

/*Implemente um algoritmo que, utilizando as estruturas de pilha, converta
expressões matemáticas na notação infixa (exemplo: 3 + 4 * 2) para a notação
pós-fixa (exemplo: 3 4 2 * +).
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
    
    printf("Digite a expressao matematica: ");
    scanf("%[^\n]", entrada);
    while(entrada[i] != '\0'){
        if(entrada[i] == '('){
            pilha = adicionar(pilha, entrada[i]);
        }else if(entrada[i] == ')'){
            while(pilha->dado != '('){
                printf("%c", pilha->dado);
                pilha = remover(pilha);
            }
            pilha = remover(pilha);
        }else if(entrada[i] == '+' || entrada[i] == '-'){
            while(pilha != NULL && pilha->dado != '('){
                printf("%c", pilha->dado);
                pilha = remover(pilha);
            }
            pilha = adicionar(pilha, entrada[i]);
        }else if(entrada[i] == '*' || entrada[i] == '/'){
            while(pilha != NULL && (pilha->dado == '*' || pilha->dado == '/')){
                printf("%c", pilha->dado);
                pilha = remover(pilha);
            }
            pilha = adicionar(pilha, entrada[i]);
        }else if(entrada[i] >= '0' && entrada[i] <= '9'){
            printf("%c", entrada[i]);
        }
        i++;
    }
    while(pilha != NULL){
        printf("%c", pilha->dado);
        pilha = remover(pilha);
    }
    printf("\n");
    return 0;
}