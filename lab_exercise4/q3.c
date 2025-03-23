#include <stdio.h>
/*Construa um programa que leia um número desconhecido de peixes de um
arquivo texto, chamado “pescado.txt”, e exiba a quantidade total de quilos de
peixe pescado. O arquivo é formatado como no exemplo abaixo: o nome do
peixe, o peso em gramas e o comprimento em centímetros.*/
int main(){
    FILE *arq = fopen("pescado.txt", "r");

    char nome[100];
    int peso, comprimento;
    int total = 0;

    while (fscanf(arq, "%s %d %d", nome, &peso, &comprimento) != EOF){
        total += peso;
    }

    printf("Total de peixes pescados: %d gramas\n", total);
    fclose(arq);
    return 0;
}