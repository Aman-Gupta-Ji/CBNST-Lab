#include<stdio.h>
#include<stdlib.h>

float* Solveliner(int n, float A[][n+1], float x[])//Using Gauss Jorden Method
{
	int i, j, k, e, l, m;
	if(n<=0)
	{
		if(n==0)
				n=-1;
		n=n*-1;
	}
	printf("\nMatrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
	 	{
	 		printf("%.4f\t\t",A[i][j]);
	 	}
	 	printf("\n");
	}
	float r;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==i)
			    continue;
			if(A[i][i]==0)
			{
				for(e=0;e<n;e++)
				{
					if(A[e][i]!=0)
					{
						for(k=0;k<=n;k++)
							A[i][k]+=A[e][k];
					}
				}
			}
			r=A[j][i]/A[i][i];
			for(k=0;k<=n;k++)
		  	    A[j][k]=A[j][k]-r*A[i][k];
		}
		printf("\nMatrix in step %d\n",i+1);
		for(l=0;l<n;l++)
		{
			for(m=0;m<=n;m++)
	 		{
	 			printf("%.4f\t\t",A[l][m]);
	 		}
	 		printf("\n");
		}
	}
	printf("\nDiagnoal Matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
	 	{
	 		printf("%.4f\t\t",A[i][j]);
	 	}
	 	printf("\n");
	}
	float sum;
	for(i=0;i<n;i++)
	{
		x[i]=A[i][n]/A[i][i];
	}
	return x;
}
