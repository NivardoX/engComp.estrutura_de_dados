#include <stdio.h>

int main()
{
	long long int A[2000] = {0,1,1,2,3,5,8,13,21};
	int maior_index = 8;
	long long int x;
	scanf("%lld",&x);
	while(x--){
		long long int num;
		scanf("%lld",&num);
		if(num > maior_index){
			long long int i = 0;	
			for(i = maior_index ; i < num+1;i++){
				A[i] = A[i-1] + A[i-2];
			}
			maior_index = num;
		}

		printf("Fib(%lld) = %lld\n",num,A[num]);


	}

	return 0;
}
