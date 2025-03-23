#include <stdio.h>
/*Construa um programa que leia um arquivo texto contendo o nome e as três
notas de vários alunos (uma quantidade indefinida de alunos). Escreva em outro
arquivo texto o nome e a situação do aluno (aprovado, quarta prova ou
reprovado).*/

int main(){
    FILE *arq = fopen("alunos.txt", "r");
    FILE *arq2 = fopen("situacao.txt", "w");

    char nome[100];
    float n1, n2, n3, media;
    while (fscanf(arq, "%s %f %f %f", nome, &n1, &n2, &n3) != EOF){
        media = (n1+n2+n3)/3;
        if(media >= 7){
            fprintf(arq2, "%s Aprovado\n", nome);
        } else if (media < 4){
            fprintf(arq2, "%s Reprovado\n", nome);
        } else {
            fprintf(arq2, "%s Quarta Prova\n", nome);
        }
    }

    printf("Situação dos alunos escrita com sucesso!\n");
    fclose(arq);
    fclose(arq2);
    return 0;
}