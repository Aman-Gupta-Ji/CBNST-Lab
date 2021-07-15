/* Secant Method (Method of False Position)
1) Take 2 initial inputs: x1 & x2
	such that f(x1)*f(x2) < 0
2) Apply Secant Method to get the value of x
	x = x1 - (x2-x1)f(x1)/(f(x2)-f(x1))
3) x1=x2
   x2=x 
4) if f(x)<=error, then print the root of equation */

#include<stdio.h>
#include<math.h>
#define f(x) (x*x*x+4*x-10)

int main(void)
{
	float x1, x2, err;
	printf("\nSecant Method\n");
	printf("\nEnter initial approximation x1 & x2 : ");
	b: scanf("%f%f",&x1,&x2);
	if (f(x1)*f(x2)>=0) {
		printf("\nTry again Wrong initial approximation x1 & x2 : ");
		goto b;
	}
	printf("\nEnter accepted error : ");
	scanf("%f",&err);
	
	float x;
	int count=0;
	do
	{
		count++;
		x=x1-(x2-x1)*f(x1)/(f(x2)-f(x1));
		x1=x2;
		x2=x;
		printf("\nIteration %d x%d = %f ",count,count,x);
	}while(fabs(f(x))>err);
	printf("\nRoot of the equation = %f \nafter %d Iteration \n",x,count);
	
	return 0;
}
