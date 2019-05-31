#include <stdio.h>
#include <stdlib.h>
#include "functions.h" 

//-------------GLOBAIS-----------//
int COUNT_DFS = 0;
int aux1 = 1;
int qnt_acertados = 1;
//-------------------------------//

//-----------Prototipos----------//
int dfs(node nodo_atual);
//-------------------------------//

int dfs(node nodo_atual) {

    if (checar_rainhas(nodo_atual.estado) == 8) {
    	if (nodo_atual.estado[0] != nodo_atual.estado[1]){
            printf("--------------------------------------\n");
            for (int i = 0; i < 8; i++) {
               printf("%d ", nodo_atual.estado[i]);
           }
           printf("ESTADO POSSÍVEL N° %d\n",qnt_acertados++);
           printf("--------------------------------------\n");
	        //exit(0);
       }   	
   }
   while (nodo_atual.visitado < nodo_atual.qnt_possi) {
    if (COUNT_DFS != 0)
        nodo_atual = cria_possibilidades(nodo_atual);
    COUNT_DFS++;

    if (nodo_atual.qnt_possi == 0) {
        return 0;
    }
    dfs(nodo_atual.possibilidades[++nodo_atual.visitado]);

}

return 0;
}


int main(int argc, char const *argv[]) {
    node raiz = cria_node_zerado();
    dfs(raiz);


    return 0;
}