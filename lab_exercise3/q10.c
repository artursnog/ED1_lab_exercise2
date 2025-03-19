#include <stdio.h>
#include <stdlib.h>


/*Defina um registro ASCII que armazena um caractere e um valor inteiro
associado. Crie uma função que recebe um valor inteiro e um caractere, e
retorna o endereço de um elemento do tipo ASCII, alocado dinamicamente na
memória. O programa principal deve chamar a função passando valores lidos do
usuário, receber o retorno em um ponteiro, exibir os valores de retorno e deletar
a memória que foi alocada dentro da função.
*/

typedef struct {
    char caractere;
    int valor;
}ASCII;

ASCII* alocaASCII(int valor, char caractere){
    ASCII *elemento = (ASCII*)malloc(sizeof(ASCII));
    elemento->caractere = caractere;
    elemento->valor = valor;
    return elemento;
}

int main(){
    int valor;
    char caractere;
    printf("Digite um valor inteiro: ");
    scanf("%d", &valor);
    printf("Digite um caractere: ");
    scanf(" %c", &caractere);
    ASCII *elemento = alocaASCII(valor, caractere);
    printf("Caractere: %c\nValor: %d\n", elemento->valor, elemento->caractere);
    free(elemento);
    return 0;
}
