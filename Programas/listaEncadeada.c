#include <stdio.h>
#include <stdlib.h>

typedef int tp_item;

typedef struct tp_no{                                   ///estrutura da lista,
    tp_item info;                                       ///este será o dado que estara contido no nó
    struct tp_no *prox;                                 ///este ponteiro estara apontando para uma estrutura semelhante a esta
}tplista;                                               ///nome da estrutura

tplista* inicializa();                                  ///inicializar a lista
int lista_vazia(tplista *lista);                        ///checar se a lista ta vazia
tplista* aloca();                                       ///aloca memoria do tamanho de uma lista
int inserir_final(tplista **lista, tp_item e);
void listagem(tplista *lista);

void main(){
    tplista *lista;                                     ///criação de um ponteiro da lista
    tp_item e;
    lista = inicializa();                               ///inicializando a lista(seu valor será nulo)
    if(lista_vazia(lista)){                             ///executa a função que checa se esta função se diferente de 0
        printf("A lista esta vazia\n");
    }else{                                              ///senão
        printf("A lista não esta vazia\n");
    }
    inserir_final(&lista,10);
    inserir_final(&lista,20);
    inserir_final(&lista,30);

    listagem(lista);
}

tplista *inicializa(){                                  ///esta função que é um ponteiro de lista
    return NULL;                                        ///alterando seu valor para null
}

int lista_vazia(tplista *lista){                        ///esta função checa se a lista esta apontando para nulo
    if(lista == NULL)                                   ///se alista aponta para null
        return 1;                                       ///retorna 1 - verdadeiro
    return 0;                                           ///senão 0, falso
}

tplista* aloca(){                                       ///esta função ira alocar memoria para uma lista
    tplista* pt;                                        ///cria um ponteiro que recebera o endereço de memoria alocado
    pt = (tplista*)malloc(sizeof(tplista));             ///aloca memoria no sistema, (convertendo) esta alocação pra o tipo de ponteiro para tplista do tamanho de um tplista
    return pt;                                          ///retorna o ponteiro com o endereço de memoria alocada
}

int inserir_final(tplista **lista, tp_item e){           ///esta função vair inserir na lista '**lista' o elemento 'e'
    tplista *novo_no;                                    ///cria um ponteiro que vai receber o end de memoria alocads
    tplista *atu, *ant;                                  ///estes ponteiros vão navegar todos os nós da lista, apontado para o nó atual e o nó que ele aponta
    novo_no = aloca();                                   ///o ponteiro esta armazenando o end de memoria alocada

    if(novo_no == NULL)                                  ///verifica se o ponteiro recebeu null, traduzindo, não foi possivel alocar memoria, (o malloc vai informar isso)
        return 0;                                        ///não conseguiu alocar memoria

    atu = *lista;                                        ///o ponteiro ant vai receber o valor que o 'l' aponta , o 'l' vira um ponteiro de indireção, pois ponta para um ponteiro
    ant = NULL;
    novo_no->info = e;                                   ///o ponteiro que recebeu o endereço de memoria alocada vai salvar em info o valor inserido no parametro
    novo_no->prox = NULL;

    while(atu != NULL){                                  ///enquanto o ponteiro não apontar para nulo
        ant = atu;                                       ///o ponteiro anterior vai apontar para o ponteiro atual
        atu = atu->prox;                                 ///o ponteiro atual vai apontar para o proximo nó que que ele aponta
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
