#include <stdio.h>

typedef struct {
    char estado[6];
    char tipo[6];
} Tigela;

void Fome(Tigela *tigela){
    tigela->estado[0] = 'v';
    tigela->estado[1] = 'a';
    tigela->estado[2] = 'z';
    tigela->estado[3] = 'i';
    tigela->estado[4] = 'a';
    tigela->estado[5] = '\0';

}

int main(){
    
    //8º Declare um registro "Tigela" com os campos estado (cheia ou vazia) e tipo de
    //alimento (sopa ou canja). Crie uma função "Fome" que recebe um ponteiro para
    //uma Tigela e altera o seu estado para "vazia". Na função principal crie uma
    //tigela cheia, crie um ponteiro que aponta para essa tigela e então mostre como a
    //tigela estava antes da janta. Depois chame a função Fome com o ponteiro que
    //aponta para a tigela e ao fim mostre a tigela depois da janta.

    Tigela tigela = {"cheia", "sopa"};
    Tigela *p = &tigela;
    printf("Antes da janta: %s\n", p->estado);
    Fome(p);
    printf("Depois da janta: %s\n", p->estado);

    return 0;
}