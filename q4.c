#include <stdio.h>

void Mais(int *ptr) {
    *ptr+=1;
    printf("%d\n", *ptr);
}

int Incremento(int num1) {
    return num1+1;
}

int main(){

    //4º Construa duas funções que realizem o incremento de um número em uma
    // unidade. A função Mais deve receber um número inteiro através de um
    // ponteiro. A função Incrementa deve receber um valor inteiro, sem usar
    // ponteiros, e retornar o valor incrementado em uma unidade. Utilize as duas
    // funções como no exemplo abaixo:
    int num1 = 10;
    printf("%d\n", num1);
    Mais(&num1);
    printf("%d\n", Incremento(num1));

    return 0;
}