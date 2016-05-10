#include "cabecalho.h"

int menuAvd(){
    system("color f0");
    SetConsoleTitle("Estrutura de Dados - Menu Atividades - Breno");
    setlocale(LC_ALL,"Portuguese");
    //sistema de horario formatado
    time_t horario;                     ///para trabalhar com tempo, cria-se uma variavel do tipo time_t
    struct tm * horainfo;               ///estrutura para receber o tempo
    char buffer [80];                   ///variavel que vai receber o horario

    time (&horario);                    ///função time recebe a variavel horario
    horainfo = localtime (&horario);
    ///strftime(local-que-a-string-será-salva,tamanho-maximo,"string e o formato",valor)
    strftime (buffer,80,"Horário: %c",horainfo);

    char equacao[9] = "84/53*+2-";
    tp_item resultado;
    char op;

    system("cls");
    printf("\n\t\t___________%s___________",buffer);
    printf("\n\t\t|               ESTRUTURA  DE  DADOS             |");
    printf("\n\t\t|________________________________________________|");
    printf("\n\t\t|                 MENU  ATIVIDADE                |");
    printf("\n\t\t|________________________________________________|");
    printf("\n\t\t|                                                |");
    printf("\n\t\t| [1] - Atividade 1                              |");
    printf("\n\t\t| [2] - Atividade 2                              |");
    printf("\n\t\t| [3] - Atividade 3                              |");
    printf("\n\t\t| [4] - Atividade 4                              |");
    printf("\n\t\t| [5] - Equação Polonesa                         |");
    printf("\n\t\t| [0] - Sair                                     |");
    printf("\n\t\t|________________________________________________|");
    printf("\n\nDigite a opção desejada: ");
    op=getche();
    printf("\n");
    switch(op)
    {
        case '1':
            atvd1();
            break;
        case '2':
            atvd2();
            break;
        case '3':
            atvd3();
            break;
        case '4':
            atvd4();
            break;
        case '5':
            resultado = EquacaoPolonesa(equacao);
            printf("\nEquação: %s\nResultado da Esquacão: %f\n",equacao, resultado);
            getch();
            break;
        case '0':
            exit(0);
            break;
         default:
            fim_menu(1);
            break;
    }
    return 0;
}
