#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#define MAX 10               ///tamanho maximo da pilha
#define BASE -1

typedef float tp_item;        ///Dando um apelido a um tipo, otimizando a troca de tipo da pilha

typedef struct {            ///estrutura da pilha
    int topo;               ///representa o topo da pilha
    tp_item item[MAX];      ///vetor que vai representar a pilha
} tp_pilha;

void inicia_pilha(tp_pilha *p);              ///vai criar a pilha(inicializar o topo)
int empilha(tp_pilha *p, tp_item e);         ///bota um elemento na pilha
int desempilha(tp_pilha *p, tp_item *e);     ///tira um elemento da pilha
int verifica_topo(tp_pilha *p, tp_item *e);  ///retorna o valor do topo da pilha
int pilha_vazia(tp_pilha *p);                ///verifica se a pilha esta vazia
int retira_impar(tp_pilha *p);
int ver_pilha(tp_pilha p);
int pilhas_iguais(tp_pilha p1,tp_pilha p2);
int junta_pilha(tp_pilha *p1, tp_pilha *p2);
int recorta_pilha(tp_pilha *pMain, tp_pilha *pDestiny);
float equacao_polonesa(char ex[]);
void menu_pilha();
void configtela();

int main() {
    ///printf("\n=============\n\n=============\n");
    system("color f0");
    //configtela();
    SetConsoleTitle("Estrutura de Dados - Pilha - Breno");
    setlocale(LC_ALL,"Portuguese");

    float e;
    tp_item valor = 0;

    tp_pilha pilha1;         ///cria a pilha1
    tp_pilha pilha2;
    tp_pilha pilha3;

    inicia_pilha(&pilha1);   ///inicia a pilha
    inicia_pilha(&pilha2);
    inicia_pilha(&pilha3);
    //menu_pilha();
    int i;

    char equacao[] = "84/53*+2-";

    e = equacao_polonesa(equacao);
    printf("\nEquação: %s\nResultado da Esquacão: %f\n",equacao, e);

    ///atividade 1
    /*for(i = 1; i < MAX; i++){
        empilha(&pilha1,i);
    }
    empilha(&pilha1,99);
    printf("\n\t===> Pilha 1\n");
    ver_pilha(pilha1);
    while(!(pilha_vazia(&pilha1))){
        desempilha(&pilha1,&e);
        if(e % 3 == 0){
            e = e * 2;
            empilha(&pilha2,e);
        } else {
            e = e * 3;
            empilha(&pilha3,e);
        }
    }
    ///atividade 1
    printf("\n\t===> Pilha 2\n");
    ver_pilha(pilha2);
    printf("\n\t===> Pilha 3\n");
    ver_pilha(pilha3);

    ///junta_pilhas
    printf("\n=============\nValore Inseridos na Pilha 1\n=============\n");
    for(i = 0; i < 3; i++){
        empilha(&pilha2,i);
        verifica_topo(&pilha2,&e);
        printf("\nO Valor [%d] foi Inserido na Pilha 2!",e);
    }
    printf("\n=============\nValore Inseridos na Pilha 2\n=============\n");
    ver_pilha(pilha1);
    printf("\n=============\nPilha 1 Verificada\n=============\n");
    junta_pilha(&pilha2,&pilha1);
    printf("\n=============\nPilhas anexadas\n=============\n");
    ver_pilha(pilha1);
    printf("\n=============\nPilha 1 Verificada\n=============\n");
    ver_pilha(pilha2);
    printf("\n=============\nPilha 2 Verificada\n=============\n");

    /*
    verifica_topo(&pilha1,&e);
    printf("\nValor no topo da Pilha 1: [%d]!",e);
    verifica_topo(&pilha2,&e);
    printf("\nValor no topo da Pilha 2: [%d]!",e);*/
    //ver_pilha(&pilha2);
    ///*/

    ///retira impares
    /*
    for(i = 0; i < MAX; i++){
        empilha(&pilha1,i);
        verifica_topo(&pilha1,&e);
        printf("\nO Valor [%d] foi Inserido na Pilha 1!",e);
    }
    printf("\n=============\nRetirar os Numero Impares\n=============\n");
    retira_impar(&pilha1);
    //ver_pilha(&pilha1);
    ///*/

    ///checa pilhas iguais
    /*/
    for(i = 0; i < MAX; i++){
        empilha(&pilha1,i);
        verifica_topo(&pilha1,&e);
        printf("\nO Valor [%d] foi Inserido na Pilha 2 Destino!",e);
    }
    for(i = 0; i < 3; i++){
        empilha(&pilha2,i);
        verifica_topo(&pilha2,&e);
        printf("\nO Valor [%d] foi Inserido na Pilha 2 Destino!",e);
    }
    /*//*
    for(i = 0; i < MAX; i++){
        empilha(&pilha1,i);
        verifica_topo(&pilha1,&e);
        printf("\nO Valor [%d] foi Inserido na Pilha 2 Destino!",e);
        empilha(&pilha2,i);
        verifica_topo(&pilha2,&e);
        printf("\nO Valor [%d] foi Inserido na Pilha 2 Destino!",e);
    }
    //*//*
    printf("\n\n");
    if(pilhas_iguais(pilha1,pilha2)){
        printf("\n=============\nPilhas 1 e 2 são Iguais!\n=============\n");
    } else {
        printf("\n=============\nPilhas 1 e 2 são Diferentes!\n=============\n");
    }
    //*/
}

