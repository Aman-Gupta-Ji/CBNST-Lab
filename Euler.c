#include<stdio.h>
#include<math.h>

double g(double x,double y) {
    return -x*y*y;
}

int main(void) {
    double x0, y0, x, h;
    printf("\nEnter x0 and y0 \n");
    scanf("%lf%lf",&x0,&y0);
    printf("\nEnter x \n");
    scanf("%lf",&x);
    int n,i;
    printf("\nEnter the value of n : ");
    scanf("%d",&n);
    h=(x-x0)/n;
    printf("\nh = %lf",h);
    double hg, y1, x1;
    for(i=0;i<n;i++) {
        x1=x0+h;
        hg=g(x0,y0);
        printf("\nY%d\t= %lf + %lf * %lf",i+1,y0,h,hg);
        hg*=h;
        printf("\n\t= %lf + %lf",y0,hg);
        y1=y0+hg;
        printf("\n\t= %lf",y1);
        printf("\nf( %lf ) = %lf \n",x1,y1);
        y0=y1;
        x0=x1;
    }
    printf("\n\nAnswer by Euler's Method \nf( %lf ) = %lf \n",x1,y1);
    return 0;
}