#include <stdio.h>

typedef struct {
    char Tipo[20];
    float Peso;
    unsigned Comprimento;
}Peixe;

void exibirPeixe(Peixe peixe1) {
    printf("O tipo do peixe e: %s\n", peixe1.Tipo);
    printf("O peso do peixe e: %.2fkg\n", peixe1.Peso);
    printf("O comprimento do peixe e de: %ucm\n", peixe1.Comprimento);
}
void exibirPeixePtr(Peixe*peixe1) {
    printf("O tipo do peixe e: %s\n", peixe1->Tipo);
    printf("O peso do peixe e: %.2fkg\n", peixe1->Peso);
    printf("O comprimento do peixe e de: %ucm\n", peixe1->Comprimento);
}

int main(){
      //1º Defina um registro que descreve um peixe. O registro deve incluir o tipo
    // (string), o peso (ponto-flutuante) e o comprimento (inteiro) do peixe. Em
    // seguida mostre:
    // a) Como criar uma variável de tipo peixe
    // b) Como criar um ponteiro para uma variável de tipo peixe
    Peixe peixe1 = {"Piranha", 0.5, 30};
    Peixe *ptr = &peixe1;

    //2º Construa uma função que receba um peixe e exiba o seu conteúdo.
    // a) Faça uma versão utilizando um parâmetro tipo peixe
    // b) Faça uma versão utilizando um parâmetro tipo ponteiro para peixe
    exibirPeixe(peixe1);
    printf("/n");
    exibirPeixePtr(ptr);
    
    return 0;
}
