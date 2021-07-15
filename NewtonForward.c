#include<stdio.h>
int main()
{
	printf("Enter the total no of observations\n");
	int n, i, j;
	scanf("%d",&n);
	if (n<=0)
	{
		if(n==0)
			n=-1;
		n*=-1;
	}
	printf("Enter the data in tabular form\nx\t\ty \n");
	float x[n], y[n][n], f;
	for(i=0;i<n;i++)
		scanf("%f%f",&x[i],&y[i][0]);
	printf("\nData inputed by the user\nx\t\ty\n");
	for(i=0;i<n;i++)
		printf("%f\t%f\n",x[i],y[i][0]);
	printf("\nEnter the value of x to find the value of y at that instance :\n");
	double u, u1 , h, a;
	scanf("%f",&f);
	h=x[1]-x[0];
	u=(f-x[0])/h;
	u1=u;
	a=y[0][0];
	long fact=1;
	for(j=1;j<n;j++)
	{
		for(i=0;i<=(n-j);i++)
			y[i][j]=y[i+1][j-1]-y[i][j-1];
	}
	printf("\nForward Difference table\nx\t\ty");
	for(i=1;i<n;i++)
	{
		printf("\t\ty%d",i);
	}
	for(i=0;i<n;i++)
	{
		printf("\n%f",x[i]);
		for(j=0;j<(n-i);j++)
			printf("\t%f",y[i][j]);
	}
	for(j=1;j<n;j++)
	{
		a=a+(u1*y[0][j])/fact;
		u1*=(u-j);
		fact*=j+1;
	}
	printf("\nBy Newton Forward Substitution \nfor x = %f\t y = %lf \n",f,a);
	return 0;
}