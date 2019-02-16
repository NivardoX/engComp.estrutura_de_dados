#include <stdio.h>

int main(int argc, char const *argv[]){
	char entrada[10001];	
	char aux[1001];	
	while(scanf("%s",entrada) != EOF){
		int i = 0,j = 0,z;

		while(entrada[i++] != '\0'){
			if(entrada[i-1] == ')' || entrada[i-1] == '(')
				aux[j++] = entrada[i-1];
		}
		aux[j] = '\0';
		
		for(i = j-1; i >= 0; i--){
			if(aux[i] == '(' && aux[i+1] == ')'){
				for(z = i+1; z < j;z++){
					aux[z] = aux[z+1];					
				}
				j--;
				for(z = i; z < j;z++){
					aux[z] = aux[z+1];					
				}

				j--;
				aux[j] = '\0'; 

			}
		}
		printf("%s\n",(aux[0] == '\0'?"correct":"incorrect"));
	}
	return 0;
}
