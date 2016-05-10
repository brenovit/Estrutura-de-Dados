#include "cabecalho.h"

void menuP() {
    system("color f0");
    SetConsoleTitle("Estrutura de Dados - Menu Pilha - Breno");
    setlocale(LC_ALL,"Portuguese");
    //sistema de horario formatado
    time_t horario;                     ///para trabalhar com tempo, cria-se uma variavel do tipo time_t
    struct tm * horainfo;               ///estrutura para receber o tempo
    char buffer [80];                   ///variavel que vai receber o horario

    time (&horario);                    ///fun��o time recebe a variavel horario
    horainfo = localtime (&horario);
    ///strftime(local-que-a-string-ser�-salva,tamanho-maximo,"string e o formato",valor)
    strftime (buffer,80,"Hor�rio: %c",horainfo);

    char op;

    system("cls");
    printf("\n\t\t___________%s___________",buffer);
    printf("\n\t\t|               ESTRUTURA  DE  DADOS             |");
    printf("\n\t\t|________________________________________________|");
    printf("\n\t\t|                   MENU  PILHA                  |");
    printf("\n\t\t|________________________________________________|");
    printf("\n\t\t|                                                |");
    printf("\n\t\t| [1] - Pilha Estatica                           |");
    printf("\n\t\t| [2] - Pilha Dinamica                           |");
    printf("\n\t\t| [3] - Voltar                                   |");
    printf("\n\t\t|________________________________________________|");

    printf("\n\nDigite a op��o desejada: ");
    op=getche();                        //com a fun��o getche n�o � necessario apertar enter para entrar
    printf("\n");                                    //a fun��o getche esta contida na bibliiteca conio.h
    switch(op)
    {
        case '1':
            pilha_estatica();
            break;
        case '2':
            pilha_dinamica();
            break;
        case '3':
            menu();
            break;
         default:                //opc�o errada
            fim_menu(1);
            break;
    }
}
