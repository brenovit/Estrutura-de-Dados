#include "cabecalho.h"
#define BASE -1

void configtela();

int pilha_estatica(){
    system("color f0");
    //configtela();
    SetConsoleTitle("Estrutura de Dados - Pilha - Breno");
    setlocale(LC_ALL,"Portuguese");

    tp_item e;

    tp_pilha pilha1;         ///cria a pilha1
    tp_fila fila1;
    tp_fila fila2;

    inicia_pilha(&pilha1);   ///inicia a pilha
    inicia_fila(&fila1);
    inicia_fila(&fila2);
    //menu_pilha();

    int i;
    ///junta pilhas
    ///
    printf("\n=============\nValore Inseridos na Pilha 1\n=============\n");
    for(i = 0; i < 3; i++){
        empilha(&pilha1,i);
        verifica_topo(&pilha1,&e);
        printf("\nO Valor [%d] foi Inserido na Pilha 2!",e);
    }
    printf("\n=============\nValore Inseridos na Pilha 2\n=============\n");
    ver_pilha(pilha1);
    printf("\n=============\nPilha 1 Verificada\n=============\n");
//    junta_pilha(&pilha2,&pilha1);
    printf("\n=============\nPilhas anexadas\n=============\n");
    ver_pilha(pilha1);
    printf("\n=============\nPilha 1 Verificada\n=============\n");

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
    fim_pilha(1);
    return 1;
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
        return 1;
    }
}

int retira_impar(tp_pilha *p){
///1)	Implementar uma função que receba uma pilha como parâmetro
///     e retire todos os elementos ímpares dessa pilha. (Use uma pilha auxiliar).
    tp_pilha pilhaAux;
    inicia_pilha(&pilhaAux);
    tp_item e;
    int i;

    recorta_pilha(p,&pilhaAux);

    for(i = pilhaAux.topo; i >= 0; i--){
        desempilha(&pilhaAux, &e);
        /*if(e % 2 == 0){
            empilha(p,e);
            verifica_topo(p,&e);
        }*/
    }
    return 1;
}

int pilhas_iguais(tp_pilha p1,tp_pilha p2){
///2)	Implementar uma função que receba duas pilhas como parâmetro
///     e retorna 1 caso sejam idênticas ou zero caso contrário.
    tp_item e1, e2;
    if(p1.topo != p2.topo){
        printf("\n\t\t\tTAMANHO DAS PILHAS DIFERENTES!");
        return 0;
    }

    do{
        desempilha(&p1, &e1);
        desempilha(&p2, &e2);
        if(e1 != e2){
            return 0;
        }
    }while(!pilha_vazia(&p1));
    return 1;
}

int junta_pilha(tp_pilha *p1, tp_pilha *p2){
///3)	Implementar uma função que receba duas pilhas como parâmetro
///     e empilhe a segunda sobre a primeira. (Use uma pilha auxiliar, além das duas pilhas em questão)
    tp_pilha pilhaAux;
    inicia_pilha(&pilhaAux);

    recorta_pilha(p1,&pilhaAux);
    recorta_pilha(&pilhaAux,p2);
    return 1;
}

int recorta_pilha(tp_pilha *pMain, tp_pilha *pDestiny){
    tp_item e;
    int i;
    for(i = pMain->topo; i >= 0; i--){
        desempilha(pMain, &e);
        empilha(pDestiny,e);
    }
    return 1;
}

int ver_pilha(tp_pilha p){
    tp_item e;
    do{
        desempilha(&p,&e);
        printf("---\n");
        printf("|%d|\n",e);
    }while(!pilha_vazia(&p));
    printf("--- \n");
    return 1;
}

int pilha_vazia(tp_pilha *p){ ///verifica se a pilha esta vazia
    if(p->topo == -1){ ///se o valor
        return 1;
    } else {
        return 0;       ///pilha tem item
    }
}
