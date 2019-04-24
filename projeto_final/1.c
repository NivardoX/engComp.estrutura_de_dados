#include <stdio.h>
#include <stdlib.h>

int **possibilidades_global;

typedef struct node 
{
	struct node *pai;
	struct node *possibilidades;
	int tam_pos;
	int estado[8];
	int visitado;
} node;


struct node cria_possibilidades(node nodoa,int *qnt);


node cria_node_zerado(){
	node a;	
	a.pai = NULL;
	int qnt;
	for (int i = 0; i < 8; i++){
		a.estado[i] = -1;
	}
	a = cria_possibilidades(a,&(qnt));

	a.tam_pos = qnt;
	a.visitado = -1;

	return a;
}

int checar_conflito(int *estado,int qnt_rainhas){
	int flag = 1;
	for (int i = 0; i < qnt_rainhas; i++)
	{

		if(abs(estado[i]-i) == abs(estado[qnt_rainhas] - qnt_rainhas) || estado[i] == estado[qnt_rainhas]){
			flag = 0;
			break;
		}
	}

	return !flag;
}

struct node cria_possibilidades(node nodoa,int *qnt){
	int qnt_rainhas = 0;
	int vetor[8][8] ={{-1,-1,-1,-1,-1,-1,-1,-1},
				{-1,-1,-1,-1,-1,-1,-1,-1},
				{-1,-1,-1,-1,-1,-1,-1,-1},
				{-1,-1,-1,-1,-1,-1,-1,-1},
				{-1,-1,-1,-1,-1,-1,-1,-1},
				{-1,-1,-1,-1,-1,-1,-1,-1},
				{-1,-1,-1,-1,-1,-1,-1,-1},
				{-1,-1,-1,-1,-1,-1,-1,-1}};

	int tam_aux = 0;

	for (int i = 0; i < 8; i++)
	{
		qnt_rainhas = nodoa.estado[i] != -1? qnt_rainhas+1:qnt_rainhas;
	}
	printf("Quantidade de rainhas = %d\n",qnt_rainhas );
	int *estado = nodoa.estado;
	for (int i = 0; i < 8; i++)
	{
		estado[qnt_rainhas] = i;
		if(checar_conflito(estado,qnt_rainhas)){
			continue;
		}

		for(int j = 0 ; j < 8 ; j++){
			vetor[tam_aux][j] = estado[j];

		}	
	tam_aux++;
	}
	
	printf("Quantidade de possibilidades = %d\n", tam_aux);
	node * aloc_din_vetor = (node*) malloc(tam_aux * sizeof(node));

	for (int i = 0; i < tam_aux; i++)
	{
		node b;	
		for(int j = 0; j < 8 ; j++){
			b.estado[j] = vetor[i][j];
		}
		b.pai = &nodoa;
		b.visitado = -1;
		b.tam_pos = 0;

		aloc_din_vetor[i] = b;
	}
	nodoa.possibilidades = aloc_din_vetor;
	return nodoa;

}




int main(int argc, char const *argv[])
{
	node raiz = cria_node_zerado();





	return 0;
}