void menu_pilha(){
    system("cls");
    printf("\n\t\t\t_________________________________________________");
    printf("\n\t\t\t|                  MENU PILHA                   |");
    printf("\n\t\t\t|_______________________________________________|");
    printf("\n\t\t\t|                                               |");
    printf("\n\t\t\t| 1 - Empilhar                                  |");
    printf("\n\t\t\t| 2 - Desempilhar                               |");
    printf("\n\t\t\t| 3 - Ver Pilha                                 |");
    printf("\n\t\t\t| 4 - Retira Impares                            |");
    printf("\n\t\t\t| 5 - Compara duas Pilhas                       |");
    printf("\n\t\t\t| 6 - Junta duas Pilhas                         |");
    printf("\n\t\t\t| 0 - Sair                                      |");
    printf("\n\t\t\t|_______________________________________________|");
}

void inicia_pilha(tp_pilha *p){         ///o ponteiro p aponta para um item na pilha(struct) -> o topo
    p->topo = BASE;                     ///este topo recebe um valor base, isto é, não aponta para posiçãoa lguma da pilha = -1.
}                                       ///Se o topo estiver valendo -1, quer dizer que a pilha esta vazia.

int empilha(tp_pilha *p, tp_item e){    ///recebe como parametro uma pilha e o valor que será inserido
    if (p->topo == MAX-1){              ///checa se o topo da pilha esta na ultima posição, ou se a pilha esta cheia
        printf("\t\t\tA PILHA DA CHEIA\n");
        return 0;                       ///retorna 0 para falso ou qualquer outro numero como verdadeiro = logica booleana
    }
    p->topo++;                          ///o valor do topo da pilha vai incrementar, isto é, subir
    p->item[p->topo] = e;               ///o item atual da pilha, na posição que o topo se encontra, vai receber o valor do parametro 'e'
    //printf("Empilhei o Valor [%d]!\n",e);
    return 1;                           ///retorna 1 para verdadeiro = logica booleana
}

int desempilha(tp_pilha *p, tp_item *e){
    if (pilha_vazia(p)){                ///if(pilha_vazia(p)==1) - o 'p' de pilha vazia é o mesmo 'p' de tp_pilha entretanto ele esta recebendo o seu valor, um endereço de memoria
        printf("\n\n\t\tNão foi possível remover um item da pilha!\n");
        return 0;                       ///retorna 0 como falso
    } else {
        tp_item temp;                   ///cria uma variavel temporaria que vai
        temp = p->item[p->topo];        ///receber o valor do elemento no topo da pilha
        *e = temp;                      ///o valor da variavel que o ponteiro 'i' esta, vai receber o valor temporario - retorno
        p->topo--;                      ///decrementa a pilha
        //printf("Desempilhei o Valor [%d]!\n",*e);
        return 1;
    }
}

int verifica_topo(tp_pilha *p, tp_item *e){
    if(pilha_vazia(p)){
        printf("\n\n\t\tNão foi possivel verificar a pilha!\n");
        return 0;
    } else {                            ///igual ao desempilha a diferença que esse só retorna o valor no topo.
        tp_item temp;                   ///cria uma variavel temporaria que vai
        temp = p->item[p->topo];        ///receber o valor do elemento no topo da pilha
        *e = temp;                      ///o valor da variavel que o ponteiro 'i' esta, vai receber o valor temporario - retorno
        //printf("\nO Valor no topo da Pilha é: [%d]",*i);
        return 1;
    }
}

int retira_impar(tp_pilha *p){
///1)	Implementar uma função que receba uma pilha como parâmetro
///     e retire todos os elementos ímpares dessa pilha. (Use uma pilha auxiliar).
    tp_pilha pilhaAux;
    inicia_pilha(&pilhaAux);
    int e;
    int i;

    recorta_pilha(p,&pilhaAux);

    //printf("\n=============\nRecortei os elementos da Pilha Principal e Colei na Pilha Auxiliar\n=============\n");
    for(i = pilhaAux.topo; i >= 0; i--){
        //desempilha(&pilhaAux, &e);
        printf("\nO Valor [%d] foi Removido da Pilha Auxiliar!",e);
        if(e % 2 == 0){
            empilha(p,e);
            //printf("\nO Valor [%d] foi Inserido na Pilha!",e);
//            verifica_topo(p,&e);
            printf("\nO Valor [%d] foi Inserido na Pilha Principal!\n",e);
        }
    }
    return 1;
}

