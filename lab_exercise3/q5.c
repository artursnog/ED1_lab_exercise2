#include <stdio.h>
#include <stdlib.h>
/*Construa um vetor dinâmico de alunos. O registro aluno deve ser composto
por nome (ou matrícula), código da disciplina (número inteiro sem sinal), e
situação da disciplina. A situação da disciplina deve ser uma enumeração com
os valores: Aprovado, Trancado, Reprovado. Peça ao usuário para digitar o
número de alunos do vetor e em seguida leia os dados do primeiro aluno. Para
finalizar mostre os dados do primeiro aluno usando uma função que recebe um
ponteiro para aluno.*/

enum Situacao{
    Aprovado,
    Trancado,
    Reprovado
};

typedef struct{
    char nome[20];
    unsigned int codigo;
    enum Situacao situacao;
}Aluno;

void mostrarAluno(Aluno *aluno) {
    printf("Nome: %s\nCodigo: %d\nSituacao: ", aluno->nome, aluno->codigo);
    switch (aluno->situacao) {
        case Aprovado:
            printf("Aprovado\n");
            break;
        case Trancado:
            printf("Trancado\n");
            break;
        case Reprovado:
            printf("Reprovado\n");
            break;
    }
}

int main(){
    int n;
    int situacao;
    printf("Digite o numero de alunos: ");
    scanf("%d", &n);
    Aluno *aluno = (Aluno*)malloc(n*sizeof(Aluno));
    for (int i = 0; i < n; i++)
    {   
        printf("Digite o nome do aluno: ");
        scanf("%s", aluno[i].nome);
        printf("Digite o codigo da disciplina: ");
        scanf("%d", &aluno[i].codigo);
        printf("Digite a situacao do aluno (0 - Aprovado, 1 - Trancado, 2 - Reprovado): ");
        scanf("%d", &situacao);
        aluno[i].situacao = situacao;
    }
    
    

    mostrarAluno(&aluno[0]);
    return 0;
}
