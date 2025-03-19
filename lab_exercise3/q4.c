#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Repita o exercício anterior criando um vetor dinâmico de carros. Ao invés de
inicializar o vetor com valores predefinidos, peça ao usuário para digitar os
dados de dois carros. Use uma função para receber o vetor de carros e exibir o
valor total dos carros.
*/

typedef struct{
    char modelo[20];
    int ano;
    float preco;
}Carro;

void exibirValor(Carro *carro){
    float valortotal = 0;
    for(int i = 0; i < 2; i++){
        valortotal += carro[i].preco;
    }
    printf("Valor total dos carros: %.2f\n", valortotal);
}

int main(){
    Carro *carro = (Carro*)malloc(2*sizeof(Carro));
    for(int i = 0; i < 2; i++){
        printf("Digite o modelo do carro %d: ", i);
        scanf("%s", carro[i].modelo);
        printf("Digite o ano do carro %d: ", i);
        scanf("%d", &carro[i].ano);
        printf("Digite o preco do carro %d: ", i);
        scanf("%f", &carro[i].preco);
    }
    exibirValor(carro);

    free(carro);
    return 0;
}
