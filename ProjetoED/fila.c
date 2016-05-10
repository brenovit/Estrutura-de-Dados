#include "cabecalho.h"

int inicia_fila(tp_fila *f){        ///para iniciar uma fila
    f->inicio = f->fim = MAX-1;     ///os 2 marcadores apontaram para a mesma posição neste caso MAX-1
    return 1;
}

int fila_ta_vazia(tp_fila *f){      ///para saber se uma fila ta vazia
    if(f->inicio == f->fim){        ///checa se o valor do inicio esta igual ao do fim, isto é, ambos apontam para a mesma posição na fila
        return 1;                   ///se forem iguais, retorna 1(true), -> a fila esta vazia
    }
    else {                          ///senão
        return 0;                   ///retorna 0(false) -> a fila tem elemento
    }
}

int inserir_fila(tp_fila *f, tp_item e){     ///para inserir_fila elementos na fila, checa
    if (proximo(f->fim) == f->inicio){       ///se o proximo valor do organizador "fim" é igual ao valor do organizador "inicio"
        return 0;                            ///se for, a fila ta cheia, impedindo de inserir_fila elementos.
    }
    else {                                   ///senão
        f->fim = proximo(f->fim);            ///o valor do organizador fim será igual a sua proxima posição
        f->item[f->fim] = e;                 ///o elemento da fila, na posição que o "fim" aponta, recebera o valor da variavel "e"
        return 1;
    }
}

int proximo(int pos){
    if(pos == MAX-1){               ///se a posição for igual ao tamanho maximo menos 1
        return 0;                   ///a proxima posição é igual a 0, isto faz com que a fila sempre zere sua posição quando estiver espaço vazio para inserir_fila.
    }
    else{                           ///senão
        return pos+1;               ///retorna a posição indicada + 1
    }
}

int retorna_proximo(tp_fila *f, tp_item *e){
    if (fila_ta_vazia(f)){                       ///se a fila ta vazia
        return 0;
    }
    else {
        *e = f->item[proximo(f->inicio)];        ///o ponterio "e" recebe o valor do elemento na fila, na posição que o "fim" aponta
        return 1;
    }
}

int remover_fila(tp_fila *f, tp_item *e){    ///para remover_fila elementos da fila
    if (fila_ta_vazia(f)){                   ///se a fila estiver vazia
        return 0;                            ///não tem como remover_fila elementos
    }
    else {
        f->inicio = proximo(f->inicio); ///o organizador "inicio" recebe o valor da proxima casa da fila
        *e = f->item[f->inicio];        ///o ponterio "e" recebe o valor do elemento na fila, na posição que o "inicio" aponta
        return 1;                       ///retorna verdadeiro
    }
}

int maior_menor_media_fila(tp_fila f, tp_item *maior, tp_item *menor, float *media){
    tp_item e;
    int i = 0;
    *maior = 0;
    *menor = 0;
    *media = 0;
    while(!fila_ta_vazia(&f)){
        remover_fila(&f,&e);
        if(i == 0){
            *maior = e;
            *menor = e;
        }
        if(e <= (*menor)){
            *menor = e;
        }
        if(e >= (*maior)){
            *maior = e;
        }
        *media+=e;
        i++;
    }
    *media = *media / i;
    return 1;
}

int fila_ordenada(tp_fila *f){
    tp_item temp;
    int k, j;

    if(fila_ta_vazia(f)){
        return 0;
    }
    for(k=0; k < f->fim; k++){
        for(j=0; j < f->fim; j++){
            if(f->item[j] > f->item[j+1]){
                temp = f->item[j];
                f->item[j] = f->item[j+1];
                f->item[j+1] = temp;
            }
        }
    }
    return 1;
}

int mostrar_fila(tp_fila f){
    tp_item e;
    while(!fila_ta_vazia(&f)){
        remover_fila(&f,&e);
        printf("|%d",e);
    }
    printf("|\n");
    return 1;
}

int limpa_fila(tp_fila *f){
    tp_item e;
    do{
        remover_fila(f,&e);
    }while(!fila_ta_vazia(f));
    return 1;
}

int fila_checa_par(tp_fila *f, tp_item e){
    tp_item el;
    /*if((e) % 2 == 0){
        if(!inserir_fila(f, (e))){
            remover_fila(f, &el);
            inserir_fila(f, (e));
        }
    } else {
        if(!remover_fila(f, &el)){
            printf("\n\t\tA FILA TA VAZIA\n");
            return 0;
        }
    }*/
    return 1;
}
