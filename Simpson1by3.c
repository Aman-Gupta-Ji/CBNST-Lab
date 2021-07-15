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
	double x[n], y[n], X, sumodd=0, sumeven=0;
	for(i=0;i<n;i++)
		scanf("%lf%lf",&x[i],&y[i]);
	printf("\nData inputed by the user\nx\t\ty\n");
	for(i=0;i<n;i++)
		printf("%lf\t%lf\n",x[i],y[i]);
	X=y[0]+y[n-1];
    for(i=1;i<n-1;i++) {
        if(i%2==0)
            sumeven+=y[i];
        else
            sumodd+=y[i];
    }
	double h=x[1]-x[0];
    printf("\nsum odd is %lf\nsum even is %lf\n",sumodd,sumeven);
    X=(y[0]+y[n-1]+4*sumodd+2*sumeven)*h/3;
    printf("\nNumerical Integration Using Simpsons 1/3 Rule \n%lf\n",X);
    return 0;
}