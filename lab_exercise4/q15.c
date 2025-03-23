#include <stdio.h>

/*Crie um programa que grave os 100 primeiros números naturais ao mesmo
tempo em um arquivo texto e em um arquivo binário. Compare os tamanhos
dos arquivos e explique como os tipos escolhidos para guardar os números
podem tornar o arquivo binário menor ou maior que o arquivo texto.*/

int main(){
    FILE *arq = fopen("numerosnat.txt", "w");
    FILE *arq2 = fopen("numerosbin.bin", "wb");

    int n = 100;
    for (int i = 0; i < n; i++){
        fprintf(arq, "%d ", i);
        fwrite(&i, sizeof(int), 1, arq2);
    }
    
    fclose(arq);
    fclose(arq2);
    return 0;
}
/*O arquivobin.bin ficou com 400 bytes e o arquivonat.txt ficou com 290 bytes.
Isso ocorre porque o arquivo binário armazena os números inteiros em 4 bytes cada,
enquanto o arquivo texto armazena os números inteiros em 1 byte cada. 
Portanto, o arquivo binário é maior que o arquivo texto.*/