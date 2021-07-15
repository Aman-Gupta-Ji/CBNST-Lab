/* Iterative Method
1) Take 2 initial input : x1 & x2
	such that f(x1)*f(x2)<0 
2) x = q(x)
3) q`(x)
4) if |q`(x1)|<1 && |q`(x2)|<1
	print("function is correct");
5) x0 = is the initial quess at which the function gives smaller value
6) x3 = q(x0)
7) if |x0-x3|<=error then x3 ans
	else x0=x3 */

#include<stdio.h>
#include<math.h>
#define f(x) (x*x*x-4*x-9)
#define g(x) (pow((4*x+9),1/3.0))
#define dg(x) (4/3.0*pow((4*x+9),-2/3.0))

int main(void)
{
	printf("\nIterative Method\n");
	float x1,x2,err;
	do
	{
		printf("\nEnter initial approximation x1 & x2 : ");
		scanf("%f%f",&x1,&x2);
	}while(f(x1)*f(x2)>=0);
	if(fabs(dg(x1))<1&&fabs(dg(x2))<1)
		printf("\nFunction is Correct and coverges ");
	else
	{
		printf("\nFunction does not coverges ");
		return 1;
	}
	printf("\nEnter acceptable error : ");
	scanf("%f",&err);
	
	float x0,x3;
	x3=(x1+x2)/2;
	/* OR
	if(fabs(f(x1))<fabs(f(x2)))
		x3=x1;
	else
		x3=x2;
	*/
	int count=0;
	do
	{
		count++;
		x0=x3;
		x3=g(x0);
		printf("\nIteration %d x%d = %f ",count,count,x3);
	}while(fabs(x3-x0)>=err);
	printf("\nRoot of the equation = %f \nafter %d Iterations \n",x3,count);
	
	return 0;
}
