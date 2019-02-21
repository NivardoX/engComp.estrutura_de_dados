#include <stdio.h>

int main()
{

	int n = 12;
	char op;	
	op = getchar();


	double soma = 0;
	int i,j;
	float z;
	int aux = 0;
	int count = 0;
	
	for ( i = 12; i > 0;i--)
		{
			for (j =0 ; j < 12; j++)
			{
				scanf("%f",&z);
				if(j < i -1){
					soma += z;
					aux++;	
				}
			}
		}	

	if(op =='S')
		printf("%.1f\n",soma);
	else if(op == 'M')
		printf("%.1f\n",soma/aux);
}