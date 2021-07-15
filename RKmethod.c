#include<stdio.h>
#include<math.h>

double g(double x,double y) {
    return 1/(x*x)-y/x-y*y;
}

int main(void) {
    double x0, y0, x, h, e;
    printf("\nEnter x0 and y0 \n");
    scanf("%lf%lf",&x0,&y0);
    printf("\nEnter x \n");
    scanf("%lf",&x);
    int n, i, cc;
    printf("\nEnter the value of n : ");
    scanf("%d",&n);
    h=(x-x0)/n;
    printf("\nh = %lf\n",h);
    double hg, y1, yc, x1, k1, k2, k3, k4, k;
    for(i=0;i<n;i++) {
        x1=x0+h;
        printf("Y%d",i+1);
        k1=h*g(x0,y0);
        printf("\nk1\t=h * %lf",g(x0,y0));
        printf("\n\t= %lf",k1);
        k2=h*g(x0+h/2,y0+k1/2);
        printf("\nk2\t=h * %lf",g(x0+h/2,y0+k1/2));
        printf("\n\t= %lf",k2);
        k3=h*g(x0+h/2,y0+k2/2);
        printf("\nk3\t=h * %lf",g(x0+h/2,y0+k2/2));
        printf("\n\t= %lf",k3);
        k4=h*g(x0+h,y0+k3);
        printf("\nk4\t=h * %lf",g(x0+h,y0+k3));
        printf("\n\t= %lf",k4);
        k=k1+2*k2+2*k3+k4;
        printf("\nk\t= %lf / 6",k);
        k/=6;
        printf("\n\t= %lf",k);
        y1=y0+k;
        x0=x1;
        y0=y1;
        printf("\nf( %lf ) = %lf \n\n",x1,y1);
    }
    printf("\n\nAnswer by Euler's Method \nf( %lf ) = %lf \n",x1,y1);
    return 0;
}