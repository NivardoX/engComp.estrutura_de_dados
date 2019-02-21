#include <stdio.h>


int main(int argc, char const *argv[])
{
	while(1){
		int n;
		
		scanf("%d",&n);
		
		if(!n)
			return 0;


		while(1){
			int pilha[n],pilhaAux[n],pilha3[n];
			int i,j,maior = n,auxPilha1 = 0,auxPilha2 = -1;
			int z,scanned;


			for (i = 0; i < n; i++){
				scanf("%d",&scanned);
				if(!scanned)
					break;
				pilha3[i] = scanned;	
			}
	
			for (i = n - 1; i >= 0; i--){
				z = pilha3[i];
				if(!z)
					break;
				
				if(auxPilha2 != -1){
					for(j = auxPilha2 ;j >=0 ;j--){
						if(pilhaAux[j] == maior){
							pilha[auxPilha1++] = pilhaAux[j];
							auxPilha2--;
							maior--;
						}

					}
				}
				if(z == maior){
					pilha[auxPilha1++] = z;
					maior--;

				}else{
					pilhaAux[auxPilha2++ + 1] = z;
				}
				


			}
			if(auxPilha2 != -1){
				for(j = auxPilha2 ;j >=0 ;j--){
					if(pilhaAux[j] == maior){
						pilha[auxPilha1++] = pilhaAux[j];
						auxPilha2--;
						maior--;
					}

				}
			}
		
			/* for (int i = 0; i <auxPilha1; i++)
			{
				printf(".%d ",pilha[i]);
			}
			printf("\n");
			for (int i = 0; i <auxPilha2; i++)
			{
				printf("-%d ",pilhaAux[i]);
			}
			printf("\n");
			*/

			if(!scanned){
				printf("\n");
				break;

			}
			if(auxPilha1 == n)
				printf("Yes\n");
			else
				printf("No\n");
		}


	}
	return 0;
}
