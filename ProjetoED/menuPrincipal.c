#include "cabecalho.h"

void menu() {
    system("color f0");
    //sistema de horario formatado
    time_t horario;                     ///para trabalhar com tempo, cria-se uma variavel do tipo time_t
    struct tm * horainfo;               ///estrutura para receber o tempo
    char buffer [80];                   ///variavel que vai receber o horario

    time (&horario);                    ///função time recebe a variavel horario
    horainfo = localtime (&horario);
    ///strftime(local-que-a-string-será-salva,tamanho-maximo,"string e o formato",valor)
    strftime (buffer,80,"Horário: %c",horainfo);

    char op;

    system("cls");
    printf("\n\t\t___________%s___________",buffer);
    printf("\n\t\t|               ESTRUTURA  DE  DADOS             |");
    printf("\n\t\t|________________________________________________|");
    printf("\n\t\t|                 MENU  PRINCIPAL                |");
    printf("\n\t\t|________________________________________________|");
    printf("\n\t\t|                                                |");
    printf("\n\t\t| [1] - Menu Pilha                               |");
    printf("\n\t\t| [2] - Fila                                     |");
    printf("\n\t\t| [3] - Atividades                               |");
    printf("\n\t\t| [0] - Sair                                     |");
    printf("\n\t\t|________________________________________________|");

    printf("\n\nDigite a opção desejada: ");
    op=getche();                        //com a função getche não é necessario apertar enter para entrar
    printf("\n");                                    //a função getche esta contida na bibliiteca conio.h
    switch(op)
    {
        case '1':
            menuP();
            break;
        case '2':
            menuF();
            break;
        case '3':
            menuAvd();
            break;
        case '0':
            exit(0);
            break;
         default:                //opcão errada
            fim_menu(1);
            break;
    }
}
