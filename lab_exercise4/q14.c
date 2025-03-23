#include <stdio.h>
#include <stdlib.h>

/*No exercício anterior, se o usuário digitar apenas espaços para a mensagem,
o resultado será uma faixa colorida com a cor de fundo. Podemos usar isso para
criar uma imagem formada apenas por caracteres de espaço coloridos.
Construa um programa que peça a largura e altura da imagem e leia do usuário
uma matriz de números. Cada número de 3 dígitos representa a cor de um
“bloco” da imagem. Guarde em um arquivo binário os valores de altura, largura
e de cada bloco da imagem. Assim como o programa anterior, construa um
menu para controlar as opções de armazenamento e exibição da imagem.
*/

int main(){
    FILE *arq;

    int largura, altura;
    int **imagem;
    int **aux;
    char opcao;
    int i, j;
    while (1){
        printf("Imagem Colorida\n--------------------\n[A]rmazenar\n[E]xibir\n[S]air\n--------------------\nOpcao: ");
        scanf(" %c", &opcao);
        if (opcao == 'A'){
            arq = fopen("imagem.bin", "ab");
            if (arq == NULL) {
                perror("Erro ao abrir o arquivo imagem.bin");
                return 1;
            }

            printf("Digite a largura da imagem: ");
            scanf("%d", &largura);
            printf("Digite a altura da imagem: ");
            scanf("%d", &altura);
            imagem = (int **)malloc(altura * sizeof(int *));
            for (i = 0; i < altura; i++){
                imagem[i] = (int *)malloc(largura * sizeof(int));
            }

            for (i = 0; i < altura; i++){
                for (j = 0; j < largura; j++){
                    printf("Digite a cor do bloco %d %d: ", i, j);
                    scanf("%d", &imagem[i][j]);
                }
            }

            fwrite(&largura, sizeof(int), 1, arq);
            fwrite(&altura, sizeof(int), 1, arq);
            for (i = 0; i < altura; i++){
                for (j = 0; j < largura; j++){
                    fwrite(&imagem[i][j], sizeof(int), 1, arq);
                }
            }

            printf("Imagem colorida foi armazenada.\n");
            fclose(arq);

            for (i = 0; i < altura; i++){
                free(imagem[i]);
            }
            free(imagem);
        }
        else if (opcao == 'E'){
            arq = fopen("imagem.bin", "rb");
            
            if (arq == NULL) {
                perror("Erro ao abrir o arquivo imagem.bin");
                return 1;
            }

            fseek(arq, 0, SEEK_SET);
            fread(&largura, sizeof(int), 1, arq);
            fread(&altura, sizeof(int), 1, arq);
            aux = (int **)malloc(altura * sizeof(int *));
            for (i = 0; i < altura; i++){
                aux[i] = (int *)malloc(largura * sizeof(int));
            }

            for (i = 0; i < altura; i++){
                for (j = 0; j < largura; j++){
                    fread(&aux[i][j], sizeof(int), 1, arq);
                }
            }

            for (i = 0; i < altura; i++){
                for (j = 0; j < largura; j++){
                    printf("\033[38;5;%dm\033[48;5;%dm  \033[0m",
                           aux[i][j], aux[i][j]);
                }
                printf("\n");
            }

            for (i = 0; i < altura; i++){
                free(aux[i]);
            }
            
            free(aux);
            fclose(arq);
        }
        else if (opcao == 'S'){
            break;
        }
        else{
            printf("Opcao invalida\n");
        }
    }
    return 0;
}