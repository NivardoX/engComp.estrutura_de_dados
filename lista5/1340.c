#include <stdio.h>
#include <stdlib.h>

#define MAXIMO 1000     // QUANTIDADE MAXIMA DE ELEMENTOS X

typedef struct{     // STRUCT DA PILHA
    int topo;
    int vetor[MAXIMO];
}pilha;

typedef struct{   // STRUCT DA FILA
    int base;
    int topo;
    int vetor[MAXIMO];
}fila;

typedef struct{     // STRUCT DA FILA PRIORITARIA
    int topo;
    int vetor[MAXIMO];
}filaPrioridade;


void pushP(pilha *p, int x);
void pushF(fila *f, int x);
void pushFP(filaPrioridade *fp, int x);
void push(pilha *p, fila *f, filaPrioridade *fp, int x);
void popP(pilha *p);
void popF(fila *f);
void popFP(filaPrioridade *fp);
void criaP(pilha *p);
void criaF(fila *f);
void criaFP(filaPrioridade *fp);
void cria(pilha *p, fila *f, filaPrioridade *fp);
int cmpfunc (const void * a, const void * b);


int main () {

  pilha *vetorPilha = (pilha*)malloc(sizeof(pilha));    // CRIA O PONTEIRO VETOR PILHA
  
  fila *vetorFila = (fila*)malloc(sizeof(fila));    // CRIA O PONTEIRO VETOR FILA
  
  filaPrioridade *vetorFilaPrioridade = (filaPrioridade*)malloc(sizeof(filaPrioridade));    // CRIA O PONTEIRO VETOR FILA PRIORITARIA
  
  cria(vetorPilha, vetorFila, vetorFilaPrioridade);   // INICIA TODAS OS VETORES
  int n, op, x, cP=0, cF=0, cFP=0;

  while(scanf("%d", &n) != EOF){  // LE ENQUANTO NAO CHEGAR NO EOF
    while(n--){
      scanf("%d", &op); // LE O OP QUE REPRESENTA 1 INSERÇÃO, 2 POPS
      if(op==1){
        scanf("%d", &x);
        push(vetorPilha, vetorFila, vetorFilaPrioridade, x); // REALIZA O PUSH EM TODOS DE UMA VEZ
      }

      if(op==2){
        scanf("%d", &x);
        qsort(vetorFilaPrioridade->vetor, vetorFilaPrioridade->topo+1 , sizeof(int), cmpfunc); // REALIZA UM QSORT NO VETOR FILA PRIORITARIO
        if(x!=vetorPilha->vetor[vetorPilha->topo]){   // VERIFICA SE O TOPO DO VETOR PILHA TEM O X
          cP=1;
        }
        if(x!=vetorFila->vetor[vetorFila->base]){   // VERIFICA SE O TOPO DO VETOR FILA TEM O X
          cF=1;
        }
        if(x!=vetorFilaPrioridade->vetor[vetorFilaPrioridade->topo]){   // VERIFICA SE O TOPO DO VETOR FILA PRIORIDADE TEM O X
          cFP=1;
        }
        popF(vetorFila);  // DECREMENTA TODOS OS VETORES DE DADOS PARA NAO HAVER CONFUSÃO
        popP(vetorPilha);
        popFP(vetorFilaPrioridade);
      }
    }
    // VERIFICA AS CONDIÇÕES PARA IMPRESSÃO
    if((cFP==0 && cF==0 && cP==0) || (cFP!=0 && cF==0 && cP==0) || (cFP==0 && cF!=0 && cP==0) || (cFP==0 && cF==0 && cP!=0)) printf("not sure\n");
    else if (cFP==0 && cF!=0 && cP!=0) printf("priority queue\n");
    else if (cFP!=0 && cF==0 && cP!=0) printf("queue\n");
    else if (cFP!=0 && cF!=0 && cP==0) printf("stack\n");
    else printf("impossible\n");
    // RESETA AS VARIAVEIS PARA PODE REINICIAR O PROGRAMA
    cria(vetorPilha, vetorFila, vetorFilaPrioridade);
    cP=0, cF=0, cFP=0;
  }
  
return 0;
}

void pushP(pilha *p,int x) {     // FUNÇÃO PUSH DA PILHA
  p->topo++;
  p->vetor[p->topo]=x;
}

void pushF(fila *f,int x) {     // FUNÇÃO PUSH DA FILA
  f->topo++;
  f->vetor[f->topo]=x;
}

void pushFP(filaPrioridade *fp,int x) {     // FUNÇÃO PUSH DA FILA PIORITARIA
  fp->topo++;
  fp->vetor[fp->topo]=x;
}

void push(pilha *p, fila *f, filaPrioridade *fp, int x){   // FUNÇÃO PUSH QUE CHAMA TODAS DE UMA VEZ 
  pushP(p, x);
  pushF(f, x);
  pushFP(fp, x);
}

void popP(pilha *p){     // FUNÇÃO POP DA PILHA(NAO GERA RETORNO)
	p->topo--;
}

void popF(fila *f){ // FUNÇÃO POP DA FILA(NAO GERA RETORNO)
  f->base++;
}

void popFP(filaPrioridade *fp){ // FUNÇÃO POP DA PILHA(NAO GERA RETORNO)
  fp->topo--;
}

void criaP(pilha *p){      // FUNÇÃO QUE RETORNA DA PILHA PARA O INICIO
  p->topo=-1;
}

void criaF(fila *f){  // FUNÇÃO QUE RETORNA DA FILA PARA O INICIO
  f->topo=-1;
  f->base=0;
}

void criaFp(filaPrioridade *fp){  // FUNÇÃO QUE RETORNA DA FILA PRIORITARIA PARA O INICIO
  fp->topo=-1;
}

void cria(pilha *p, fila *f, filaPrioridade *fp){ // FUNÇÃO QUE CHAMA TODAS DE CRIAÇÃO DE UMA VEZ
  criaP(p);
  criaF(f);
  criaFp(fp);
}

int cmpfunc (const void * a, const void * b){ // FUNÇÃO DE COMPARAÇÃO PARA UM QSORT
   return ( *(int*)a - *(int*)b );
}
