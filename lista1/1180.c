#include <stdio.h>

int main()
{
	int A[1005];
	int x,pos=0,qnt = 0,menor;

	scanf("%d",&x);

	while(x--){
		scanf("%d",&A[qnt++]);

		if(qnt == 1)
			menor = A[0];

		if(A[qnt-1] < menor){
			menor = A[qnt -1 ];
			pos = qnt-1;
		}
	}

	printf("Menor valor: %d\n",menor);
	printf("Posicao: %d\n",pos);
	return 0;
}
