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

int inserir_inicio(tplista **lista, tp_item e);         ///função de inserir nós no inicio da lista
int inserir_oredenado(tplista **lista, tp_item e);      ///função de inserir nós de forma ordenada na lista
int inserir_final(tplista **lista, tp_item e);          ///função de inserir nós no final da lista

int remover_inicio(tplista **lista, tp_item *e);        ///função para remover o primeiro nó da lista
int remover_meio(tplista **lista, tp_item *e);          ///função para remover um nó com um certo valor
int remover_final(tplista **lista, tp_item *e);         ///função para remover o ultimo nó da lista

void listagem(tplista *lista);                          ///esta função ira listar todos os elementos contidos na lsita
void libera_lista(tplista **lista);                     ///esta função ira limpar toda lista(liberar o espaço em memoria)
int tamanho_lista(tplista **lista);                     ///esta função ira retornar o tamanho da lista

void manipular_lista_inicio();                          ///esta função vai manipular a lista pelo inicio
void manipular_lista_meio();                            ///esta função vai manipular a lista pelo meio ou de forma ordenada
void manipular_lista_final();                           ///esta função vai manipular a lista pelo final

int buscar_pelo_elemento(tplista **lista, tp_item e);   ///esta função ira buscar por um nó na lista de ocordo com o valor que ele tiver
int buscar_pela_posicaoo(tplista **lista, int pos, tp_item *e);///esta função ira buscar por um nó na lista de ocordo com a posição dele na lista
tplista *buscar_pelo_elemento_end(tplista *lista, tp_item e);

int main(){
    setlocale(LC_ALL,"");
    tplista *lista;                                     ///criação de um ponteiro da lista
    tp_item e;
    lista = inicializa();                               ///inicializando a lista(seu valor será nulo)
    libera_lista(&lista);                               ///limpa a lista

    //manipular_lista_inicio();
    //manipular_lista_meio();
    manipular_lista_final();

    system("pause");
    return 1;
}

void manipular_lista_inicio(){
    tplista *lista;                                     ///criação de um ponteiro da lista
    tp_item e = 10;
    lista = inicializa();                               ///inicializando a lista(seu valor será nulo)

    ///===== - Inicio - =============================== - Teste de Inserir no Inicio da Lista
    inserir_inicio(&lista,10);
    inserir_inicio(&lista,20);
    inserir_inicio(&lista,30);

    if(lista_vazia(lista)){                             ///executa a função que checa se a lista ta vazia(se diferente de 0)
        printf("\nA lista esta vazia\n");
    } else {                                            ///senão
        printf("\nA lista não esta vazia\n");
    }

    printf("\nQuantidade de nós presente na lista: %d\n",tamanho_lista(&lista));

    listagem(lista);                                    ///mostra os valores presentes nos nós da lista

    if(buscar_pela_posicaoo(&lista, 2, &e))
        printf("\nO valor do nó na Segunda posição é: %d \n",e);

    e = 20;

    if(buscar_pelo_elemento(&lista, e))
        printf("\nO elemento [%d] foi encontrado na lista\n",e);
    else
        printf("\nNão foi encontrado o elemento [%d]\n",e);

    tplista *lista2 = buscar_pelo_elemento(&lista, e);
        printf("\nO elemento [%d] foi encontrado na lista em {%d}\n",e,&lista2);

    /*if(remover_inicio(&lista,&e))
        printf("\nElemento [%d] removido com Sucesso do Inicio da Lista\n\n",e);

    printf("\nQuantidade de nós presente na lista: %d\n\n",tamanho_lista(&lista));

    listagem(lista);*/
    ///===== - Fim - ================================== - Teste de Inserir no Inicio da Lista

    libera_lista(&lista);                               ///limpa a lista
}

void manipular_lista_meio(){
    tplista *lista;                                     ///criação de um ponteiro da lista
    tp_item e = 20;
    lista = inicializa();                               ///inicializando a lista(seu valor será nulo)

    ///===== - Inicio - =============================== - Teste de Inserir de modo Ordenado na Lista
    inserir_oredenado(&lista,20);
    inserir_oredenado(&lista,30);
    inserir_oredenado(&lista,10);

    if(lista_vazia(lista)){                             ///executa a função que checa se a lista ta vazia(se diferente de 0)
        printf("\nA lista esta vazia\n");
    }else{                                              ///senão
        printf("\nA lista não esta vazia\n");
    }

    printf("\nQuantidade de nós presente na lista: %d\n\n",tamanho_lista(&lista));

    listagem(lista);                                    ///mostra os valores presentes nos nós da lista

    if(remover_meio(&lista,&e))
        printf("\nElemento [%d] removido com Sucesso da Lista\n",e);

    printf("\nQuantidade de nós presente na lista: %d\n\n",tamanho_lista(&lista));

    listagem(lista);
    ///===== - Fim - ================================== - Teste de Inserir de modo Ordenado na Lista

    libera_lista(&lista);                               ///limpa a lista
}

