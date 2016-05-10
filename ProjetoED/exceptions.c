#include "cabecalho.h"

void fim_menu (int e){
    switch(e){
        case 1:
            puts("Opção errada\n");
            getch();
            menu();
            break;
        default:
            exit(1);
            break;
    }
}
void fim_atvd(int op){
    printf("\nPressione 1 para Reiniciar ou 0 para Voltar ao Menu Principal\n");
    char num;
    num = getche();
    switch(op){
        case 1:
            if(num == '1')
                atvd1();
            break;
        case 2:
            if(num == '1')
                atvd2();
            break;
        case 3:
            if(num == '1')
                atvd3();
            break;
        case 4:
            if(num == '1')
                atvd4();
            break;
    }
    menu();
}
void fim_pilha(int op){
    printf("\nPressione 1 para Reiniciar ou 0 para Voltar ao Menu Principal\n");
    char num;
    num = getche();
    switch(op){
    case 1:
        if(num == '1')
            pilha_estatica();
        break;
    case 2:
        if(num == '1')
            pilha_dinamica();
        break;
    }
    menu();
}

