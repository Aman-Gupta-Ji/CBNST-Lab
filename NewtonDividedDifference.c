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
	double x[n], y[n][n], X;
	for(i=0;i<n;i++)
		scanf("%lf%lf",&x[i],&y[i][0]);
	printf("\nData inputed by the user\nx\t\ty\n");
	for(i=0;i<n;i++)
		printf("%lf\t%lf\n",x[i],y[i][0]);
	printf("\nEnter the value of x to find the value of y at that instance :\n");
	scanf("%lf",&X);
    int start;
	for(j=1;j<n;j++)
	{
        start=0;
		for(i=0;i<=(n-j);i++,start++)
			y[i][j]=(y[i+1][j-1]-y[i][j-1])/(x[start+j]-x[start]);
	}
	printf("\nNewton Divided Difference table\nx\t\ty");
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
	double f=y[0][0], series=1, mid;
	for(j=1;j<n;j++)
	{
        series*=X-x[j-1];
		mid=series*y[0][j];
        printf("\n (%d) %lf",j, mid);
		f+=mid;
	}
	printf("\nBy Newton Divided Difference Substitution \nfor x = %lf\t y = %lf \n",X,f);
	return 0;
}