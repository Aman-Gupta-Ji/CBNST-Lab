/* Regula Falsi Method (Method of False Position)
1) Take 2 initial inputs: x1 & x2
	such that f(x1)*f(x2) < 0
2) Apply Regular Falsi Method to get the value of x
	x = x1 - (x2-x1)f(x1)/(f(x2)-f(x1))
3) if f(x1)*f(x)<0, then set x2=x
	if f(x)*f(x2)<0, then set x1=x 
4) if f(x)<=error, then print the root of equation */

#include<stdio.h>
#include<math.h>
#define f(x) (x*x*x-4*x-9)

int main(void)
{
	float x1, x2, err;
	printf("\nRegular Falsi Method or Method of False Position\n");
	do
	{
		printf("\nEnter initial approximaion x1 & x2 : ");
		scanf("%f%f",&x1,&x2);
	}while(f(x1)*f(x2)>=0);
	printf("\nEnter accepted error : ");
	scanf("%f",&err);
	
	float x;
	int count=0;
	do
	{
		count++;
		x=x1-(x2-x1)*f(x1)/(f(x2)-f(x1));
		if(f(x1)*f(x)<0)
			x2=x;
		else if(f(x)*f(x2)<0)
			x1=x;
		printf("\nIteration %d x%d = %f ",count,count,x);
	}while(fabs(f(x))>err);
	printf("\nRoot of the equation = %f \nafter %d Iteration \n",x,count);
	
	return 0;
}
