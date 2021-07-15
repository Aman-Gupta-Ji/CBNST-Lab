#include<stdio.h>

int main(void) {
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
	double x[n], y[n], X;
	for(i=0;i<n;i++)
		scanf("%lf%lf",&x[i],&y[i]);
	printf("\nData inputed by the user\nx\t\ty\n");
	for(i=0;i<n;i++)
		printf("%lf\t%lf\n",x[i],y[i]);
	X=y[0]+y[n-1];
    for(i=1;i<n-1;i++)
        X+=2*y[i];
	double h=x[1]-x[0];
    printf("\nX is %lf\n",X);
    X=X*h/2;
    printf("\nNumerical Integration Using Trapezoidal Rule \n%lf\n",X);
    return 0;
}