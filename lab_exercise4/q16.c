#include <stdio.h>
/*Crie um registro Soldado com os campos nome, eliminações, mortes, taxa
de eliminação por morte (eliminações/mortes) e número de partidas jogadas. Na
função principal leia um soldado de um arquivo binário. Se o arquivo não
Para existir, você deve direcionar o usuário para a criação de um novo soldado.
Quando o soldado for lido (seja pelo arquivo ou pelo teclado), você deve dar as
seguintes opções ao usuário:*/

typedef struct{
    char nome[20];
    int elim;
    int mortes;
    float taxa;
    int partidas;
}Soldado;

int main(){
    FILE *arq = fopen("soldado.bin", "rb");

    Soldado soldado;
    char opcao;
    if(arq == NULL){
        arq = fopen("soldado.bin", "wb");
        printf("Digite o nome do soldado: ");
        scanf("%s", soldado.nome);
        soldado.elim = 0;
        soldado.mortes = 0;
        soldado.taxa = 0;
        soldado.partidas = 0;
        fwrite(&soldado, sizeof(Soldado), 1, arq);
        fclose(arq);
    }
    else{
        fread(&soldado, sizeof(Soldado), 1, arq);
        fclose(arq);
    }
    while(1){
        printf("[N]ovo soldado\n[A]tualiza soldado\n[E]xibe soldado\n[S]air\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);
        if(opcao == 'N'){
            arq = fopen("soldado.bin", "wb");
            printf("Digite o nome do soldado: ");
            scanf("%s", soldado.nome);
            soldado.elim = 0;
            soldado.mortes = 0;
            soldado.taxa = 0;
            soldado.partidas = 0;
            fwrite(&soldado, sizeof(Soldado), 1, arq);
            fclose(arq);
        }
        else if(opcao == 'A'){
            arq = fopen("soldado.bin", "wb");
            printf("Digite o numero de eliminacoes: ");
            scanf("%d", &soldado.elim);
            printf("Digite o numero de mortes: ");
            scanf("%d", &soldado.mortes);
            soldado.taxa = (float)soldado.elim/soldado.mortes * 100;
            soldado.partidas++;
            fwrite(&soldado, sizeof(Soldado), 1, arq);
            fclose(arq);
        }
        else if(opcao == 'E'){
            printf("-------------------\n");
            printf("Nome: %s\nEliminacoes: %d\nMortes: %d\nTaxa: %.2f%%\nPartidas: %d\n", soldado.nome, soldado.elim, soldado.mortes, soldado.taxa, soldado.partidas);
            printf("-------------------\n");
        }
        else if(opcao == 'S'){
            break;
        }
        else{
            printf("Opcao invalida\n");
        }
    }

    return 0;
}