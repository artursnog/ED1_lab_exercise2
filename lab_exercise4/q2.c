#include <stdio.h>

/*Escreva um programa para ler todos os números do texto e gravá-los em outro
arquivo. */

int main(){
    FILE *arq = fopen("texto.txt", "r");
    FILE *arq2 = fopen("numeros.txt", "w");
    
    char c;
    int e_num = 0;
    while((c = fgetc(arq)) != EOF){
        if(c >= '0' && c <= '9'){
            fputc(c, arq2);
            e_num = 1;
        } else if (e_num) {
            fputc('\n', arq2);
            e_num = 0;
        }
    }

    printf("Numeros copiados com sucesso!\n");
    fclose(arq);
    fclose(arq2);
    return 0;
}