void manipular_lista_final(){
    tplista *lista;                                     ///criação de um ponteiro da lista
    tp_item e;
    lista = inicializa();                               ///inicializando a lista(seu valor será nulo)

    ///===== - Inicio - =============================== - Teste de Inserir no Final da Lista
    inserir_final(&lista,10);
    inserir_final(&lista,20);
    inserir_final(&lista,30);

    if(lista_vazia(lista)){                             ///executa a função que checa se a lista ta vazia(se diferente de 0)
        printf("\nA lista esta vazia\n");
    }else{                                              ///senão
        printf("\nA lista não esta vazia\n");
    }

    printf("\nQuantidade de nós presente na lista: %d\n",tamanho_lista(&lista));

    listagem(lista);                                    ///mostra os valores presentes nos nós da lista

    if(remover_final(&lista,&e))
        printf("\nElemento [%d] removido com Sucesso do Final da Lista\n\n",e);

    printf("\nQuantidade de nós presente na lista: %d\n\n",tamanho_lista(&lista));

    listagem(lista);
    ///===== - Fim - ================================== - Teste de Inserir no Final da Lista

    libera_lista(&lista);                               ///limpa a lista
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

void listagem(tplista *lista){                          ///esta função lista todos os elementos contido em uma lista
    tplista *atu;                                       ///cria-se um ponteiro do tipo tplista
    atu = lista;                                        ///este ponteiro vai receber a lista passada como parametro
    while(atu != NULL){                                 ///laço que vai passaar por toda a lista, até o seu valor se tornar nulo
        printf("Valor na lista: %d\n",atu->info);       ///mostra o dado(info) contido na lista
        atu = atu->prox;                                ///diz para o ponteiro 'atu', que ele vai receber o nó, que o nó atual aponta
    }
}

int tamanho_lista(tplista **lista){                     ///esta função ira retornar o tamanho da lista, percorrendo cada elemento
    if(lista_vazia(*lista))                             ///verifica se a lista esta vazia
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
    if(!lista_vazia(*lista)){                           ///verifica se a lista não é nula
        while((*lista) != NULL){                        ///enquanto existir nó dentro da lista
            no = *lista;                                ///o novo nó vai receber o primeiro nó da lista
            *lista = (*lista)->prox;                    ///esta lista vai avançar para o nó que ela aponta
            free(no);                                   ///libera a memoria do nó
        }
        free(lista);                                    ///por fim, a lista é liberada por completo da memoria
    }
}

int inserir_inicio(tplista **lista, tp_item e){         ///esta função ira inserir novos nós no final da lista
    if(lista == NULL)                                   ///checa se a lista existe
        return 0;
    tplista *novo_no;                                   ///cria o novo nó
    novo_no = aloca();                                  ///aloca memoria para ele

    if(novo_no == NULL)                                 ///checa se o nó foi alocado com sucesso
        return 0;

    novo_no->info = e;                                  ///passa para a info desse nó o valor passado como parametro
    novo_no->prox = (*lista);                           ///faz com que este nó aponte para o mesmo lugar que a lista aponta

    *lista = novo_no;                                   ///agora a lista esta apontando para o novo nó

    return 1;
}

int inserir_oredenado (tplista **lista, tp_item e){     ///esta função ira inserir um novo nó de forma ordenada na lista
    if(lista == NULL)                                   ///checa se a lista existe
        return 0;
    tplista *novo_no;                                   ///cria o novo nó
    novo_no = aloca();                                  ///aloca memoria para ele

    if(novo_no == NULL)                                 ///checa se o nó foi alocado com sucesso
        return 0;

    novo_no->info = e;                                  ///passa para a info desse nó o valor passado como parametro
    if(lista_vazia(*lista)){                            ///checa se a lista esta vazia, para inserir no primeiro elemento
        novo_no->prox = (*lista);                       ///o novo nó vai receber a lista
        *lista = novo_no;                               ///a lista recebe o novo nó
        return 1;                                       ///sai da inserção

    } else {                                            ///se a lista não estiver vazia, vai procurar o local para inserir
        tplista *atu, *ant;                             ///estes ponteiros vão navegar todos os nós da lista, apontado para o nó atual e o proximo nó que ele aponta
        atu = *lista;                                   ///o ponteiro atual recebe a lista e faz um laço, verificando
        while(atu != NULL && atu->info < e){            ///se enquanto o atual não for nulo, e o valor dele for menor que o valor do elemento passado como parametro
            ant = atu;                                  ///o anterior recebe o atual
            atu = atu->prox;                            ///e o atual aponta para o proximo
        }                                               ///quando chegar no fim, alguma das checagens serão falsas
        if(atu == *lista){                              ///aqui ele checa se o nó atual é igual a lista(subtende-se que esta no inicio)
            novo_no->prox = (*lista);                   ///faz com que este nó aponte para o mesmo lugar que a lista aponta
            *lista = novo_no;                           ///e a lista aponta para o novo nó
        } else {                                        ///senão
            novo_no->prox = ant->prox;                  ///o novo nó vai apontar para o proximo nó que o anterior aponta
            ant->prox = novo_no;                        ///e o anterior vai apontar para o novo nó, inserindo assim no meio da lista;
        }
        return 1;
    }
}

int inserir_final(tplista **lista, tp_item e){          ///esta função vair inserir na lista '**lista' o elemento 'e'
    tplista *novo_no;                                   ///cria um ponteiro que vai receber o end de memoria alocads
    tplista *aux;                                       ///estes ponteiros vão navegar todos os nós da lista, apontado para o nó atual e o nó que ele aponta
    novo_no = aloca();                                  ///o ponteiro esta armazenando o end de memoria alocada

    if(novo_no == NULL)                                 ///verifica se o ponteiro recebeu null, traduzindo, não foi possivel alocar memoria, (o malloc vai informar isso)
        return 0;                                       ///não conseguiu alocar memoria

    novo_no->info = e;                                  ///o ponteiro que recebeu o endereço de memoria alocada vai salvar em info o valor inserido no parametro
    novo_no->prox = NULL;

    if((*lista) == NULL){                               ///checa se a lista esta vazia, para inserir no primeiro elemento
        *lista = novo_no;                               ///a lista vai apontar para o nó criado
    } else {                                            ///se não estiver vazia
        aux = *lista;                                   ///a lista auxiliar vai receber a lista passada como parametro
        while(aux->prox != NULL){                       ///enquanto o nó que a auxiliar aponta não for nulo
            aux = aux ->prox;                           ///a auxiliar vai apontar para o proximo nó que que ela aponta
        }
        aux->prox = novo_no;                            ///por fim, quando chegar no ultimo nó, ele vai apontar para o nó criado
    }
    return 1;
}

int remover_inicio(tplista **lista, tp_item *e){        ///função para remover o primeiro nó da lista
    if(lista == NULL)                                   ///checa se a lista existe
        return 0;
    if(lista_vazia(*lista))                             ///checa se a lista esta vazia
        return 0;

    tplista *no = *lista;                               ///cria-se um novo nó, que aponta para a lista
    *e = no->info;                                      ///o valor que estiver neste nó vais er passado para o parametro 'e'
    *lista = no->prox;                                  ///a lista vai apontar para o proximo nó que o novo nó aponta
    free(no);                                           ///por fim o novo nó é liberado da memoria
    return 1;
}

int remover_meio(tplista **lista, tp_item *e){          ///função para remover um nó com um certo valor
    if(lista == NULL)                                   ///checa se a lista existe
        return 0;
    if(lista_vazia(*lista))                             ///checa se a lista esta vazia
        return 0;
    tplista *ant, *atu = *lista;                        ///cria-se 2 ponteiros para percorrer a lista, o ponteiro 'atu' vai receber a lista
    while(atu != NULL && atu->info != *e){              ///enquanto o atu não for nulo e o valor que estiver nele for diferente do valor passado como parametro
        ant = atu;                                      ///o nó anterior vai receber o atu
        atu = atu->prox;                                ///o atu vai apontar para o proximo nó que ele aponta
    }

    if(atu == NULL)                                     ///checa se o valor é nulo
        return 0;                                       ///isto é, não foi encontrado

    if(atu == *lista){                                  ///se foi encontrado, ele checa se vai remover o primeiro
        *lista = atu->prox;                             ///então a lista vai apontar para o proximo nó que o atu aponta
    } else {                                            ///senão
        ant->prox = atu->prox;                          ///o proximo nó que o nó anterior aponta vai apontar para o proximo nó que o atu aponta
    }
    free(atu);                                          ///por fim o atu que agora foi encontrado é liberado da memoria
    return 1;
}

int remover_final(tplista **lista, tp_item *e){         ///função para remover o ultimo nó da lista
    if(lista == NULL)                                   ///checa se a lista existe
        return 0;
    if(lista_vazia(*lista))                             ///checa se a lista esta vazia
        return 0;

    tplista *ant, *atu = *lista;                        ///cria-se 2 ponteiros para percorrer a lista, o ponteiro 'atu' vai receber a lista
    while(atu->prox != NULL){                           ///este laço vai percorrer toda a lista até que o proximo nó do atu seja nulo
        ant = atu;                                      ///o potneiro anterior recebe o atu
        atu = atu->prox;                                ///e o 'atu' vai apontar para o proximo nó que ele aponta
    }
    *e = atu->info;
    if(atu == (*lista)){                                ///se o atu for igual a lista(quer dizer que é o primeiro)
        *lista = atu->prox;                             ///a lista vai apontar para o proximo nó que o atu aponta
    } else {                                            ///senão
        ant->prox = atu->prox;                          ///o proximo nó que que o anterior aponta, vai apontar para o proximo nó que o 'atu' aponta
    }
    free(atu);                                          ///por fim, o atu é liberado
    return 1;
}

int buscar_pelo_elemento(tplista **lista, tp_item e){   ///esta função ira buscar por um nó na lista de ocordo com o valor que ele tiver
    if(lista == NULL)                                   ///checa se a lista existe ou esta vazia
        return 0;

    tplista *atu = *lista;                              ///cria-se um novo nó, recebendo a lista

    while(atu != NULL && atu->info != e){               ///enquanto o atu não for nulo e o valor de info contido neste nó for diferente do parametro 'e'
        atu = atu->prox;                                ///o atu vai apontar o proximo nó que ele aponta
    }
    if(atu == NULL)                                     ///se o atu for nulo
        return 0;                                       ///quer dizer que nada foi encontrado
    else{                                               ///senão
        return 1;                                       ///retorna 1 informando que foi encontrado o dado
    }
}

tplista *buscar_pelo_elemento_end(tplista *lista, tp_item e){   ///esta função ira buscar por um nó na lista de ocordo com o valor que ele tiver e retornar o endereço de memoria
    if(lista == NULL)                                   ///checa se a lista existe ou esta vazia
        return NULL;

    //tplista *atu = *lista;                          ///cria-se um novo nó, recebendo a lista

    while(lista != NULL && lista->info != e){           ///enquanto o atu não for nulo e o valor de info contido neste nó for diferente do parametro 'e'
        lista = lista->prox;                            ///o atu vai apontar o proximo nó que ele aponta
    }
    if(lista == NULL)                                   ///se o atu for nulo
        return NULL;                                    ///quer dizer que nada foi encontrado
    else{                                               ///senão
        return lista;                                   ///retorna 1 informando que foi encontrado o dado
    }
}

int buscar_pela_posicaoo(tplista **lista, int pos, tp_item *e){///esta função ira buscar por um nó na lista de ocordo com a posição dele na lista
    if(lista == NULL || pos <= 0)                       ///checa se a lista existe
        return 0;
    if(lista_vazia(*lista))                             ///checa se a lista esta vazia
        return 0;
    tplista *atu = *lista;                              ///cria-se um novo no para recebendo a lista
    int i = 1;                                          ///cria-se uma varivel intermediaria para filtrar as posições
    while(atu != NULL && i < pos){                      ///enquanto o atu não for nulo e o valor de i for menor que o valor do paramentro pos
        atu = atu->prox;                                ///o atu vai apontar o proximo nó que ele aponta
        i++;                                            ///o 'i' incrementa
    }
    if(atu == NULL)                                     ///se o atu for nulo
        return 0;                                       ///quer dizer que nada foi encontrado
    else{                                               ///senão
        *e = atu->info;                                 ///o parametro 'e' vai receber o valor da info contida no nó encontrado
        return 1;                                       ///retorna um informando que tudo ocorreu normal
    }
}
