#include <stdio.h>

//10º Descubra qual é a saída do seguinte trecho de código, sem auxílio do
    //computador. Depois rode o programa passo a passo com o depurador para
    //verificar se conseguiu chegar na resposta certa.
    //#include <stdio.h>
    //int main() {
    //  int valor = 10, *temp, soma = 0;
    //  temp = &valor;
    //  *temp = 20;
    //  temp = &soma;
    //  *temp = valor;
    //  printf("valor: %d\nsoma: %d\n", valor, soma);
    //  return 0;
    //}
    //Sugestão: observe como as variáveis se alteram com a execução do programa.
    // No começo tempos valor = 10, *temp sem atribuição e soma = 0, quando colocamos temp = &valor, atribuimos ao temp o endereço de "valor".
    //Como temp armazena o endereço de valor, *temp aponta pro valor armazenado na variavel "valor", logo se colocarmos *temp = 20, estaremos mudando a variavel
    //valor, que fica valor = 20. Em temp = &soma atribuimos aogra o endereço da variavel soma a temp. Como *temp = valor, e em temp está armazenada o endereço de soma
    //o *temp vai receber o valor da variavel "valor" que é 20 e será atribuido a variavel soma, que ficara 20 também. No final teremos valor = 20, temp = &soma, soma = 20.

int main(){
    int valor = 10, *temp, soma = 0;
    temp = &valor;
    *temp = 20;
    temp = &soma;
    *temp = valor;
    printf("valor: %d\nsoma: %d\n", valor, soma);
    return 0;
}