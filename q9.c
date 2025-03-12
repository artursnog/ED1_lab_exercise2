#include <stdio.h>

typedef struct
{
    int horas;
    int minutos;
}Horario;

void MostrarHorario(Horario *horario){
    int h, m;
    h = horario->horas;
    m = horario->minutos;
    printf("Que horas são? ");
    scanf("%d:%d", &h,&m);
    if (horario->minutos == m && horario->horas == h)
    {
        printf("Horário correto\n");
    }else{
        printf("Horário incorreto, sao %d:%d\n", horario->horas, horario->minutos);
    }
    
}



int main(){

    //9° Declare um registro Horário com os campos horas e minutos. Crie uma
    //função MostrarHorario que deve receber um ponteiro para um Horário e
    //mostrá-lo no formato HH:MM. Na função principal, declare uma variável do
    //tipo Horário e um ponteiro que aponta para ela. Peça que o usuário digite o
    //horário atual e guarde-o na variável. Usando o ponteiro, incremente o horário
    //recebido em uma hora e em seguida mostre o horário corrigido com MostrarHorario.

    Horario horario = {4, 20};
    Horario *p = &horario;
    MostrarHorario(p);
    

    
    return 0;
}