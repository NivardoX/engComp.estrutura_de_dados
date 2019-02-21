#include <stdio.h>

int main(int argc, char const *argv[])
{


	while(1){	
		int n;
		scanf("%d",&n);
		if(!n)
			return 0;

		int i,j;
		for (i = 0; i < n; i++){
				for( j = 0 ; j < n ; j++){
					int xe = i,xd = n -1-i,yc=j,yb = n-1-j;

					int menor = 150;

					menor = (menor<xe?menor:xe);
					menor = (menor<xd?menor:xd); 
					menor = (menor<yc?menor:yc);
					menor = (menor<yb?menor:yb);
					menor++;
					if(j == n-1)
						printf("%3d",menor);
					else	
						printf("%3d ",menor);
				}
				printf("\n");
			}
			printf("\n");
	}
}