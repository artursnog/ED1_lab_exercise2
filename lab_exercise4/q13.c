#include <stdio.h>

/*O Exercício de Revisão 1 do Laboratório 6 (Tipos Inteiros) mostra como
usar códigos de Escape para mudar a cor do texto exibido em um terminal. A
sequência de caracteres "\033[38;5;000;48;5;154m" define a cor 000 para o
texto e 154 para o fundo. Considerando que as cores são valores de 3 dígitos de
000 a 255, construa um programa para ler do usuário um texto com no máximo
80 caracteres, um código para a cor do texto e um código para a cor do fundo.
Guarde essas informações em um arquivo binário. O usuário deve ter a opção de
guardar uma nova frase ou exibir a frase já armazenada através de um menu,
como mostrado no exemplo abaixo.*/

int main(){
    FILE *arq = fopen("cores.bin", "ab");

    char texto[80];
    int corTexto, corFundo;
    char opcao;
    while (1){
        printf("\nMensagens Coloridas\n");
        printf("\n--------------------\n");
        printf("[A]rmazenar\n[E]xibir\n[S]air\n");
        printf("--------------------\nOpcao: ");
        scanf(" %c", &opcao);
        if (opcao == 'A'){
            printf("Sua mensagem: ");
            scanf(" %s", texto);
            printf("Cor do texto: ");
            scanf("%d", &corTexto);
            printf("Cor do fundo: ");
            scanf("%d", &corFundo);
            fwrite(texto, sizeof(char), 80, arq);
            fwrite(&corTexto, sizeof(int), 1, arq);
            fwrite(&corFundo, sizeof(int), 1, arq);
            printf("Texto colorido foi armazenado.\n");
        }
        else if (opcao == 'E'){
            fseek(arq, 0, SEEK_SET);
            fread(texto, sizeof(char), 80, arq);
            fread(&corTexto, sizeof(int), 1, arq);
            fread(&corFundo, sizeof(int), 1, arq);
            printf("\033[38;5;%d;48;5;%dm%s\033[0m\n", corTexto, corFundo, texto);
        }
        else if (opcao == 'S'){
            break;
        }
        else{
            printf("Opcao invalida\n");
        }
    }

    fclose(arq);
    return 0;
}