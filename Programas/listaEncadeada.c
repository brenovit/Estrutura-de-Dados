#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
typedef int tp_item;

typedef struct tp_no{                                   ///estrutura da lista,
    tp_item info;                                       ///este será o dado que estara contido no nó
    struct tp_no *prox;                                 ///este ponteiro estara apontando para uma estrutura semelhante a esta
}tplista;                                               ///nome da estrutura

tplista* inicializa();                                  ///inicializar a lista
int lista_vazia(tplista *lista);                        ///checar se a lista ta vazia
tplista* aloca();                                       ///aloca memoria do tamanho de uma lista
int inserir_final(tplista **lista, tp_item e);          ///esta função ira inserir um novo nó no final da lista
void listagem(tplista *lista);                          ///esta função ira listar todos os elementos contidos na lsita
void libera_lista(tplista **lista);                     ///esta função ira limpar toda lista(liberar o espaço em memoria)
int tamanho_lista(tplista **lista);                     ///esta função ira retornar o tamanho da lista

void main(){
    setlocale(LC_ALL,"");
    tplista *lista;                                     ///criação de um ponteiro da lista
    tp_item e;
    lista = inicializa();                               ///inicializando a lista(seu valor será nulo)

    inserir_final(&lista,10);
    inserir_final(&lista,20);
    inserir_final(&lista,30);

    //libera_lista(&lista);

    if(lista_vazia(lista)){                             ///executa a função que checa se esta função se diferente de 0
        printf("A lista esta vazia\n");
    }else{                                              ///senão
        printf("A lista não esta vazia\n");
    }
    printf("\nQuantidade de nós presente na lista: %d\n\n",tamanho_lista(&lista));
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

    atu = *lista;                                        ///o ponteiro atu vai receber o valor que a 'lista' aponta , a 'lista' vira um ponteiro de indireção, pois aponta para um ponteiro
    ant = NULL;                                          ///o nó anteriro receber nulo
    novo_no->info = e;                                   ///o ponteiro que recebeu o endereço de memoria alocada vai salvar em info o valor inserido no parametro
    novo_no->prox = NULL;

    while(atu != NULL){                                  ///enquanto o ponteiro não apontar para nulo
        ant = atu;                                       ///o ponteiro anterior vai apontar para o ponteiro atual
        atu = atu->prox;                                 ///o ponteiro atual vai apontar para o proximo nó que que ele aponta
    }
    ///esta parte vai ser executada na primeira vez que a lista for executada.
    if(ant == NULL){                                     ///se o ponteiro anterior for nulo(quer dizer que ela esta vazia)
        *lista = novo_no;                                ///o valor da lista, vai ser o novo nó criado
    }else{
        ant->prox = novo_no;
    }
    return 1;
}

void listagem(tplista *lista){                          ///esta função lista todos os elementos contido em uma lista
    tplista *atu;                                       ///cria-se um ponteiro do tipo tplista
    atu = lista;                                        ///este ponteiro vai receber a lista passada como parametro
    while(atu != NULL){                                 ///laço que vai passaar por toda a lista, até o seu valor se tornar nulo
        printf("Valor na lista: %d\n",atu->info);       ///mostra o dado(info) contido na lista
        atu = atu->prox;                                ///diz para o ponteiro 'atu', que ele vai receber o nó, que o nó atual aponta
    }
}

int tamanho_lista(tplista **lista){                     ///esta função ira retornar o tamanho da lista, percorrendo cada elemento
    if(lista_vazia(lista))                              ///verifica se a lista esta vazia
        return 0;
    int cont = 0;                                       ///cria-se um contador
    tplista *no = *lista;                               ///cria-se um nó, que recebe o primeiro nó da lista passado como parametro
    while(no != NULL){                                  ///enquanto este nó não for nulo
        cont++;                                         ///o contador aumenta
        no = no->prox;                                  ///o nó vai apontar para o proximo nó
    }
    return cont;
}

void libera_lista(tplista **lista){                     ///esta função vai limpar toda a lista
    tplista *no;                                        ///cria-se uma nova lista
    if(!lista_vazia(lista)){                            ///verifica se a lista não é nula
        while((*lista) != NULL){                        ///enquanto existir nó dentro da lista
            no = *lista;                                ///o novo nó vai receber o primeiro nó da lista
            *lista = (*lista)->prox;                    ///esta lista vai avançar para o nó que ela aponta
            free(no);                                   ///libera a memoria do nó
        }
        free(lista);                                    ///por fim, a lista é liberada por completo da memoria
    }
}
