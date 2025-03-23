#include <stdio.h>
/*Considerando o arquivo texto apresentado, o que o trecho de código abaixo
faz?
Ele irá imprimir o primeiro caractere do arquivo*/
/*Modifique o programa para ler do arquivo texto:
a) O oitavo caractere
b) Uma palavra
c) A quinta palavra
d) Uma linha*/
int main(){

    FILE *fin;
    fin = fopen("intro.txt", "r");

    char ch;
    for (int i = 0; i < 8; i++)
    {
        ch = fgetc(fin);
    }
    rewind(fin);

    char palavra[10];
    for (int i = 0; i < 3; i++)
    {
        fscanf(fin, "%s", palavra);
        
    }
    rewind(fin);

    char quinta[20];
    for (int i = 0; i < 5; i++)
    {
        fscanf(fin, "%s", quinta);
    }
    rewind(fin);

    char linha[100];
    fgets(linha, 100, fin);
    fclose(fin);

    printf("O oitavo caractere: %c\n", ch);
    printf("Uma palavra: %s\n", palavra);
    printf("A quinta palavra: %s\n", quinta);
    printf("Uma linha: %s\n", linha);
    
    return 0;
}
