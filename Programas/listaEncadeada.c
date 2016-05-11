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

int inserir_inicio(tplista **lista, tp_item e);         ///fun��o de inserir n�s no inicio da lista
int inserir_oredenado(tplista **lista, tp_item e);      ///fun��o de inserir n�s de forma ordenada na lista
int inserir_final(tplista **lista, tp_item e);          ///fun��o de inserir n�s no final da lista

int remover_inicio(tplista **lista, tp_item *e);        ///fun��o para remover o primeiro n� da lista
int remover_meio(tplista **lista, tp_item *e);          ///fun��o para remover um n� com um certo valor
int remover_final(tplista **lista, tp_item *e);         ///fun��o para remover o ultimo n� da lista

void listagem(tplista *lista);                          ///esta fun��o ira listar todos os elementos contidos na lsita
void libera_lista(tplista **lista);                     ///esta fun��o ira limpar toda lista(liberar o espa�o em memoria)
int tamanho_lista(tplista **lista);                     ///esta fun��o ira retornar o tamanho da lista

void manipular_lista_inicio();                          ///esta fun��o vai manipular a lista pelo inicio
void manipular_lista_meio();                            ///esta fun��o vai manipular a lista pelo meio ou de forma ordenada
void manipular_lista_final();                           ///esta fun��o vai manipular a lista pelo final

int buscar_pelo_elemento(tplista **lista, tp_item e);   ///esta fun��o ira buscar por um n� na lista de ocordo com o valor que ele tiver
int buscar_pela_posicaoo(tplista **lista, int pos, tp_item *e);///esta fun��o ira buscar por um n� na lista de ocordo com a posi��o dele na lista

void main(){
    setlocale(LC_ALL,"");
    tplista *lista;                                     ///cria��o de um ponteiro da lista
    tp_item e;
    lista = inicializa();                               ///inicializando a lista(seu valor ser� nulo)
    libera_lista(&lista);                               ///limpa a lista

    manipular_lista_inicio();
    //manipular_lista_meio();
    //manipular_lista_final();
}

void manipular_lista_inicio(){
    tplista *lista;                                     ///cria��o de um ponteiro da lista
    tp_item e = 10;
    lista = inicializa();                               ///inicializando a lista(seu valor ser� nulo)

    ///===== - Inicio - =============================== - Teste de Inserir no Inicio da Lista
    inserir_inicio(&lista,10);
    inserir_inicio(&lista,20);
    inserir_inicio(&lista,30);

    if(lista_vazia(lista)){                             ///executa a fun��o que checa se a lista ta vazia(se diferente de 0)
        printf("\nA lista esta vazia\n");
    } else {                                            ///sen�o
        printf("\nA lista n�o esta vazia\n");
    }

    printf("\nQuantidade de n�s presente na lista: %d\n",tamanho_lista(&lista));

    listagem(lista);                                    ///mostra os valores presentes nos n�s da lista

    if(buscar_pela_posicaoo(&lista, 2, &e))
        printf("\nO valor do n� na Segunda posi��o �: %d \n",e);

    e = 20;

    if(buscar_pelo_elemento(&lista, e))
        printf("\nO elemento [%d] foi encontrado na lista\n",e);
    else
        printf("\nN�o foi encontrado o elemento [%d]\n",e);

    /*if(remover_inicio(&lista,&e))
        printf("\nElemento [%d] removido com Sucesso do Inicio da Lista\n\n",e);

    printf("\nQuantidade de n�s presente na lista: %d\n\n",tamanho_lista(&lista));

    listagem(lista);*/
    ///===== - Fim - ================================== - Teste de Inserir no Inicio da Lista

    libera_lista(&lista);                               ///limpa a lista
}

