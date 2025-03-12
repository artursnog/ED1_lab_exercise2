#include <stdio.h>

int main(){

    //3º Descubra o que acontece ao tentarmos acessar um ponteiro que contém um
    //endereço inválido. Para isso tente mostrar o conteúdo apontado por um ponteiro
    //recém-criado:
    int *ptr2;
    printf("%d\n", *ptr2);
    
    return 0;
}