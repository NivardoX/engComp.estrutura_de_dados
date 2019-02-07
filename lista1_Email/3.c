#include <stdio.h>
void dot_product1(double v[5][4], double u[4][3]){


	for (int k = 1; k < 16; k++)
	{
		
		int sum  = 0;
		for (int j = 0; j < 5;j++)
		{
			sum = 0;
			for (int i = 0; i < 4 ; i++)
			{
				sum += v[i][j] * u[i][k%3] ;
			}	
			
			
		}
		if (k%3 == 0)
				printf("%d\n",sum );					
			else
				printf("%d ",sum );			
			
	}
}



int main(int argc, char const *argv[])
{
	double A[5][4],B[4][3];

	printf("Insira os 20 numeros da matriz 4x5\n");
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			
			scanf("%lf",&A[j][i]);
		}
	}
	printf("Insira os 12 numeros da matriz 4x3\n");

	for (int j = 0; j < 4; j++)	
	{
		for (int i = 0; i < 3; i++)
		{
			
			scanf("%lf",&B[j][i]);
		}
	}

	dot_product1(A,B);

}