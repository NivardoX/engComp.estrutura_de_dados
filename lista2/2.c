#include <stdio.h>

int main(int argc, char const *argv[])
{

	int n;
	scanf("%d",&n);
	getchar();
	char op;	
	scanf("%c",&op);	

	double soma = 0;
	int i;
	for (i = 0; i < 144; i++){
		float z;
		scanf("%f",&z);
		if(i%12 == n){
			soma += z;
		}
	}				

	if(op =='S')
		printf("%.1f\n",soma);
	else
			printf("%.1f\n",soma/12);
}