#include "cabecalho.h"

void configtela();
int main() {
    setlocale(LC_ALL,"Portuguese");
    //configtela();
    SetConsoleTitle("Estrutura de Dados - Menu Principal - Breno");
    menu();
    //pilha();
    return 0;
}

void configtela()//função que configura o tamanho da tela e do buffer
{
    COORD outbuff;
    outbuff.X = 120; // tem que ser +1 que o tamanho X
    outbuff.Y = 45; // tem que ser +1 que o tamanho Y
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(hConsole, outbuff);
    Sleep(130);
    SMALL_RECT windowSize = {0, 0, 119, 44};
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}
