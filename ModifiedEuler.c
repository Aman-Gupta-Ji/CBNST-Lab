#include<stdio.h>
#include<math.h>

double g(double x,double y) {
    return -x*y*y;
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
    printf("Enter allowed error e : ");
    scanf("%lf",&e);
    h=(x-x0)/n;
    printf("\nh = %lf",h);
    double hg, y1, yc, x1;
    for(i=0;i<n;i++) {
        x1=x0+h;
        hg=g(x0,y0);
        printf("\nY%d\t= %lf + %lf * %lf",i+1,y0,h,hg);
        hg*=h;
        printf("\n\t= %lf + %lf",y0,hg);
        y1=y0+hg;
        printf("\n\t= %lf",y1);
        printf("\nf( %lf ) = %lf ",x1,y1);
        cc=1;
        do {
            yc=y1;
            y1=y0+h*(g(x0,y0)+g(x1,yc))/2;
            printf("\nCorrction %d\t= %lf + h/2 * ( %lf + %lf )\n\t\t=%lf",cc++,y0,g(x0,y0),g(x1,y1),y1);
        }while(fabs(y1-yc)>e);
        x0=x1;
        y0=y1;
        printf("\nf( %lf ) = %lf \n\n",x1,y1);
    }
    printf("\n\nAnswer by Modified Euler's Method \nf( %lf ) = %lf \n",x1,y1);
    return 0;
}