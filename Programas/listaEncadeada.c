#include <stdio.h>
#include <stdlib.h>

typedef int tp_item;

typedef struct tp_no{                                   ///estrutura da lista,
    tp_item info;                                       ///este ser� o dado que estara contido no n�
    struct tp_no *prox;                                 ///este ponteiro estara apontando para uma estrutura semelhante a esta
}tplista;                                               ///nome da estrutura

tplista* inicializa();                                  ///inicializar a lista
int lista_vazia(tplista *lista);                        ///checar se a lista ta vazia
tplista* aloca();                                       ///aloca memoria do tamanho de uma lista
int inserir_final(tplista **lista, tp_item e);
void listagem(tplista *lista);

void main(){
    tplista *lista;                                     ///cria��o de um ponteiro da lista
    tp_item e;
    lista = inicializa();                               ///inicializando a lista(seu valor ser� nulo)
    if(lista_vazia(lista)){                             ///executa a fun��o que checa se esta fun��o se diferente de 0
        printf("A lista esta vazia\n");
    }else{                                              ///sen�o
        printf("A lista n�o esta vazia\n");
    }
    inserir_final(&lista,10);
    inserir_final(&lista,20);
    inserir_final(&lista,30);

    listagem(lista);
}

tplista *inicializa(){                                  ///esta fun��o que � um ponteiro de lista
    return NULL;                                        ///alterando seu valor para null
}

int lista_vazia(tplista *lista){                        ///esta fun��o checa se a lista esta apontando para nulo
    if(lista == NULL)                                   ///se alista aponta para null
        return 1;                                       ///retorna 1 - verdadeiro
    return 0;                                           ///sen�o 0, falso
}

tplista* aloca(){                                       ///esta fun��o ira alocar memoria para uma lista
    tplista* pt;                                        ///cria um ponteiro que recebera o endere�o de memoria alocado
    pt = (tplista*)malloc(sizeof(tplista));             ///aloca memoria no sistema, (convertendo) esta aloca��o pra o tipo de ponteiro para tplista do tamanho de um tplista
    return pt;                                          ///retorna o ponteiro com o endere�o de memoria alocada
}

int inserir_final(tplista **lista, tp_item e){           ///esta fun��o vair inserir na lista '**lista' o elemento 'e'
    tplista *novo_no;                                    ///cria um ponteiro que vai receber o end de memoria alocads
    tplista *atu, *ant;                                  ///estes ponteiros v�o navegar todos os n�s da lista, apontado para o n� atual e o n� que ele aponta
    novo_no = aloca();                                   ///o ponteiro esta armazenando o end de memoria alocada

    if(novo_no == NULL)                                  ///verifica se o ponteiro recebeu null, traduzindo, n�o foi possivel alocar memoria, (o malloc vai informar isso)
        return 0;                                        ///n�o conseguiu alocar memoria

    atu = *lista;                                        ///o ponteiro ant vai receber o valor que o 'l' aponta , o 'l' vira um ponteiro de indire��o, pois ponta para um ponteiro
    ant = NULL;
    novo_no->info = e;                                   ///o ponteiro que recebeu o endere�o de memoria alocada vai salvar em info o valor inserido no parametro
    novo_no->prox = NULL;

    while(atu != NULL){                                  ///enquanto o ponteiro n�o apontar para nulo
        ant = atu;                                       ///o ponteiro anterior vai apontar para o ponteiro atual
        atu = atu->prox;                                 ///o ponteiro atual vai apontar para o proximo n� que que ele aponta
    }
    ///esta parte vai ser executada na primeira vez da lista.
    if(ant == NULL){
        *lista = novo_no;
    }else{
        ant->prox = novo_no;
    }
    return 1;
}

void listagem(tplista *lista){
    tplista *atu;
    atu = lista;
    while(atu != NULL){
        printf("Valor na lista: %d\n",atu->info);
        atu = atu->prox;
    }
}
