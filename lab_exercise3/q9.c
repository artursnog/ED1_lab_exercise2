#include <stdio.h>
#include <stdlib.h>
/*Crie um registro "Local" com os campos nome, país e continente. Pergunte
ao usuário quantos locais ele quer visitar nas próximas férias e crie um vetor de
locais alocando dinamicamente o espaço de acordo com quantos locais ele quer
visitar. Use um laço for para armazenar as informações dos locais que o usuário
deseja visitar, e depois do armazenamento mostre os locais que ele escolheu.
Libere o espaço alocado dinamicamente ao final do programa*/

typedef struct{
    char nome[50];
    char pais[50];
    char continente[50];
}Local;

int main(){
    int n;
    printf("Quantos locais deseja visitar? ");
    scanf("%d", &n);
    Local *locais = (Local*)malloc(n*sizeof(Local));
    for (int i = 0; i < n; i++){
        printf("Digite o nome do %dº local: ", i+1);
        scanf(" %s", locais[i].nome);
        printf("Digite o país do %dº local: ", i+1);
        scanf(" %s", locais[i].pais);
        printf("Digite o continente do %dº local: ", i+1);
        scanf(" %s", locais[i].continente);
    }
    for(int i = 0; i < n; i++){
        printf("Local %d: %s\n", i+1, locais[i].nome);
        printf("País: %s\n", locais[i].pais);
        printf("Continente: %s\n", locais[i].continente);
    }
    free(locais);
    return 0;
}
