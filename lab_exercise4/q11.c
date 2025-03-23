#include <stdio.h>

/*Escreva um programa que leia um valor inteiro do usuário e armazene-o em
um arquivo binário chamado “interger.bin”. Ao entrar, o programa deve
verificar se o arquivo “integer.bin” existe, e em caso positivo, deve ler e exibir o
número na tela.
*/

int main(){
    FILE *arq = fopen("integer.bin", "rb");

    int n;
    if (arq != NULL){
        arq = fopen("integer.bin", "rb+");
        fread(&n, sizeof(int), 1, arq);
        printf("Arquivo integer.bin encontrado!\nEle contem o numero %d.\n", n);
        fclose(arq);
    }
    
    arq = fopen("integer.bin", "wb");
    printf("Digite um numero inteiro: ");
    scanf("%d", &n);
    fwrite(&n, sizeof(int), 1, arq);
    printf("Numero armazenado no arquivo integer.bin.\n");
    fclose(arq);

    return 0;
}