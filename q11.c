#include <stdio.h>

enum TipoImagem{
    JPG,
    PNG,
    BMP
};
typedef struct{
    char nome[20];
    int altura;
    int largura;
    enum TipoImagem tipo;
}Imagem;

void Detalhes(Imagem *img){
    switch (img->tipo)
    {
        case  JPG:
            printf("A imagem \"%s\" com tamanho %dX%d tem formato JPG.\n", img->nome, img->altura, img->largura);
            break;
        case PNG:
            printf("A imagem \"%s\" com tamanho %dX%d tem formato PNG.\n", img->nome, img->altura, img->largura);
            break;
        case BMP:
            printf("A imagem \"%s\" com tamanho %dX%d tem formato BMP.\n", img->nome, img->altura, img->largura);
            break;
        default:
            printf("Formato de imagem inválido.\n");
            break;
    }
}

int main(){
    
    //11º Crie um registro Imagem que contenha campos para nome, altura, largura e
    //tipo, sendo o tipo um dos seguintes valores: JPG, PNG ou BMP. Use uma
    //enumeração para guardar o tipo da imagem. No programa principal inicialize
    //uma variável do tipo Imagem e passe seu endereço para uma função Detalhes.
    //A função deve receber o endereço de uma Imagem e exibir os seus dados no
    //formato do exemplo abaixo.
    Imagem imagem = {"imagem.jpg", 1920, 1080, JPG};
    Imagem *arqImg = &imagem;
    Detalhes(arqImg);

    return 0;
}