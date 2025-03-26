#include <stdio.h>
#include <stdlib.h>

/*Com base no programa anterior, implemente um programa que solucione,
por meio de estrutura de pilha, expressões fornecidas em notação pós-fixa.
*/

typedef struct pilha{
    int dado;
    struct pilha *prox;
}Pilha;

Pilha *criaPilha(){
    return NULL;
}

Pilha *adicionar(Pilha *pilha, int dado){
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
    int i = 0, num1, num2;

    printf("Digite a expressao matematica: ");
    scanf("%[^\n]", entrada);
    while(entrada[i] != '\0'){
        if(entrada[i] >= '0' && entrada[i] <= '9'){
            pilha = adicionar(pilha, entrada[i] - '0');
        }else if(entrada[i] == '+'){
            num1 = pilha->dado;
            pilha = remover(pilha);
            num2 = pilha->dado;
            pilha = remover(pilha);
            pilha = adicionar(pilha, num2 + num1);
        }else if(entrada[i] == '-'){
            num1 = pilha->dado;
            pilha = remover(pilha);
            num2 = pilha->dado;
            pilha = remover(pilha);
            pilha = adicionar(pilha, num2 - num1);
        }else if(entrada[i] == '*'){
            num1 = pilha->dado;
            pilha = remover(pilha);
            num2 = pilha->dado;
            pilha = remover(pilha);
            pilha = adicionar(pilha, num2 * num1);
        }else if(entrada[i] == '/'){
            num1 = pilha->dado;
            pilha = remover(pilha);
            num2 = pilha->dado;
            pilha = remover(pilha);
            pilha = adicionar(pilha, num2 / num1);
        }
        i++;
    }
    printf("%d\n", pilha->dado);
    return 0;
}