void manipular_lista_meio(){
    tplista *lista;                                     ///cria��o de um ponteiro da lista
    tp_item e = 20;
    lista = inicializa();                               ///inicializando a lista(seu valor ser� nulo)

    ///===== - Inicio - =============================== - Teste de Inserir de modo Ordenado na Lista
    inserir_oredenado(&lista,20);
    inserir_oredenado(&lista,30);
    inserir_oredenado(&lista,10);

    if(lista_vazia(lista)){                             ///executa a fun��o que checa se a lista ta vazia(se diferente de 0)
        printf("\nA lista esta vazia\n");
    }else{                                              ///sen�o
        printf("\nA lista n�o esta vazia\n");
    }

    printf("\nQuantidade de n�s presente na lista: %d\n\n",tamanho_lista(&lista));

    listagem(lista);                                    ///mostra os valores presentes nos n�s da lista

    if(remover_meio(&lista,&e))
        printf("\nElemento [%d] removido com Sucesso da Lista\n",e);

    printf("\nQuantidade de n�s presente na lista: %d\n\n",tamanho_lista(&lista));

    listagem(lista);
    ///===== - Fim - ================================== - Teste de Inserir de modo Ordenado na Lista

    libera_lista(&lista);                               ///limpa a lista
}

void manipular_lista_final(){
    tplista *lista;                                     ///cria��o de um ponteiro da lista
    tp_item e;
    lista = inicializa();                               ///inicializando a lista(seu valor ser� nulo)

    ///===== - Inicio - =============================== - Teste de Inserir no Final da Lista
    inserir_final(&lista,10);
    inserir_final(&lista,20);
    inserir_final(&lista,30);

    if(lista_vazia(lista)){                             ///executa a fun��o que checa se a lista ta vazia(se diferente de 0)
        printf("\nA lista esta vazia\n");
    }else{                                              ///sen�o
        printf("\nA lista n�o esta vazia\n");
    }

    printf("\nQuantidade de n�s presente na lista: %d\n",tamanho_lista(&lista));

    listagem(lista);                                    ///mostra os valores presentes nos n�s da lista

    if(remover_final(&lista,&e))
        printf("\nElemento [%d] removido com Sucesso do Final da Lista\n\n",e);

    printf("\nQuantidade de n�s presente na lista: %d\n\n",tamanho_lista(&lista));

    listagem(lista);
    ///===== - Fim - ================================== - Teste de Inserir no Final da Lista

    libera_lista(&lista);                               ///limpa a lista
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

void listagem(tplista *lista){                          ///esta fun��o lista todos os elementos contido em uma lista
    tplista *atu;                                       ///cria-se um ponteiro do tipo tplista
    atu = lista;                                        ///este ponteiro vai receber a lista passada como parametro
    while(atu != NULL){                                 ///la�o que vai passaar por toda a lista, at� o seu valor se tornar nulo
        printf("Valor na lista: %d\n",atu->info);       ///mostra o dado(info) contido na lista
        atu = atu->prox;                                ///diz para o ponteiro 'atu', que ele vai receber o n�, que o n� atual aponta
    }
}

int tamanho_lista(tplista **lista){                     ///esta fun��o ira retornar o tamanho da lista, percorrendo cada elemento
    if(lista_vazia(*lista))                             ///verifica se a lista esta vazia
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
    if(!lista_vazia(*lista)){                           ///verifica se a lista n�o � nula
        while((*lista) != NULL){                        ///enquanto existir n� dentro da lista
            no = *lista;                                ///o novo n� vai receber o primeiro n� da lista
            *lista = (*lista)->prox;                    ///esta lista vai avan�ar para o n� que ela aponta
            free(no);                                   ///libera a memoria do n�
        }
        free(lista);                                    ///por fim, a lista � liberada por completo da memoria
    }
}

int inserir_inicio(tplista **lista, tp_item e){         ///esta fun��o ira inserir novos n�s no final da lista
    if(lista == NULL)                                   ///checa se a lista existe
        return 0;
    tplista *novo_no;                                   ///cria o novo n�
    novo_no = aloca();                                  ///aloca memoria para ele

    if(novo_no == NULL)                                 ///checa se o n� foi alocado com sucesso
        return 0;

    novo_no->info = e;                                  ///passa para a info desse n� o valor passado como parametro
    novo_no->prox = (*lista);                           ///faz com que este n� aponte para o mesmo lugar que a lista aponta

    *lista = novo_no;                                   ///agora a lista esta apontando para o novo n�

    return 1;
}

int inserir_oredenado (tplista **lista, tp_item e){     ///esta fun��o ira inserir um novo n� de forma ordenada na lista
    if(lista == NULL)                                   ///checa se a lista existe
        return 0;
    tplista *novo_no;                                   ///cria o novo n�
    novo_no = aloca();                                  ///aloca memoria para ele

    if(novo_no == NULL)                                 ///checa se o n� foi alocado com sucesso
        return 0;

    novo_no->info = e;                                  ///passa para a info desse n� o valor passado como parametro
    if(lista_vazia(*lista)){                            ///checa se a lista esta vazia, para inserir no primeiro elemento
        novo_no->prox = (*lista);                       ///o novo n� vai receber a lista
        *lista = novo_no;                               ///a lista recebe o novo n�
        return 1;                                       ///sai da inser��o

    } else {                                            ///se a lista n�o estiver vazia, vai procurar o local para inserir
        tplista *atu, *ant;                             ///estes ponteiros v�o navegar todos os n�s da lista, apontado para o n� atual e o proximo n� que ele aponta
        atu = *lista;                                   ///o ponteiro atual recebe a lista e faz um la�o, verificando
        while(atu != NULL && atu->info < e){            ///se enquanto o atual n�o for nulo, e o valor dele for menor que o valor do elemento passado como parametro
            ant = atu;                                  ///o anterior recebe o atual
            atu = atu->prox;                            ///e o atual aponta para o proximo
        }                                               ///quando chegar no fim, alguma das checagens ser�o falsas
        if(atu == *lista){                              ///aqui ele checa se o n� atual � igual a lista(subtende-se que esta no inicio)
            novo_no->prox = (*lista);                   ///faz com que este n� aponte para o mesmo lugar que a lista aponta
            *lista = novo_no;                           ///e a lista aponta para o novo n�
        } else {                                        ///sen�o
            novo_no->prox = ant->prox;                  ///o novo n� vai apontar para o proximo n� que o anterior aponta
            ant->prox = novo_no;                        ///e o anterior vai apontar para o novo n�, inserindo assim no meio da lista;
        }
        return 1;
    }
}

int inserir_final(tplista **lista, tp_item e){          ///esta fun��o vair inserir na lista '**lista' o elemento 'e'
    tplista *novo_no;                                   ///cria um ponteiro que vai receber o end de memoria alocads
    tplista *aux;                                       ///estes ponteiros v�o navegar todos os n�s da lista, apontado para o n� atual e o n� que ele aponta
    novo_no = aloca();                                  ///o ponteiro esta armazenando o end de memoria alocada

    if(novo_no == NULL)                                 ///verifica se o ponteiro recebeu null, traduzindo, n�o foi possivel alocar memoria, (o malloc vai informar isso)
        return 0;                                       ///n�o conseguiu alocar memoria

    novo_no->info = e;                                  ///o ponteiro que recebeu o endere�o de memoria alocada vai salvar em info o valor inserido no parametro
    novo_no->prox = NULL;

    if((*lista) == NULL){                               ///checa se a lista esta vazia, para inserir no primeiro elemento
        *lista = novo_no;                               ///a lista vai apontar para o n� criado
    } else {                                            ///se n�o estiver vazia
        aux = *lista;                                   ///a lista auxiliar vai receber a lista passada como parametro
        while(aux->prox != NULL){                       ///enquanto o n� que a auxiliar aponta n�o for nulo
            aux = aux ->prox;                           ///a auxiliar vai apontar para o proximo n� que que ela aponta
        }
        aux->prox = novo_no;                            ///por fim, quando chegar no ultimo n�, ele vai apontar para o n� criado
    }
    return 1;
}

int remover_inicio(tplista **lista, tp_item *e){        ///fun��o para remover o primeiro n� da lista
    if(lista == NULL)                                   ///checa se a lista existe
        return 0;
    if(lista_vazia(*lista))                             ///checa se a lista esta vazia
        return 0;

    tplista *no = *lista;                               ///cria-se um novo n�, que aponta para a lista
    *e = no->info;                                      ///o valor que estiver neste n� vais er passado para o parametro 'e'
    *lista = no->prox;                                  ///a lista vai apontar para o proximo n� que o novo n� aponta
    free(no);                                           ///por fim o novo n� � liberado da memoria
    return 1;
}

int remover_meio(tplista **lista, tp_item *e){          ///fun��o para remover um n� com um certo valor
    if(lista == NULL)                                   ///checa se a lista existe
        return 0;
    if(lista_vazia(*lista))                             ///checa se a lista esta vazia
        return 0;
    tplista *ant, *novo_no = *lista;                    ///cria-se 2 ponteiros para percorrer a lista, o ponteiro 'novo_no' vai receber a lista
    while(novo_no != NULL && novo_no->info != *e){      ///enquanto o novo_no n�o for nulo e o valor que estiver nele for diferente do valor passado como parametro
        ant = novo_no;                                  ///o n� anterior vai receber o novo_no
        novo_no = novo_no->prox;                        ///o novo_no vai apontar para o proximo n� que ele aponta
    }

    if(novo_no == NULL)                                 ///checa se o valor � nulo
        return 0;                                       ///isto �, n�o foi encontrado

    if(novo_no == *lista){                              ///se foi encontrado, ele checa se vai remover o primeiro
        *lista = novo_no->prox;                         ///ent�o a lista vai apontar para o proximo n� que o novo_no aponta
    } else {                                            ///sen�o
        ant->prox = novo_no->prox;                      ///o proximo n� que o n� anterior aponta vai apontar para o proximo n� que o novo_no aponta
    }
    free(novo_no);                                      ///por fim o novo_no que agora foi encontrado � liberado da memoria
    return 1;
}

int remover_final(tplista **lista, tp_item *e){         ///fun��o para remover o ultimo n� da lista
    if(lista == NULL)                                   ///checa se a lista existe
        return 0;
    if(lista_vazia(*lista))                             ///checa se a lista esta vazia
        return 0;

    tplista *ant, *novo_no = *lista;                    ///cria-se 2 ponteiros para percorrer a lista, o ponteiro 'novo_no' vai receber a lista
    while(novo_no->prox != NULL){                       ///este la�o vai percorrer toda a lista at� que o proximo n� do novo_no seja nulo
        ant = novo_no;                                  ///o potneiro anterior recebe o novo_no
        novo_no = novo_no->prox;                        ///e o 'novo_no' vai apontar para o proximo n� que ele aponta
    }
    *e = novo_no->info;
    if(novo_no == (*lista)){                            ///se o novo_no for igual a lista(quer dizer que � o primeiro)
        *lista = novo_no->prox;                         ///a lista vai apontar para o proximo n� que o novo_no aponta
    } else {                                            ///sen�o
        ant->prox = novo_no->prox;                      ///o proximo n� que que o anterior aponta, vai apontar para o proximo n� que o 'novo_no' aponta
    }
    free(novo_no);                                      ///por fim, o novo_no � liberado
    return 1;
}

int buscar_pelo_elemento(tplista **lista, tp_item e){   ///esta fun��o ira buscar por um n� na lista de ocordo com o valor que ele tiver
    if(lista == NULL)                                   ///checa se a lista existe ou esta vazia
        return 0;

    tplista *novo_no = *lista;                          ///cria-se um novo n�, recebendo a lista

    while(novo_no != NULL && novo_no->info != e){       ///enquanto o novo_no n�o for nulo e o valor de info contido neste n� for diferente do parametro 'e'
        novo_no = novo_no->prox;                        ///o novo_no vai apontar o proximo n� que ele aponta
    }
    if(novo_no == NULL)                                 ///se o novo_no for nulo
        return 0;                                       ///quer dizer que nada foi encontrado
    else{                                               ///sen�o
        return 1;                                       ///retorna 1 informando que foi encontrado o dado
    }
}

int buscar_pela_posicaoo(tplista **lista, int pos, tp_item *e){///esta fun��o ira buscar por um n� na lista de ocordo com a posi��o dele na lista
    if(lista == NULL || pos <= 0)                       ///checa se a lista existe
        return 0;
    if(lista_vazia(*lista))                             ///checa se a lista esta vazia
        return 0;
    tplista *novo_no = *lista;                          ///cria-se um novo no para recebendo a lista
    int i = 1;                                          ///cria-se uma varivel intermediaria para filtrar as posi��es
    while(novo_no != NULL && i < pos){                  ///enquanto o novo_no n�o for nulo e o valor de i for menor que o valor do paramentro pos
        novo_no = novo_no->prox;                        ///o novo_no vai apontar o proximo n� que ele aponta
        i++;                                            ///o 'i' incrementa
    }
    if(novo_no == NULL)                                 ///se o novo_no for nulo
        return 0;                                       ///quer dizer que nada foi encontrado
    else{                                               ///sen�o
        *e = novo_no->info;                             ///o parametro 'e' vai receber o valor da info contida no n� encontrado
        return 1;                                       ///retorna um informando que tudo ocorreu normal
    }
}
