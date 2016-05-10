#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

char *p[MAX];
int spos = 0;
int rpos = 0;

void qstore(char *q);
char *qretrieve();
void enter(void);
void review(void);
void excluir(void);

void main(void){
    char s[80];
    register int t;

    for(t=0; t<MAX; ++t)
        p[t] = NULL;   //inicializando a matrz com nulos

    for(;;) {
        printf("E - Inserir\n");
        printf("L - Listar\n");
        printf("R - Remover\n");
        printf("Q - Sair\n");
        gets(s);

        *s = toupper(*s);

        switch(*s){
        case 'E':
            enter();
            break;
        case 'L':
            review();
            break;
        case 'R':
            excluir();
            break;
        case 'Q':
            exit(0);
        }
    }

    system("pause");
    return 0;
}

/* Insere um evento na Fila */

void enter(void){
    char s[256];
    char *p;

    do{
           printf("Insira o evento %d.: ", spos+1);
           gets(s);

           if(*s==0){
                printf("Nenhuma entrada!\n");
            break;
           }

           if(!p){
            printf("Sem memória. \n");
            return;
           }
           strcpy(p, s);
           if(*s){
            qstore(p);
           }

    }while(*s);
}

/* Vê o que há na fila */
void review(void){
    register int t;

    for(t=rpos; t<spos; ++t){
        printf("%d. %s\n", t+1, p[t]);
    }
}

/* Apaga um evento da fila */
void excluir(void){
    char *p;
    if((p=qretrieve())==NULL){
            printf("%s\n", p);
        return;
    }
}

/* Armazenar um evento */
void qstore(char *q){
    if(spos == MAX){
        printf("\n\t\t\tLista cheia!!\n\n");
        return;
    }
    p[spos] = q;
    spos++;
}

/* Recupera um evento */
char *qretrieve(){
    if(rpos == spos){
        printf("Sem eventos!\n");
        return NULL;
    }
    rpos++;
    return p[rpos-1];
}


