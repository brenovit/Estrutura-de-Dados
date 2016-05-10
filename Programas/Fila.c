#include <stdio.h>
#include <stdlib.h>
#define MAX 30

typedef int tp_item;

///Estrutura da Fila
typedef struct {
    tp_item item[MAX];
    int inicio, fim;
}tp_fila;

///Escopo das funções
int inserir(tp_fila *f, tp_item e);
int remover(tp_fila *f, tp_item *e);
int ta_vazia(tp_fila *f);
int inicia_fila(tp_fila *f);
int retorna_proximo(tp_fila *f, tp_item *e);
int mostrar_fila(tp_fila f);
int maior_menor_media(tp_fila f, tp_item *maior, tp_item *menor, float *media);
int fila_ordenada(tp_fila *f);
int proximo(int pos);

int main(){
    system("color f0");
    tp_fila fila1, fila2;                   ///crio a fila
    tp_item el, e, maior, menor;            ///crio uma variavel para ser intermediaria
    float media;
    inicia_fila(&fila1);                    ///inicio a fila
    inicia_fila(&fila2);
    int i;

    inserir(&fila1, 1);
    inserir(&fila1, 2);
    inserir(&fila1, 0);
    inserir(&fila1, 4);
    inserir(&fila1, 5);
    inserir(&fila1, 3);
    inserir(&fila1, 2);
    inserir(&fila1, 5);
    inserir(&fila1, 1);
    inserir(&fila1, 0);

    mostrar_fila(fila1);

    fila_ordenada(&fila1);

    mostrar_fila(fila1);

    ///atividade 3
    /*//
    int num;
    for(int i = 0; i < 16; i++){ ///laço para inserir 3 elementos da fila
        //printf("\nDigite um numero:");
        //scanf("%d",&num);
        if((i) % 2 == 0){
            if(!inserir(&fila1, (i))){
                remover(&fila1, &el);
                inserir(&fila1, (i));
            }
        } else {
            if(!remover(&fila1, &el)){
                printf("\n\t\tA FILA TA VAZIA\n");
            }
        }
    }
    while(!ta_vazia(&fila1)){
        remover(&fila1, &el);
        printf("|%d",el);
    }
    printf("|\n");
    printf("\n");
    mostrar_fila(fila1);
    //*/
    ///atividade 3

    ///atividade 2
    /*//
    mostrar_fila(fila1);
    maior_menor_media(fila1, &maior, &menor, &media);
    printf("\n\n========================================\n\tMaior Elemento: %d\n\tMenor Elemento: %d\n\tMedia dos Valores: %.2f\n========================================\n",maior,menor,media);
    */
    ///atividade 2

    printf("\n");
    system("pause");
    return 0;
}

int inicia_fila(tp_fila *f){        ///para iniciar uma fila
    f->inicio = f->fim = MAX-1;     ///os 2 marcadores apontaram para a mesma posição neste caso MAX-1
    return 1;
}

int ta_vazia(tp_fila *f){           ///para saber se uma fila ta vazia
    if(f->inicio == f->fim){        ///checa se o valor do inicio esta igual ao do fim, isto é, ambos apontam para a mesma posição na fila
        return 1;                   ///se forem iguais, retorna 1(true), -> a fila esta vazia
    }
    else {                          ///senão
        return 0;                   ///retorna 0(false) -> a fila tem elemento
    }
}

int inserir(tp_fila *f, tp_item e){     ///para inserir elementos na fila, checa
    if (proximo(f->fim) == f->inicio){  ///se o proximo valor do organizador "fim" é igual ao valor do organizador "inicio"
        //printf("\t\t\tA FILA DA CHEIA\n");
        return 0;                       ///se for, a fila ta cheia, impedindo de inserir elementos.
    }
    else {                              ///senão
        f->fim = proximo(f->fim);       ///o valor do organizador fim será igual a sua proxima posição
        f->item[f->fim] = e;            ///o elemento da fila, na posição que o "fim" aponta, recebera o valor da variavel "e"
        ///printf("O valor [%d] foi inserido na fila.\n",e);
        return 1;
    }
}

int proximo(int pos){
    if(pos == MAX-1){               ///se a posição for igual ao tamanho maximo menos 1
        return 0;                   ///a proxima posição é igual a 0, isto faz com que a fila sempre zere sua posição quando estiver espaço vazio para inserir.
    }
    else{                           ///senão
        return pos+1;               ///retorna a posição indicada + 1
    }
}

int retorna_proximo(tp_fila *f, tp_item *e){
    if (ta_vazia(f)){                   ///se a fila ta vazia
        return 0;
    }
    else {
        *e = f->item[proximo(f->inicio)];        ///o ponterio "e" recebe o valor do elemento na fila, na posição que o "fim" aponta
        return 1;
    }
}

int remover(tp_fila *f, tp_item *e){    ///para remover elementos da fila
    if (ta_vazia(f)){                   ///se a fila estiver vazia
        return 0;                       ///não tem como remover elementos
    }
    else {
        f->inicio = proximo(f->inicio); ///o organizador "inicio" recebe o valor da proxima casa da fila
        *e = f->item[f->inicio];        ///o ponterio "e" recebe o valor do elemento na fila, na posição que o "inicio" aponta
        ///printf("O valor [%d] foi removido na fila.\n",*e);
        return 1;                       ///retorna verdadeiro
    }
}

int maior_menor_media(tp_fila f, tp_item *maior, tp_item *menor, float *media){
    tp_item e;
    int i = 0;
    *maior = 0;
    *menor = 0;
    *media = 0;
    while(!ta_vazia(&f)){
        remover(&f,&e);
        if(i == 0){
           *menor = e;
           i = 1;
        }
        if(e < (*menor)){
            *menor = e;
        }
        if(e > (*maior)){
            *maior = e;
        }
        *media+=e;
    }
    *media = *media / (f.fim+1);
    return 1;
}

int fila_ordenada(tp_fila *f){
    tp_item e, e1, temp;
    int k, j,i;

    if(ta_vazia(f)){
        return 0;
    }
    for(k=0; k < f->fim; k++){
        for(j=0; j < f->fim; j++){
            if(f->item[j] > f->item[j+1]){
                temp = f->item[j];
                f->item[j] = f->item[j+1];
                f->item[j+1] = temp;
            }
            /*printf("Depois da volta: [%2d]",k);
            for(i=0; i < f.fim+1; i++){
                printf("%3d ",f.item[i]);
            }
            printf("\n");*/
        }
    }
    //printf("A fila esta ordenada\n");
    return 1;
}

int mostrar_fila(tp_fila f){
    tp_item e;
    while(!ta_vazia(&f)){
        remover(&f,&e);
        printf("|%d",e);
    }
    printf("|\n");
    return 1;
}
