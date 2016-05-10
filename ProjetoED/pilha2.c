#include "cabecalho.h"



void criarpilha(pilha2 *p, int c ){
   p->topo = -1;
   p->capa = c;
   p->pElem = (float*) malloc (c * sizeof(float));
}
int estavazia (pilha2 *p ){
   if( p-> topo == -1 )
      return 1;   ///true
   else
      return 0;   ///false
}

int estacheia (pilha2 *p ){
	if (p->topo == p->capa - 1)
		return 1;
	else
		return 0;
}

void empilhar (pilha2 *p, float v){
	p->topo++;
	p->pElem [p->topo] = v;
}

float desempilhar (pilha2 *p ){
   float aux = p->pElem [p->topo];
   p->topo--;
   return aux;
}

float retornatopo (pilha2 *p ){
   return p->pElem [p->topo];
}

int pilha_dinamica(){
	pilha2 minhapilha;
	int capacidade;
	char op;
	float valor;

	printf( "\nCapacidade da pilha? " );
	scanf( "%d", &capacidade );

	criarpilha (&minhapilha, capacidade);

	while( 1 ){ ///loop infinito
        system("cls");
		printf("\n1- empilhar (push)\n");
		printf("2- desempilhar (POP)\n");
		printf("3- Mostrar o topo \n");
		printf("4- sair\n");
		printf("\nopcao? ");
		op = getche();

		switch (op){
			case '1': ///push
				if( estacheia( &minhapilha ) == 1 )
					printf("\nPILHA CHEIA! \n");
				else {
					printf("\nVALOR? ");
					valor = getche();
					empilhar (&minhapilha, valor);
				}
				break;
			case '2': ///pop
				if ( estavazia(&minhapilha) == 1 )
					printf( "\nPILHA VAZIA! \n" );
				else{
					valor = desempilhar (&minhapilha);
					printf ( "\n%.1f DESEMPILHADO!\n", valor );
				}
				getch();
				break;
			case '3': ///mostrar o topo
				if ( estavazia (&minhapilha) == 1 )
					printf( "\nPILHA VAZIA!\n");
				else {
					valor = retornatopo (&minhapilha);
					printf ( "\nTOPO: %.1f\n", valor );
				}
				getch();
				break;
			case '4':
				fim_pilha(2);
			default:
			    printf( "\nOPCAO INVALIDA! \n" );
                getch();
		}
	}
}
