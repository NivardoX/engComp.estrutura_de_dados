#include<stdio.h>
#include <math.h>

int primos[10000] = {2};
int primos_index[1000000] = {0,0,1};
int index_visitado = 1;
int qnt_primos = 1;
int maior_visitado = 1;
int lixo;
int proxs[2];
int ants[2];
int qnt_testes = 0;
int eh_primo(int x){
	qnt_testes++;
	if(primos_index[x] == 0){
		int z = sqrt(x);
		if(z > maior_visitado){
			for (int i = maior_visitado; i <= z ; i++){
				eh_primo(i);
			}
			maior_visitado = z;
		}
		for (int i = 0; i < qnt_primos ; i++){
			if((x%primos[i] == 0 && primos[i] != 1)){
				return 0;
			}
		}
		primos[qnt_primos] = x;
		qnt_primos++;
		primos_index[x] = 1;
		return 1;			
	}
	else{
		return 1;
	}
}

int main(){
	int x;
	int flag = 1;
	int aux;
	while(flag){
		scanf("%d",&x);
		if(eh_primo(x)){
			aux = x;
			 flag = 0;
			int n = 0;
			int n2= 0;
			int aux2 = x;
			while(n != 2){
				if(eh_primo(++x)){

					proxs[n] = x;
					n++;
					
				}
			}
			if(aux > 3){
				while(n2 != 2){
					if(eh_primo(--aux2)){

						ants[n2] = aux2;
						n2++;
						
					}
				}
			}

		}else
			qnt_testes = 0;	
	
	
	}
	printf("O numero %d eh primo e tem os seguintes predecessores primos %d,%d \n",aux,ants[0],ants[1]);		
	printf("e tem os seguintes sucessores primos %d,%d \n",proxs[0],proxs[1]);		
	printf("O programa realizou a classificacao total de %d numeros\n",qnt_testes );

	return 0;
}