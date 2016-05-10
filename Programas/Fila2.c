/*Scrip de manipulaão de FILA ou FIFO First In First Out
Feito por André Gondim */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int tp_item;

typedef struct {
    tp_item item[MAX];
    int inicio, fim;
}tp_fila;

int dado[MAX];
int topo;
int op;

int inserir(tp_fila *f);
int remover(tp_fila *f, int e);
int ta_vazia(tp_fila *f);
int inicia_fila();

int ta_vazia(){

}

void exibir(void){
    if (topo == 0){
        printf("A pilha esta vazia\n");
    }
    else{
        int temp;
        for(temp=0;topo-1 >= temp ;temp++){
            printf("Na posicao %d temos %d\n",temp,dado[temp]);
        }
    }
    system("PAUSE");
}

int inserir(){
    if (topo==MAX){
          printf("A pilha esta cheia, OverFlow\n");
      }
      else {
           printf("Digite o valor para entrar na pilha: \n");
           scanf("%d",&dado[topo]);
           topo++;
           }
     exibir();
     return 0;
}

int remover(tp_fila *f, int e){
    if (topo==0){
        printf("A pilha esta vazia\n");
    }
    else {
        printf("Elemento %d removido\n",dado[0]);
        int i;
        for (i=0;i<=topo-1;i++){
            dado[i] = x[i+1];
        }
    }
    topo--;;
    exibir();
    return 0;
}

int menu(){
    printf("-= Programa Fila em C =-\n\n");
    printf("   Para inserir digite      1\n");
    printf("   Para remover digite      2\n");
    printf("   Para exibir digite       3\n\n");
    printf("   Para sair                4\n");
    op = getch();
    switch (op){
        case 1 : inserir();
             break;
        case 2 : remover(dado);
             break;
        case 3 : exibir();
             break;
           }
    return 0;
}


int main(){
    topo=0;
    while (op!=4){
          system("cls");
          menu();
          }
    return 0;
}
