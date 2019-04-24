#include <stdio.h>
#include <stdlib.h>

int **possibilidades_global;
int COUNT_DFS=0;
typedef struct node 
{
	struct node *pai;
	struct node *possibilidades;
	int tam_pos;
	int estado[8];
	int visitado;
} node;


struct node cria_possibilidades(node nodoa);


node cria_node_zerado(){
	node a;	
	a.pai = NULL;
	for (int i = 0; i < 8; i++){
		a.estado[i] = -1;
	}
	a = cria_possibilidades(a);
	a.visitado = -1;

	return a;
}

int checar_conflito(int *estado,int qnt_rainhas){
	int flag = 1;
	for (int i = 0; i < qnt_rainhas; i++)
	{

		if(abs(estado[i]-estado[qnt_rainhas]) == abs(i - qnt_rainhas) || estado[i] == estado[qnt_rainhas]){
			flag = 0;
			break;
		}
	}

	return !flag;
}

int checar_rainhas(int *estado){
	int qnt_rainhas = 0;
	for (int i = 0; i < 8; i++)
	{
		qnt_rainhas = estado[i] != -1? qnt_rainhas+1:qnt_rainhas;
	}
	return qnt_rainhas;
}
struct node cria_possibilidades(node nodoa){
	printf("--------------------------\n");
	for (int i = 0; i < 8; i++)
		{
			printf("%d ",nodoa.estado[i]);
		}
	printf("\n");
	printf("--------------------------\n");
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
	int estado[8]; 
	for (int i = 0; i < 8; i++){
		estado[i] = nodoa.estado[i];
	}
	
	for (int i = 0; i < 8; i++)
	{
		estado[qnt_rainhas] = i;
		if(checar_conflito(estado,qnt_rainhas)){
			continue;
		}

		for (int i = 0; i < 8; i++)
		{
			printf("%d",estado[i] );
		}
		printf("\n");
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
	nodoa.tam_pos = tam_aux;
	nodoa.possibilidades = aloc_din_vetor;


	return nodoa;

}

int dfs(node nodoP){
	printf("DFS\n");
	if(checar_rainhas(nodoP.estado) == 8){
		//printf("Estado Possível\n");
		
	//	printf("\n");
		printf("CHEGOU\n");
		return 0 ;
	}
	else{
		int aux = nodoP.tam_pos;
		printf("antes %d ",nodoP.estado[0]);
		for (int i = 0; i < aux; i++){
			printf("depois %d\n",nodoP.estado[0]);

			if( COUNT_DFS != 0){
			
	
				nodoP = cria_possibilidades(nodoP);
			}
			COUNT_DFS++;
			node aux = nodoP.possibilidades[i];
			dfs(aux );

		}

	}
	return 0;
}


int main(int argc, char const *argv[])
{
	node raiz = cria_node_zerado();
	printf("\n");

	dfs(raiz);


	return 0;
}