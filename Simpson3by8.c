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
	double x[n], y[n], X, summod3=0, sumdiv3=0;
	for(i=0;i<n;i++)
		scanf("%lf%lf",&x[i],&y[i]);
	printf("\nData inputed by the user\nx\t\ty\n");
	for(i=0;i<n;i++)
		printf("%lf\t%lf\n",x[i],y[i]);
	X=y[0]+y[n-1];
    for(i=1;i<n-1;i++) {
        if(i%3==0)
            sumdiv3+=y[i];
        else
            summod3+=y[i];
    }
	double h=x[1]-x[0];
    printf("\nsum mod 3 is %lf\nsum div 3 is %lf\n",summod3,sumdiv3);
    X=(y[0]+y[n-1]+3*summod3+2*sumdiv3)*3*h/8;
    printf("\nNumerical Integration Using Simpson 3/8 Rule \n%lf\n",X);
    return 0;
}