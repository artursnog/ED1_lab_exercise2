#include <stdio.h>
#include <string.h>
/*Construa um registro para guardar informações sobre um carro. Um carro
deve ter um modelo, ano de fabricação e preço. Em seguida construa um vetor
estático de 10 carros inicializando os dois primeiros carros respectivamente para
"Vectra", 2009, R$58.000,00 e "Polo", 2008, R$45.000,00. Use um ponteiro
para apontar para o segundo carro e exibir seus dados.*/

typedef struct{
    char modelo[20];
    int ano;
    float preco;
}Carro;

int main(){
    Carro carro[10];
    strcpy(carro[0].modelo, "Vectra");
    carro[0].ano = 2009;
    carro[0].preco = 58000.00;

    strcpy(carro[1].modelo, "Polo");
    carro[1].ano = 2008;
    carro[1].preco = 45000.00;
    
    Carro *p = &carro[1];
    printf("Modelo: %s\nAno: %d\nPreco: %.2f\n", p->modelo, p->ano, p->preco);
    return 0;
}
