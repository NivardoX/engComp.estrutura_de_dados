#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{
	int n = atoi( argv[1]);
	int x = atoi(argv[2]);
	//printf("Entre com a quantidade de vertices e o custo maximo.\n");
	//scanf("%d,%d",&n,&x);
	/* code */ FILE *file;
 	 file=fopen("graph.txt", "w+");

 	 int MAT[n][n];
 	 srand(time(NULL));
	for(int i = 0; i < n; i++)
	{
	    for(int j = i; j < n; j++)
	    {
	        if(i == j){
	            MAT[i][j] = 0;
	        }

	        else{
	            int val = rand() % x;
	            val = val<(int)(x/1.2)?0:val;
	            val =val==0? 0:(rand() % x);
	            MAT[i][j] = val;
	            MAT[j][i] = val;  // If there is edge from i to j, then there
	                               // must be edge from j to i
	        }

	    }
	}
	fprintf(file, "%d,%d\n",n,x);
	for(int i = 0; i < n; i++)
	{
	    for(int j = 0; j < n; j++)
	    {
			fprintf(file, "%d, ",MAT[i][j]);

		}
		fprintf(file, "\n");
	}
	return 0;
}