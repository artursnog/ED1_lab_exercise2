#include <stdio.h>
#include <stdlib.h>
/*Inicie o programa perguntando ao usuário quantos inteiros ele deseja
armazenar em um vetor. Use a informação digitada para criar um vetor
dinâmico com o espaço necessário para armazenar a quantidade de inteiros
desejada. Depois disso, deixe que o próprio usuário preencha o vetor, utilizando
o tamanho do vetor como condição de parada de um laço for. Mostre o vetor
que foi preenchido através de outro laço e libere o espaço alocado
dinamicamente ao final do programa.
*/
int main(){
    int n;
    printf("Quantos inteiros deseja armazenar? ");
    scanf("%d", &n);
    int *vetor = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        printf("Digite o %dº inteiro: ", i+1);
        scanf("%d", &vetor[i]);

    }
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    free(vetor);
    
    return 0;
}
