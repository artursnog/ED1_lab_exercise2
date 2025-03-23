#include <stdio.h>

/*Construa um programa que leia um número desconhecido de peixes de um
arquivo texto (semelhante ao arquivo utilizado na primeira questão) e grave
estas informações em um arquivo binário que possa ser lido pelo programa da
segunda questão. Compare o tamanho dos arquivos texto e binário.
*/

typedef struct{
    char nome[20];
    unsigned peso;
    float comp;
}Peixe;

int main(){
    FILE *arq = fopen("pescado.txt", "r");
    FILE *arq2 = fopen("peixes.bin", "ab");
    Peixe p;

    while (fscanf(arq, "%s %u %f", p.nome, &p.peso, &p.comp) != EOF){
        fwrite(&p, sizeof(Peixe), 1, arq2);
    }

    fclose(arq);
    fclose(arq2);
    return 0;
}