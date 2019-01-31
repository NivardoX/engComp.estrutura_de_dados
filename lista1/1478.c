#include <stdio.h>

int main()
{

	int n,i,j;
	
	while(1){
	
		scanf("%d",&n);
		if(n == 0)
			break;

		int arr[102][102];
		for ( i = 0; i < n; i++){
				arr[i][i] = 1;
			
		}
		

		for ( i = 0; i < n; i++){
			for ( j = 1; j < n; j++){
				 arr[i][i+j] = j+1;
					
			}
			int aux = i;
			int count = 0;
			while(aux--){
				arr[i][i - count++] = count; 	
			}
		}
		
		for (i = 0; i < n; i++){
			arr[i][0] = i+1;
			for( j = 0 ; j < n ; j++){
				if(j == n-1)
				printf("%d",arr[i][j]);
				else	
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
	
	}
	return 0;
}
