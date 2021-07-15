#include<stdio.h>
#include<math.h>

double f(double x) {
    return 17-3.5*x*x+2*x;
}
int main(void) {
    printf("\nEnter x0\th\tn \n");
    double x0, h;
    int n, i;
    scanf("%lf%lf%d",&x0,&h,&n);
    printf("\nx\t\ty\n");
    for(i=0;i<n;i++,x0+=h)
        printf("%lf\t%lf\n",x0,f(x0));
    return 0;
}