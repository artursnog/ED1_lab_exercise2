#include <stdio.h>
#include <string.h>

/* Escreva um programa que peça ao usuário para digitar um nome de arquivo
texto e uma palavra que ele deseja procurar neste arquivo. O programa deve
dizer se a palavra está ou não presente no arquivo*/

int main(){
    FILE *arq;
    char nome[20];
    char palavra[50];
    char palavraArquivo[50];
    int i = 0;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nome);
    arq = fopen(nome, "r");
    if (arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    printf("Digite a palavra que quer: ");
    scanf("%s", palavra);

    while (fscanf(arq, "%s", palavraArquivo) != EOF){
        if (strcmp(palavra, palavraArquivo) == 0){
            printf("A palavra esta presente no arquivo\n");
            fclose(arq);
            i = 1;
            break;
        }
    }

    if (i == 0){
        printf("A palavra nao está presente no arquivo\n");
    }
    fclose(arq);
    return 0;
}