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
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(A[i][i]==0)
			{
				for(e=0;e<n;e++)
				{
					if(A[e][i]!=0)
					{
						for(k=0;k<=n;k++)
							A[i][k]+=A[e][k];
						break;
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
	printf("\nUpper Triangular Matrix\n");
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
	for(i=n-1;i>=0;i--)
	{
		sum=A[i][n];
		for(j=i;j<n;j++)
		    sum=sum-A[i][j]*x[j];
		x[i]=sum/A[i][i];
	}
	
	printf("\nSollution\n");
	for(i=0;i<n;i++)
	    printf("\nX%d = %.4f",i+1,x[i]);
	return 0;
}
