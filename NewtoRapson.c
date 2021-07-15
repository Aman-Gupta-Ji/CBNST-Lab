#include<stdio.h>
#include<math.h>

float f(float x)
{
	return (x*x-5*x+2);
}
float fd(float x)
{
	return (2*x-5);
}
int main(void)
{
	float x0, x1, err;
	printf("Enter the initial aproximation : ");
	scanf("%f",&x1);
	printf("Enter the accepted error : ");
	scanf("%f",&err);
	int count=1;
	do
	{
		x0=x1;
		x1=x0-f(x0)/fd(x0);
		printf("\n f( %f ) / f'( %f ) = %f / %f = %f \n",x0,x0,f(x0),fd(x0),f(x0)/fd(x0));
		printf("%d iteration x%d : %f\n",count,count,x1);
		count++;
	}while(fabs(x0-x1)>err);
	printf("\nAnswer after %d iterations : %f\n",count-1,x1);
	return 0;
}