int pilhas_iguais(tp_pilha p1,tp_pilha p2){
///2)	Implementar uma função que receba duas pilhas como parâmetro
///     e retorna 1 caso sejam idênticas ou zero caso contrário.
    tp_item e1, e2;
    int i;

    if(p1.topo != p2.topo){
        printf("\n\t\t\tTAMANHO DAS PILHAS DIFERENTES!");
        return 0;
    }

    for(i = p1.topo; i >= 0; i--){
    //while(!(pilha_vazia(&p1))){
        desempilha(&p1, &e1);
        desempilha(&p2, &e2);
        //printf("\nO Valor [%d] foi Removido da Pilha Auxiliar!",e);
        if(e1 != e2){
            return 0;
        }
    }

    return 1;
}

int junta_pilha(tp_pilha *p1, tp_pilha *p2){
///3)	Implementar uma função que receba duas pilhas como parâmetro
///     e empilhe a segunda sobre a primeira. (Use uma pilha auxiliar, além das duas pilhas em questão)
    tp_item e;
    tp_pilha pilhaAux;
    inicia_pilha(&pilhaAux);

    int i;

    /*if((MAX - p1->topo) != p2->topo){
        printf("Tamanho Insuficiente da pilha principal");
        return 0;
    }*/

    recorta_pilha(p1,&pilhaAux);
    recorta_pilha(&pilhaAux,p2);
    return 1;
}

int recorta_pilha(tp_pilha *pMain, tp_pilha *pDestiny){
    //printf("\n=============\nCheguei no Recorta Pilha\n=============\n");
    tp_item e;
    int i;
    for(i = pMain->topo; i >= 0; i--){
        desempilha(pMain, &e);
        //printf("\nO Valor [%d] foi Removido da Pilha Principal!",e);
        empilha(pDestiny,e);
        //printf("\nO Valor [%d] foi Inserido na Pilha Destino!",e);
    }
    return 1;
}

int ver_pilha(tp_pilha p){
    tp_item e;
    int i;

    for(i = p.topo; i >= 0; i--){
        desempilha(&p,&e);
        printf("---\n");
        printf("|%d|\n",e);
    }
    printf("--- \n");
    return 1;
}

int pilha_vazia(tp_pilha *p){ ///verifica se a pilha esta vazia
    if(p->topo == -1){ ///se o valor
        printf("\n\n\t\t\tERRO! PILHA VAZIA");
        //getch();
        return 1;
    } else {
        return 0;       ///pilha tem item
    }
}

float equacao_polonesa(char ex[]){
    tp_pilha pilha;
    float calc, num1, num2, numAux;
    int i;
    char aux[1];

    inicia_pilha(&pilha);
    printf("Cheguei na equação, iniciei a pilha\n");
    for(i = 0; i < 9; i++){
        aux[0] = ex[i];
        //&& (strcmp(aux,"*") != 0) && (strcmp(aux,"-") != 0) && (strcmp(aux,"/") != 0)
        ///if(aux == '+')
        if(strcmp(aux,"+") != 0 || strcmp(aux,"*") != 0 || strcmp(aux,"-") != 0 || strcmp(aux,"/") != 0){
           //printf("\nCheguei na checagem dos operadores\n");

            if(isdigit(aux[0])){
                numAux = strtof(aux,NULL);
                empilha(&pilha, numAux);
                printf("\nEmpilhei: %.0f\n",numAux);
               // printf("\nCheguei no if do isdigit, numAux = %f\n",numAux);
            }
        printf("\naux = %c\n",aux[0]);
        }
        if(strcmp(aux,"+") == 0 || strcmp(aux,"*") == 0 || strcmp(aux,"-") == 0 || strcmp(aux,"/") == 0){
            printf("\naux = %c\n",aux[0]);
            desempilha(&pilha, &num2);
            desempilha(&pilha, &num1);
            switch(aux[0]){
                case '+': calc = num1 + num2;
                printf("\n%f + %f = &f",num1,num2,calc);
                break;
                case '-': calc = num1 - num2;
                printf("\n%f - %f = &f",num1,num2,calc);
                break;
                case '*': calc = num1 * num2;
                printf("\n%f * %f = &f",num1,num2,calc);
                break;
                case '/': calc = num1 / num2;
                printf("\n%f / %f = &f",num1,num2,calc);
                break;
            }
            empilha(&pilha, calc);
           // printf("\nPassei do Switch, calc = %f\n",calc);
        }
    }
    desempilha(&pilha, &calc);
    return calc;
}

void configtela() {//função que configura o tamanho da tela e do buffer
    COORD outbuff;
    outbuff.X = 100; // tem que ser +1 que o tamanho X
    outbuff.Y = 40; // tem que ser +1 que o tamanho Y
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(hConsole, outbuff);
    Sleep(130);
    SMALL_RECT windowSize = {0, 0, 99, 39};
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}

