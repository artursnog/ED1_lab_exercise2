#include <stdio.h>

typedef union {
    int corInt;
    struct {
        unsigned char R;
        unsigned char G;
        unsigned char B;
        unsigned char A;
    } corRGBA;
} Cores;

void lerCorRGBA(Cores *cor) {
    printf("Digite os valores para R, G, B e A (0-255): ");
    scanf("%hhu %hhu %hhu %hhu", &cor->corRGBA.R, &cor->corRGBA.G, &cor->corRGBA.B, &cor->corRGBA.A);
    printf("RGBA : %d %d %d %d\n", cor->corRGBA.R, cor->corRGBA.G, cor->corRGBA.B, cor->corRGBA.A);
}

void lerCorInt(Cores *cor) {
    printf("Digite o valor inteiro de 32 bits: ");
    scanf("%d", &cor->corInt);
    printf("Int32: %d\n", cor->corInt);
}


int main(){

    //7º Uma cor pode ser representada pela combinação de 4 valores de intensidade
    // para R (Red), G (Green), B (Blue) e A (Alpha). Esses valores podem ser
    // guardados em um registro com 4 inteiros de 8 bits (0-255) ou por um valor
    // inteiro de 32 bits codificado com os 4 valores. Construa uma união para
    // armazenar uma cor. Em seguida construa uma função para ler do usuário uma
    // cor no formato RGBA e outra para ler uma cor no formato inteiro de 32 bits.
    // Ambas as funções devem receber o endereço de uma variável do tipo cor e
    // modificar a variável recebida, sem retornar valor.

    Cores cor1;

        lerCorRGBA(&cor1);

        lerCorInt(&cor1);

    return 0;
}