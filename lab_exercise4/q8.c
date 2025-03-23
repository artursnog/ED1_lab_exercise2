#include <stdio.h>

/*Uma escola deseja fazer uma competição intercalasses com seus alunos. A
secretaria da escola montou um arquivo texto com a lista dos alunos
interessados em participar da competição. A listagem contém o nome do aluno e
um código que indica o turno (manhã ou tarde) e a série (6ª, 7ª ou 8ª), como no
exemplo abaixo:
Anita Torcano T6
Joao Paulo M7
Crie um registro para representar um aluno, leia as informações do arquivo e
guarde em um vetor de alunos. Em seguida use laços e testes condicionais para
separar e exibir os alunos agrupados por turno e série
a) Seria possível separar os alunos por sexo usando os dados fornecidos no
programa? Descreva sua solução.
Não, pois não há informação sobre o sexo dos alunos.

b) Se fosse possível adicionar novas informações aos dados, qual seria a
forma mais fácil de conseguir fazer essa separação por sexo?
A partir de um caractere F ou M no final da linha ou após o nome do aluno mesmo, indicando o sexo do aluno.
*/

typedef struct{
    char nome[20];
    char sobrenome[25];
    char turno;
    int serie;
}Alunos;

int main(){
    FILE *arq = fopen("alunos.txt", "r");
    Alunos alunos[100];
    int aux = 0;

    while (fscanf(arq, "%s %s %c%d", alunos[aux].nome, alunos[aux].sobrenome, &alunos[aux].turno, &alunos[aux].serie) != EOF){
        aux++;

    }
    
    printf("Matutino 6a Serie\n");
    for (int i = 0; i < aux; i++) {
        if (alunos[i].turno == 'M' && alunos[i].serie == 6) {
            printf("%s %s\n", alunos[i].nome, alunos[i].sobrenome);
        }
    }

    printf("\nMatutino 7a Serie\n");
    for (int i = 0; i < aux; i++) {
        if (alunos[i].turno == 'M' && alunos[i].serie == 7) {
            printf("%s %s\n", alunos[i].nome, alunos[i].sobrenome);
        }
    }

    printf("\nMatutino 8a Serie\n");
    for (int i = 0; i < aux; i++) {
        if (alunos[i].turno == 'M' && alunos[i].serie == 8) {
            printf("%s %s\n", alunos[i].nome, alunos[i].sobrenome);
        }
    }

    printf("\nVespertino 6a Serie\n");
    for (int i = 0; i < aux; i++) {
        if (alunos[i].turno == 'T' && alunos[i].serie == 6) {
            printf("%s %s\n", alunos[i].nome, alunos[i].sobrenome);
        }
    }

    printf("\nVespertino 7a Serie\n");
    for (int i = 0; i < aux; i++) {
        if (alunos[i].turno == 'T' && alunos[i].serie == 7) {
            printf("%s %s\n", alunos[i].nome, alunos[i].sobrenome);
        }
    }

    printf("\nVespertino 8a Serie\n");
    for (int i = 0; i < aux; i++) {
        if (alunos[i].turno == 'T' && alunos[i].serie == 8) {
            printf("%s %s\n", alunos[i].nome, alunos[i].sobrenome);
        }
    }
    
    fclose(arq);
    return 0;
}