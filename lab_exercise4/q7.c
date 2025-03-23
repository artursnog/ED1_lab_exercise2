#include <stdio.h>
/*Uma palavra é um palíndromo se a sequência de letras que a forma é a
mesma quando lida da esquerda para a direita ou da direita para a esquerda (ex:
raiar). Escreva uma função que seja capaz de descobrir se uma palavra é um
palíndromo. Nesta verificação desconsidere maiúsculas e minúsculas (i.e. Ana é
um palíndromo).
O programa deve ler um número indefinido de palavras de um arquivo texto e,
para cada palavra, verificar se ela é ou não um palíndromo. Exiba a quantidade
de palíndromos encontrados no texto, bem como as palavras que são
palíndromos*/

int main(){
    FILE *arq = fopen("palavras.txt", "r");
    char palavra[50];
    int palindromos = 0;
    
    while (fscanf(arq, "%s", palavra) != EOF){
        int i = 0;
        int j = 0;

        while (palavra[j] != '\0'){
            j++;
        }

        if (j > 1){
            j--;
            
            while (i < j){
                if (palavra[i] != palavra[j]){
                    break;
                }
                i++;
                j--;
            }
            
            if (i >= j){
                palindromos++;
                printf("%s e um palindromo\n", palavra);
            }
        }
    }
        printf("Total de palindromos: %d\n", palindromos);
        fclose(arq);
        return 0;
    }