#include<stdio.h>
#include <stdlib.h>
int pilha[60];
int pilha2[60];
int fim = 0;
int fim2 = 0;


void makeStack(){
	for (int i = 0; i < fim+1; i++)
	{
		pilha[fim - i] = i;
	}
}

void remakeStack(){
	int fim = 0;
	int fim2 = 0;
	for (int i = 0; i < 60; i++)
	{
		pilha[i] = 0;
		pilha2[i] = 0;
	}


}

void pop(){
	pilha2[fim2++] = pilha[fim-1];
	pilha[fim-1] = 0;
	fim--;

	//printf("POP\n");
}

void pushFront(){
	int n = pilha[fim-1];
	
	for (int i = 0; i < fim; i++)
	{
	 	pilha[fim-1-i] = pilha[fim-i-2];
	}
	pilha[0] = n;
	//	printf("PUSHFRONT\n");

}

void op(){

	pop();
	//printarStack();
	pushFront();
	//printarStack();

}
void printar(){

	 printf("Discarded cards:");
	 for (int i = 0; i < fim2; i++)
	 {
	 	if (i == fim2-1)
	 		printf(" %d", pilha2[i]);
	  	else
	 		printf(" %d,", pilha2[i]);
	 }

	 printf("\nRemaining card: %d\n",pilha[0]);
}
void printarStack(){

	 printf("Pilha1 cards:");
	 for (int i = 0; i < fim; i++)
	 {
	 	printf(" %d,", pilha[i]);
	 }

 	printf("\nPilha2 cards:");
	 for (int i = 0; i < fim2; i++)
	 {
	 	printf(" %d,", pilha2[i]);
	 }
	 printf("\n");

}


int main(int argc, char const *argv[])
{
	int N;
	remakeStack();
	while(scanf("%d",&N) != 0){
		remakeStack();
		fim2 = 0;
		if (N == 0)
			break;

		fim = N;
		makeStack();

	//	printarStack();
		for (int i = 0; i < N -1; i++)
		{
			op();
		}

		printar();
		remakeStack();
	}
		
	return 0;
	
}
