#include <stdio.h>
int A[30];

void busca_bin(int n){
	int inicio = 0,meio,fim = 29;
	while(1){
		meio = (inicio+fim)/2;

		printf("%d, %d, %d\n",inicio,meio,fim );
		if(A[meio] == n){
			printf("Achou na pos %d\n",meio);
			return;
		}else if(inicio >= fim){
			break;
			
		}else if(A[meio] > n){
			fim = meio-1;

		}else{
			 inicio = meio+1;
			 
		}


	}

	printf("nao achou.\n");
	
}
int main(int argc, char const *argv[])
{

	for (int i = 0; i < 30; i++)
	{
		int z;
		scanf("%d",&z);
		A[i] = (z%2 == 0?z*2:z*5);
	}
	int j,aux;
	for(int i = 1; i < 30;i++){
		aux = A[i];
		j = i -1;
		while(j > -1 && A[j] > aux){
			A[j+1] = A[j];
			j--;
		}
	
		A[j+1] = aux;
	}

	int n;
	scanf("%d",&n);

	
	busca_bin(n);
	return 0;
}