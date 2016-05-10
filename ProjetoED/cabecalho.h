#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include <ctype.h>
#define MAX 15


///==============================================================/// Funções Gerais
typedef float tp_item;
void roda_pilha();
void roda_fila();
void menuF();
void menuP();
void menu();
int pilha_dinamica();
int pilha_estatica();
int fila();
void fim_menu(int e);
void fim_atvd(int op);
void atvd1();
void atvd2();
void atvd3();
void atvd4();
tp_item EquacaoPolonesa(char ex[]);
int menuAvd();
///==============================================================/// Funções Gerais

///==============================================================/// Funções da Pilha
typedef struct {            ///estrutura da pilha
    int topo;               ///representa o topo da pilha
    tp_item item[MAX];      ///vetor que vai representar a pilha
} tp_pilha;

void inicia_pilha(tp_pilha *p);              ///vai criar a pilha(inicializar o topo)
int empilha(tp_pilha *p, tp_item e);         ///bota um elemento na pilha
int desempilha(tp_pilha *p, tp_item *e);     ///tira um elemento da pilha
int verifica_topo(tp_pilha *p, tp_item *e);  ///retorna o valor do topo da pilha
int pilha_vazia(tp_pilha *p);                ///verifica se a pilha esta vazia
int retira_impar(tp_pilha *p);
int ver_pilha(tp_pilha p);
int pilhas_iguais(tp_pilha p1,tp_pilha p2);
int junta_pilha(tp_pilha *p1, tp_pilha *p2);
int recorta_pilha(tp_pilha *pMain, tp_pilha *pDestiny);
///==============================================================/// Funções da Pilha

///==============================================================/// Funções da Pilha2
typedef struct{
	int topo; ///posição elemento topo
	int capa;
	float *pElem;
}pilha2;
void criarpilha(pilha2 *p, int c );
int estavazia (pilha2 *p );
int estacheia (pilha2 *p );
void empilhar (pilha2 *p, float v);
float desempilhar (pilha2 *p );
float retornatopo (pilha2 *p );
int pilha2_main();
///==============================================================/// Funções da Pilha2

///==============================================================/// Funções da Fila
typedef struct {
    tp_item item[MAX];
    int inicio, fim;
}tp_fila;

int inserir_fila(tp_fila *f, tp_item e);
int remover_fila(tp_fila *f, tp_item *e);
int fila_ta_vazia(tp_fila *f);
int inicia_fila(tp_fila *f);
int retorna_proximo_fila(tp_fila *f, tp_item *e);
int mostrar_fila(tp_fila f);
int maior_menor_media_fila(tp_fila f, tp_item *maior, tp_item *menor, float *media);
int fila_ordenada(tp_fila *f);
int proximo(int pos);
int limpa_fila(tp_fila *f);
int fila_checa_par(tp_fila *f, tp_item e);
///==============================================================/// Funções da Fila
