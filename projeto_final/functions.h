//-------------GLOBAIS-----------//
int VISITADOS[100000][8];
int aux_visitados = 0;

typedef struct node {
	struct node *pai;
	struct node *possibilidades;
	int estado[8];
	int visitado;
	int qnt_possi;
} node;
//-------------------------------//


//-----------Prototipos----------//

node cria_possibilidades(node nodo_atual);
node cria_node(int estado[8],node nodo_pai);
node cria_node_zerado();
int checar_conflito(int *estado, int qnt_rainhas);
int checar_visitado(int estado[8]);
int checar_rainhas(int *estado);
//-------------------------------//


//Cria um nodo novo atribuindo o estado e o pai
node cria_node(int estado[8],node nodo_pai){
	node nodo_novo;
	for (int j = 0; j < 8; j++) {
		nodo_novo.estado[j] = estado[j];
	}
	nodo_novo.pai = &nodo_pai;
	nodo_novo.visitado = -1;
	nodo_novo.qnt_possi = 0;

	return nodo_novo;
}

//Cria a raiz da arvore atribuindo o estado, as possibilidades e o pai.
node cria_node_zerado() {
	node a;
	a.pai = NULL;
	for (int i = 0; i < 8; i++) {
		a.estado[i] = -1;
	}

    //a.estado[0] = 0;
	a = cria_possibilidades(a);
	a.visitado = -1;

	return a;
}

//Checa se em determinado estado existe algum conflito entre as rainhas
int checar_conflito(int *estado, int qnt_rainhas) {
	int flag = 1;
	for (int i = 0; i < qnt_rainhas; i++) {

		if (abs(estado[i] - estado[qnt_rainhas]) == abs(i - qnt_rainhas) || estado[i] == estado[qnt_rainhas]) {
			flag = 0;
			break;
		}
	}

	return !flag;
}

int checar_visitado(int estado[8]) {
	int flag = 0;
	for (int i = 0; i < aux_visitados; i++) {
		int flag_interna = 1;
		for (int j = 0; j < 8; j++) {
			if (VISITADOS[i][j] == estado[j]) {
				flag_interna = flag_interna;
			} else {
				flag_interna = 0;
				break;
			}

		}
		if (flag_interna) {
			flag = 1;
			break;
		}

	}

	return flag;
}

int checar_rainhas(int *estado) {
	int qnt_rainhas = 0;
	for (int i = 0; i < 8; i++) {
		qnt_rainhas = estado[i] != -1 ? qnt_rainhas + 1 : qnt_rainhas;
	}
	return qnt_rainhas;
}

node cria_possibilidades(node nodo_atual) {
	if (checar_visitado(nodo_atual.estado)) {
		node return_null;
		return_null.qnt_possi = 0;
		return return_null;
	}
   // printf("--------------------------\n");
	for (int i = 0; i < 8; i++) {
		printf("%2d ", nodo_atual.estado[i]);
	}
	printf("\n");
   // printf("--------------------------\n");
	int qnt_rainhas = 0;
	int vetor_possibilidades_nvisitadas[8][8]= {{-1, -1, -1, -1, -1, -1, -1, -1},
												{-1, -1, -1, -1, -1, -1, -1, -1},
												{-1, -1, -1, -1, -1, -1, -1, -1},
												{-1, -1, -1, -1, -1, -1, -1, -1},
												{-1, -1, -1, -1, -1, -1, -1, -1},
												{-1, -1, -1, -1, -1, -1, -1, -1},
												{-1, -1, -1, -1, -1, -1, -1, -1},
												{-1, -1, -1, -1, -1, -1, -1, -1}};

	int tam_aux = 0;

	for (int i = 0; i < 8; i++) {
		qnt_rainhas = nodo_atual.estado[i] != -1 ? qnt_rainhas + 1 : qnt_rainhas;
	}
   // printf("Quantidade de rainhas = %d\n", qnt_rainhas);
	int estado[8];
	for (int i = 0; i < 8; i++) {
		estado[i] = nodo_atual.estado[i];
	}

	for (int i = 0; i < 8; i++) {
		estado[qnt_rainhas] = i;
		if (checar_conflito(estado, qnt_rainhas)) {
			continue;
		}


        //printf("\n");
		if (!checar_visitado(estado)) {
			for (int j = 0; j < 8; j++) {
         //       printf("%d", estado[j]);
				vetor_possibilidades_nvisitadas[tam_aux][j] = estado[j];
			}
			tam_aux++;
		} else {
			for (int x = 0; x < 8; x++) {
				VISITADOS[aux_visitados][x] = estado[x];
			}
			aux_visitados++;
		}

	}
	nodo_atual.qnt_possi = tam_aux;

	node *aloc_din_vetor_possibilidades_nvisitadas = (node *) malloc((tam_aux + 1) * sizeof(node));

	for (int i = 0; i < tam_aux; i++) {
		node b = cria_node(vetor_possibilidades_nvisitadas[i],nodo_atual);        
		aloc_din_vetor_possibilidades_nvisitadas[i] = b;
	}

	nodo_atual.possibilidades = aloc_din_vetor_possibilidades_nvisitadas;

	free(aloc_din_vetor_possibilidades_nvisitadas);

	return nodo_atual;

}
