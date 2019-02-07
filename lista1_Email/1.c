#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int A[25];
	int B[25];
	int C[50];

	for (int i = 0; i < 25; i++)
	{	

		A[i] = rand()%25;
		B[i] = rand()%25;
		C[i] = A[i];
		C[24 + i] = B[i];
	}
	C[49] = B[24];
	
	for (int i = 0; i < 50; i++){
		printf("%d ", C[i]);

	}
	printf("\n");
	int n;
	scanf("%d",&n);
	for (int i = 0; i < 50; i++){
		if(C[i] == n){
			printf("achou, posição %d.\n",i );
			return 0;
		}

	}
	printf("nao achou.\n");
	return 0;
}