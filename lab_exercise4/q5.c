#include <stdio.h>

/*Escreva um programa que abra um arquivo texto, leia caractere a caractere
até o fim do arquivo e exiba na tela o número total de caracteres, o número de
vogais, o número de consoantes, e a quantidade de outros caracteres presentes
no texto.*/

int main(){
    FILE *arq = fopen("intro.txt", "r");
        
    char c;
    int total = 0, vogal = 0, consoante = 0, outros = 0;
    while ((c = fgetc(arq)) != EOF){
        total++;
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            vogal++;
        } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            consoante++;
        } else {
            outros++;
        }
    }

    printf("Total de caracteres: %d\n", total);
    printf("Total de vogais: %d\n", vogal);
    printf("Total de consoantes: %d\n", consoante);
    printf("Total de outros caracteres: %d\n", outros);

    fclose(arq);
    return 0;
}