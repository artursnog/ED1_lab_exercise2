#include <stdio.h>
#include <stdlib.h>

/*
Defina o registro balao como mostrado abaixo. Construa um programa para
alocar dinamicamente uma variável do tipo balao. Peça ao usuário para entrar
com valores para cada um dos membros e em seguida exiba o conteúdo do
registro.
Em seguida mostre:*/
typedef struct {
    char marca[20];
    int modelo;
    float diametro;
} Balao;

void criarBalao(){
    Balao *b = (Balao*)malloc(sizeof(Balao));
    printf("Digite a marca do balao: ");
    scanf("%s", b->marca);
    printf("Digite o modelo do balao: ");
    scanf("%d", &b->modelo);
    printf("Digite o diametro do balao: ");
    scanf("%f", &b->diametro);
    printf("Marca: %s\nModelo: %d\nDiametro: %.2f\n", b->marca, b->modelo, b->diametro);
    free(b);
}

//a) Como criar uma variável de tipo peixe
// Devemos definir com typedef para que possamos usar o nome Peixe sem a palavra struct
typedef struct{
    char especie[20];
    int peso;
    float tamanho;
}Peixe;

//b) Como alocar dinamicamente um registro de tipo peixe
// Com o resgistrador que criamos anteriormente, podemos alocar dinamicamente um registro de tipo peixe, primeiro criamos a variavel e depois alocamos a memoria
// com malloc. Da para fazer em duas linhas diferentes , mas prefiro uma só. 1 - Peixe *p; 2 - pp = (Peixe*)malloc(sizeof(Peixe));
void criarPeixe(){
    Peixe *p = (Peixe*)malloc(sizeof(Peixe));
    printf("Digite a especie do peixe: ");
    scanf("%s", p->especie);
    printf("Digite o peso do peixe: ");
    scanf("%d", &p->peso);
    printf("Digite o tamanho do peixe: ");
    scanf("%f", &p->tamanho);
    printf("Especie: %s\nPeso: %d\nTamanho: %.2f\n", p->especie, p->peso, p->tamanho);
    free(p);
}

int main(){
    criarBalao();
    criarPeixe();
    return 0;
}
