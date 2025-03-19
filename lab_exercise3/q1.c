#include <stdio.h>
#include <stdlib.h>

/*Crie um programa que peça ao usuário para digitar o número de alunos em
uma turma. O programa deve usar essa informação para criar um vetor dinâmico
que armazene as notas finais desses alunos. Peça ao usuário para entrar com a
nota de dois alunos e em seguida mostre essas notas usando cout*/

int main(){
    int n;
    printf("Digite o número de alunos: ");
    scanf("%d", &n);
    float *notas = (float*)malloc(n*sizeof(float));
    for(int i = 0; i < n; i++){
        printf("Digite a nota do aluno %d: ", i+1);
        scanf("%f", &notas[i]);
    }
    for(int i = 0; i < n; i++){
        printf("Nota do aluno %d: %.2f\n", i+1, notas[i]);
    }
    free(notas);
    return 0;
}