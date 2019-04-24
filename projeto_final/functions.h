int VISITADOS[100000][8];
int aux_visitados = 0;

typedef struct node {
    struct node *pai;
    struct node *possibilidades;
    int estado[8];
    int visitado;
    int qnt_possi;
} node;

node cria_possibilidades(node nodoa);


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

node cria_possibilidades(node nodoa) {
    if (checar_visitado(nodoa.estado)) {
        node return_null;
        return_null.qnt_possi = 0;
        return return_null;
    }
   // printf("--------------------------\n");
    for (int i = 0; i < 8; i++) {
    //   printf("%2d ", nodoa.estado[i]);
    }
   	//printf("\n");
   // printf("--------------------------\n");
    int qnt_rainhas = 0;
    int vetor[8][8] = {{-1, -1, -1, -1, -1, -1, -1, -1},
                       {-1, -1, -1, -1, -1, -1, -1, -1},
                       {-1, -1, -1, -1, -1, -1, -1, -1},
                       {-1, -1, -1, -1, -1, -1, -1, -1},
                       {-1, -1, -1, -1, -1, -1, -1, -1},
                       {-1, -1, -1, -1, -1, -1, -1, -1},
                       {-1, -1, -1, -1, -1, -1, -1, -1},
                       {-1, -1, -1, -1, -1, -1, -1, -1}};

    int tam_aux = 0;

    for (int i = 0; i < 8; i++) {
        qnt_rainhas = nodoa.estado[i] != -1 ? qnt_rainhas + 1 : qnt_rainhas;
    }
   // printf("Quantidade de rainhas = %d\n", qnt_rainhas);
    int estado[8];
    for (int i = 0; i < 8; i++) {
        estado[i] = nodoa.estado[i];
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
                vetor[tam_aux][j] = estado[j];
            }
            tam_aux++;
        } else {
            for (int x = 0; x < 8; x++) {
                VISITADOS[aux_visitados][x] = estado[x];
            }
            aux_visitados++;
        }

    }
    nodoa.qnt_possi = tam_aux;

   //	printf("Quantidade de possibilidades = %d\n", tam_aux);
    node *aloc_din_vetor = (node *) malloc((tam_aux+1) * sizeof(node));

    for (int i = 0; i < tam_aux; i++) {

        node b;
        for (int j = 0; j < 8; j++) {
            b.estado[j] = vetor[i][j];
        }
        b.pai = &nodoa;
        b.visitado = -1;
        b.qnt_possi = 0;

        aloc_din_vetor[i] = b;
    }

    nodoa.possibilidades = aloc_din_vetor;


    return nodoa;

}
