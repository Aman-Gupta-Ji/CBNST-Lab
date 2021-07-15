#include<stdio.h>

int main(void)
{
	int n, i, j, k, e, l, m;
	printf("Enter the number of unknown variables in the equation : ");
	scanf("%d",&n);
	if(n<=0)
	{
		if(n==0)
				n=-1;
		n=n*-1;
	}
	float A[n][n+1];
	printf("Enter the cofficients of the eqation \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
	        scanf("%f",&A[i][j]);
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
		printf("\nMatrix in %d\n",i);
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
	float x[n];
	for(i=0;i<n;i++)
	{
		x[i]=A[i][n]/A[i][i];
	}
	
	printf("\nSollution\n");
	for(i=0;i<n;i++)
	    printf("\nX%d = %.4f",i+1,x[i]);
	return 0;
}
