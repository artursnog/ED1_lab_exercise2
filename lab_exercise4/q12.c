#include <stdio.h>

/*Construa um programa que leia do usuário uma sequência de números
inteiros, até que o número zero seja lido. Os números devem ser armazenados
em um arquivo binário chamado “vet.dat”. O primeiro número do arquivo deve
ser a quantidade de números digitados. Na entrada do programa verifique se o
arquivo existe e, caso positivo, exiba os valores do vetor.
*/

int main(){
    FILE *arq = fopen("vet.dat", "rb");
    if (arq != NULL){
        int n;
        fread(&n, sizeof(int), 1, arq);
        int vet[n];
        fread(vet, sizeof(int), n, arq);
        for (int i = 0; i < n; i++){
            printf("%d ", vet[i]);
        }
        printf("\n");
        fclose(arq);
    }

    arq = fopen("vet.dat", "wb");
    int vet[100];
    int aux = 0;
    while (1){
        printf("Digite um numero inteiro: ");
        scanf("%d", &vet[aux]);
        if (vet[aux] == 0){
            fwrite(&aux, sizeof(int), 1, arq);
            fwrite(vet, sizeof(int), aux, arq);
            break;
        }
        aux++;
    }

    fclose(arq);
    return 0;
}