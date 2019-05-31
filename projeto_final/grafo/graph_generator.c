#include<stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int n,x;
	scanf("%d,%d",&n,&x);
	/* code */ FILE *file;
 	 file=fopen("graph.txt", "w+");

 	 int MAT[n][n];
 	 srand(0);
	for(int i = 0; i < n; i++)
	{
	    for(int j = i; j < n; j++)
	    {
	        if(i == j){
	            MAT[i][j] = 0;
	        }

	        else{
	            int r = rand() % 10;
	            int val = (r == 5)? x: r;
	            MAT[i][j] = val;
	            MAT[j][i] = val;  // If there is edge from i to j, then there
	                               // must be edge from j to i
	        }

	    }
	}
	fprintf(file, "%d\n",n);
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