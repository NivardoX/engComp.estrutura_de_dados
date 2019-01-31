#include <stdio.h>

int main()
{

	int n,i,j;
	int arr[102][102];
 	while (scanf("%d", &n) == 1){
		for ( i = 0; i < n; i++){
			for ( j = 0; j < n; j++){
				if(i+j == n-1){
					arr[i][j] = 2;
					continue;
				
				}
				if(i == j){
				 arr[i][j] = 1;
				
				continue;
				}
				

				arr[i][j] = 3;

			}
		}

		for (i = 0; i < n; i++){
			for( j = 0 ; j < n ; j++){
				printf("%d",arr[i][j]);
			}
			printf("\n");
		}
	
	}
	return 0;
}
