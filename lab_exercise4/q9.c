#include <stdio.h>
/*Use o registro peixe definido abaixo
a) Construa um programa que leia do usuário os dados de um único peixe e
salve-os em um arquivo binário. Cada execução do programa deve acrescentar
um peixe ao arquivo.
b) Modifique o programa obtido no item anterior para ler e exibir os peixes
cadastrados no arquivo binário antes de permitir que o usuário faça um
novo cadastro.*/

typedef struct{
    char nome[20];
    unsigned peso;
    float comp;
}Peixe;

int main(){
    FILE *arq = fopen("peixes.bin", "ab");
    Peixe p;
    while (1){

        printf("Digite o nome do peixe: ");
        scanf("%s", p.nome);
        printf("Digite o peso do peixe: ");
        scanf("%u", &p.peso);
        printf("Digite o comprimento do peixe: ");
        scanf("%f", &p.comp);
        fwrite(&p, sizeof(Peixe), 1, arq);
        fclose(arq);
        printf("Deseja cadastrar outro peixe? (s/n)");
        char c;
        scanf(" %c", &c);
        if (c == 'n')
        {
            break;
        }
        else if (c == 's')
        {
            arq = fopen("peixes.bin", "ab+");
            fread(&p, sizeof(Peixe), 1, arq);
            printf("Nome: %s\nPeso: %u\nComprimento: %.2f\n", p.nome, p.peso, p.comp);
        }
        else
        {
            printf("Opcao invalida\n");
            break;
        }
        
    }
    return 0;
}