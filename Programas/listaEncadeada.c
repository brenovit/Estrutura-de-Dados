#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
typedef int tp_item;

typedef struct tp_no{                                   ///estrutura da lista,
    tp_item info;                                       ///este ser� o dado que estara contido no n�
    struct tp_no *prox;                                 ///este ponteiro estara apontando para uma estrutura semelhante a esta
}tplista;                                               ///nome da estrutura

tplista* inicializa();                                  ///inicializar a lista
int lista_vazia(tplista *lista);                        ///checar se a lista ta vazia
tplista* aloca();                                       ///aloca memoria do tamanho de uma lista
int inserir_final(tplista **lista, tp_item e);          ///esta fun��o ira inserir um novo n� no final da lista
void listagem(tplista *lista);                          ///esta fun��o ira listar todos os elementos contidos na lsita
void libera_lista(tplista **lista);                     ///esta fun��o ira limpar toda lista(liberar o espa�o em memoria)
int tamanho_lista(tplista **lista);                     ///esta fun��o ira retornar o tamanho da lista

void main(){
    setlocale(LC_ALL,"");
    tplista *lista;                                     ///cria��o de um ponteiro da lista
    tp_item e;
    lista = inicializa();                               ///inicializando a lista(seu valor ser� nulo)

    inserir_final(&lista,10);
    inserir_final(&lista,20);
    inserir_final(&lista,30);

    //libera_lista(&lista);

    if(lista_vazia(lista)){                             ///executa a fun��o que checa se esta fun��o se diferente de 0
        printf("A lista esta vazia\n");
    }else{                                              ///sen�o
        printf("A lista n�o esta vazia\n");
    }
    printf("\nQuantidade de n�s presente na lista: %d\n\n",tamanho_lista(&lista));
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

    atu = *lista;                                        ///o ponteiro atu vai receber o valor que a 'lista' aponta , a 'lista' vira um ponteiro de indire��o, pois aponta para um ponteiro
    ant = NULL;                                          ///o n� anteriro receber nulo
    novo_no->info = e;                                   ///o ponteiro que recebeu o endere�o de memoria alocada vai salvar em info o valor inserido no parametro
    novo_no->prox = NULL;

    while(atu != NULL){                                  ///enquanto o ponteiro n�o apontar para nulo
        ant = atu;                                       ///o ponteiro anterior vai apontar para o ponteiro atual
        atu = atu->prox;                                 ///o ponteiro atual vai apontar para o proximo n� que que ele aponta
    }
    ///esta parte vai ser executada na primeira vez que a lista for executada.
    if(ant == NULL){                                     ///se o ponteiro anterior for nulo(quer dizer que ela esta vazia)
        *lista = novo_no;                                ///o valor da lista, vai ser o novo n� criado
    }else{
        ant->prox = novo_no;
    }
    return 1;
}

void listagem(tplista *lista){                          ///esta fun��o lista todos os elementos contido em uma lista
    tplista *atu;                                       ///cria-se um ponteiro do tipo tplista
    atu = lista;                                        ///este ponteiro vai receber a lista passada como parametro
    while(atu != NULL){                                 ///la�o que vai passaar por toda a lista, at� o seu valor se tornar nulo
        printf("Valor na lista: %d\n",atu->info);       ///mostra o dado(info) contido na lista
        atu = atu->prox;                                ///diz para o ponteiro 'atu', que ele vai receber o n�, que o n� atual aponta
    }
}

int tamanho_lista(tplista **lista){                     ///esta fun��o ira retornar o tamanho da lista, percorrendo cada elemento
    if(lista_vazia(lista))                              ///verifica se a lista esta vazia
        return 0;
    int cont = 0;                                       ///cria-se um contador
    tplista *no = *lista;                               ///cria-se um n�, que recebe o primeiro n� da lista passado como parametro
    while(no != NULL){                                  ///enquanto este n� n�o for nulo
        cont++;                                         ///o contador aumenta
        no = no->prox;                                  ///o n� vai apontar para o proximo n�
    }
    return cont;
}

void libera_lista(tplista **lista){                     ///esta fun��o vai limpar toda a lista
    tplista *no;                                        ///cria-se uma nova lista
    if(!lista_vazia(lista)){                            ///verifica se a lista n�o � nula
        while((*lista) != NULL){                        ///enquanto existir n� dentro da lista
            no = *lista;                                ///o novo n� vai receber o primeiro n� da lista
            *lista = (*lista)->prox;                    ///esta lista vai avan�ar para o n� que ela aponta
            free(no);                                   ///libera a memoria do n�
        }
        free(lista);                                    ///por fim, a lista � liberada por completo da memoria
    }
}
