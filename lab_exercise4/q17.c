#include <stdio.h>

/*Crie uma união chamada Senha com os campos Alfanumérica e Numérica.
Na função principal pergunte ao usuário se ele quer exibir a senha armazenada
ou gravar uma nova senha no arquivo. Se o arquivo não tiver sido criado ainda,
a opção de exibição não deve fazer nada, a não ser avisar o usuário que o
arquivo não existe.
Use um arquivo binário para guardar a senha. Na gravação da senha, grave
primeiro um número para representar o tipo da senha. O modo alfanumérico
será correspondente ao número 1, e o modo simplesmente numérico será
correspondente ao 2. Quando o usuário abrir o programa e selecionar a opção
de exibição, o tipo da senha deve ser lido para decidir qual campo da união
apresentar na tela (campo alfanumérico ou o campo numérico).*/

typedef union{
    char alfanumerica[20];
    int numerica;
}Senha;

int main(){
    FILE *arq = fopen("senha.bin", "rb");
    char opcao;
    printf("Voce deseja exibir a senha armazenada ou gravar uma nova senha? [E]xibir/[G]ravar\n");
    scanf(" %c", &opcao);
    if(opcao == 'E'){
        if(arq == NULL){
            printf("Arquivo nao existe\n");
        }
        else{
            Senha senha;
            int tipo;
            fread(&tipo, sizeof(int), 1, arq);
            if(tipo == 1){
                fread(senha.alfanumerica, sizeof(char), 20, arq);
                printf("Senha: %s\n", senha.alfanumerica);
            }
            else if(tipo == 2){
                fread(&senha.numerica, sizeof(int), 1, arq);
                printf("Senha: %d\n", senha.numerica);
            }
            fclose(arq);
        }
    }
    else if(opcao == 'G'){
        arq = fopen("senha.bin", "wb");
        Senha senha;
        int tipo;
        printf("Digite o tipo da senha (1 para alfanumerica, 2 para numerica): ");
        scanf("%d", &tipo);
        fwrite(&tipo, sizeof(int), 1, arq);
        if(tipo == 1){
            printf("Digite a senha alfanumerica: ");
            scanf("%s", senha.alfanumerica);
            fwrite(senha.alfanumerica, sizeof(char), 20, arq);
        }
        else if(tipo == 2){
            printf("Digite a senha numerica: ");
            scanf("%d", &senha.numerica);
            fwrite(&senha.numerica, sizeof(int), 1, arq);
        }
        fclose(arq);
    }
    
    return 0;
}