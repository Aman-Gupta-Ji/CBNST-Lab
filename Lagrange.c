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
	float x[n], y[n], X;
	double fy=0, pro, div;
	for(i=0;i<n;i++)
		scanf("%f%f",&x[i],&y[i]);
	printf("\nData inputed by the user\nx\t\ty\n");
	for(i=0;i<n;i++)
		printf("%f\t%f\n",x[i],y[i]);
	printf("\nEnter the value of x to find the value of y at that instance :\n");
	scanf("%f",&X);
    for(i=0;i<n;i++) {
		pro=div=1;
		if(X==x[i]) {
			printf("X in table f(%f) = %f\n",X,y[i]);
			return 1;
		}
		for(j=0;j<n;j++) {
			if(i==j)
				continue;
			pro*=(X-x[j])/(x[i]-x[j]);
			div*=x[i]-x[j];
		}
		pro*=y[i];
		printf("\t(%d) %lf [/] %lf\n",i,pro,div);
		fy+=pro;
	}
	printf("\n f(%f) = %lf\n",X,fy);
    return 0;
}