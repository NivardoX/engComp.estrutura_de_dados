#include <stdio.h>
#include <stdlib.h>
#include "functions.h" 

//-------------GLOBAIS-----------//
int COUNT_DFS = 0;
int aux1 = 1;
int qnt_acertados = 1;
//-------------------------------//


int dfs(node nodoP) {

   // printf("\n\nDFS N° %d\n",COUNT_DFS+1);
    if (checar_rainhas(nodoP.estado) == 8) {
    	if (nodoP.estado[0] != nodoP.estado[1]){
    		printf("\n" );
	    	for (int i = 0; i < 8; i++) {
	            printf("%d ", nodoP.estado[i]);
	        }

	        printf("ESTADO POSSÍVEL N° %d\n",qnt_acertados++);
	        //exit(0);
	 	}   	
    }
    while (nodoP.visitado < nodoP.qnt_possi) {
        if (COUNT_DFS != 0)
            nodoP = cria_possibilidades(nodoP);
        COUNT_DFS++;

        if (nodoP.qnt_possi == 0) {
            //printf("Saiu %d\n", aux1++);
            return 0;
        }
        dfs(nodoP.possibilidades[++nodoP.visitado]);

    }

    //printf("Saiu %d\n", aux1++);
    return 0;
}


int main(int argc, char const *argv[]) {
    node raiz = cria_node_zerado();
    dfs(raiz);


    return 0;
}