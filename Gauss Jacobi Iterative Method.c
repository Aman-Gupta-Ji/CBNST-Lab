/* Gauss Jacobi Iterative Method */
#include<stdio.h>
#include<math.h>
float xN(float x0[],float A[],int x,int n)
{
	float sum=A[n];
	for(int i=0;i<n;i++)
	{	
		if(i==x)
  	        continue;
		sum-=A[i]*x0[i];
  	}
  	sum/=A[x];
  	return sum;
}
int main(void)
{
	printf("\nEnter the number of unknown variable : ");
	int n, i, j;
	scanf("%d",&n);
	if(n<0)
 	    n=-1*n;
	else if(n==0)
 	    n=3;
	printf("\nEnter the cofficients of the equations \n");
	float A[n][n+1];
	float Aii=0, Aij=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
	 	{
	 		scanf("%f",&A[i][j]);
	 		if(i==j)
	 		    Aii+=A[i][j];
 			else if(j<n)
 			    Aij+=A[i][j];
	 	}
	}
	if(Aii>Aij)
	{
		printf("\nequation entered are strictly diagonally dominantic therefor Gauss jacobi converges\n");
	}
	else
	{
		printf("!! Does not converges equation not diagonally dominantic\nExiting...");
		return 1;
	}
	printf("\nSet of linear equations :\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%f x%d\t",A[i][j],j+1);
		}
		printf("=\t%f\n",A[i][j]);
	}
	float x0[n], x1[n];
	for(i=0;i<n;i++)
 	    x0[i]=0;
	float err;
	int count=1;
	printf("Enter allowed Error : ");
	scanf("%f",&err);
	printf("Enter Inital apportimation \n");
	for(i=0;i<n;i++)
 	    scanf("%f",&x0[i]);
	int flag;
	do
	{
		printf("\nIteration %d\t",count);
		for(i=0;i<n;i++)
		{
  		    x1[i]=xN(x0,A[i],i,n);
  		    printf(" x%d = %f\t",i+1,x1[i]);
		}
		flag=1;
		for(i=0;i<n;i++)
		{
			if(fabs(x0[i]-x1[i])<err)
		 	    flag=0;
		}
		for(i=0;i<n;i++)
  		    x0[i]=x1[i];
		count++;
	}while(flag);
	printf("\nResult after %dth iteration ",count-1);
	for(i=0;i<n;i++)
	{
  	    printf("x%d\t= %f\t",i+1,x1[i]);
	}
	return 0;
}
/*
10 1 1 12
2 10 1 13
2 2 10 14
*/
