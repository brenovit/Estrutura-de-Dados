#include "cabecalho.h"

void atvd1(){
    system("cls");
    system("color f0");
    SetConsoleTitle("Estrutura de Dados - Atividade 1 - Breno");
    tp_item e;

    tp_pilha pilha1;         ///cria a pilha1
    tp_fila fila1;
    tp_fila fila2;

    inicia_pilha(&pilha1);   ///inicia a pilha
    inicia_fila(&fila1);
    inicia_fila(&fila2);

    int i;

    ///atividade 1
    for(i = 1; i < 9; i++){
        empilha(&pilha1,i);
    }
    empilha(&pilha1,99);
    printf("\n\t===> Pilha 1\n");
    ver_pilha(pilha1);

    /*while(!(pilha_vazia(&pilha1))){
        desempilha(&pilha1,&e);
        if(e % 3 == 0){
            e = e * 2;
             inserir_fila(&fila1,e);
        } else {
            e = e * 3;
             inserir_fila(&fila2,e);
        }
    }*/
    printf("\n\t===> Fila 1\n");
    mostrar_fila(fila1);
    printf("\n\t===> Fila 2\n");
    mostrar_fila(fila2);
    ///atividade 1
    fim_atvd(1);
}

void atvd2(){
    system("color f0");
    //configtela();
    SetConsoleTitle("Estrutura de Dados - Atividade 2 - Breno");
    setlocale(LC_ALL,"Portuguese");

    tp_fila fila1;
    tp_item maior, menor;            ///crio uma variavel para ser intermediaria
    float media;
    inicia_fila(&fila1);
    int i;
    for(i = 0; i < 10; i++){ ///laço para inserir_fila 3 elementos da fila
        inserir_fila(&fila1, i);
    }
    ///atividade 2
    mostrar_fila(fila1);
    maior_menor_media_fila(fila1, &maior, &menor, &media);
    printf("\n\n========================================\n\tMaior Elemento: %d\n\tMenor Elemento: %d\n\tMedia dos Valores: %.2f\n========================================\n",maior,menor,media);
    ///atividade 2
   fim_atvd(2);
}
void atvd3(){
    system("color f0");
    //configtela();
    SetConsoleTitle("Estrutura de Dados - Atividade 3 - Breno");
    setlocale(LC_ALL,"Portuguese");

    tp_fila fila1, fila2;                   ///crio a fila
    tp_item el, e, maior, menor;            ///crio uma variavel para ser intermediaria
    float media;
    inicia_fila(&fila1);                    ///inicio a fila
    int i;

    int num;
    for(i = 0; i < 10; i++){ ///laço para inserir_fila 3 elementos da fila
        printf("\nDigite um numero:");
        scanf("%d",&num);
        fila_checa_par(&fila1, num);
    }
    while(!fila_ta_vazia(&fila1)){
        remover_fila(&fila1, &el);
        printf("|%d",el);
    }
    printf("|\n");
    printf("\n");
    mostrar_fila(fila1);
    limpa_fila(&fila1);

    fim_atvd(3);

}
void atvd4(){
    system("color f0");
    //configtela();
    SetConsoleTitle("Estrutura de Dados - Fila - Breno");
    setlocale(LC_ALL,"Portuguese");

    tp_fila fila1;
    inicia_fila(&fila1);

    inserir_fila(&fila1, 1);
    inserir_fila(&fila1, 2);
    inserir_fila(&fila1, 0);
    inserir_fila(&fila1, 2);
    inserir_fila(&fila1, 2);
    inserir_fila(&fila1, 0);
    inserir_fila(&fila1, 1);
    inserir_fila(&fila1, 2);
    inserir_fila(&fila1, 1);
    inserir_fila(&fila1, 0);

    mostrar_fila(fila1);

    fila_ordenada(&fila1);

    mostrar_fila(fila1);

    fim_atvd(4);
}

tp_item EquacaoPolonesa(char ex[]){
    tp_pilha pilha;
    tp_item calc, num1, num2, numAux;
    int i;
    char aux;

    inicia_pilha(&pilha);

    for(i = 0; i < sizeof(ex); i++){
        aux = ex[i];
        ///if(aux == '+')
        if(strcmp(aux,'+') != 0 && !strcmp(aux,'*') != 0 && !strcmp(aux,'-') != 0 && !strcmp(aux,'/') != 0){
            if(isdigit(aux)){
                numAux = (tp_item)aux;
                empilha(&pilha, numAux);
            }
        }else{
            desempilha(&pilha, &num2);
            desempilha(&pilha, &num1);
            switch(aux){
                case '+': calc = num1 + num2; break;
                case '-': calc = num1 - num2; break;
                case '*': calc = num1 * num2; break;
                case '/': calc = num1 / num2; break;
            }
            empilha(&pilha, calc);
        }
    }
    desempilha(&pilha, &calc);
    return calc;
}
