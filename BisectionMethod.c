#include<stdio.h>
#include<math.h>

float f(float x)
{
	return(x*x*x-x-1);
}

int main(void)
{
	printf("x^3-8");
	float x, x1, x2, err, y;
	do
	{
		printf("\nEnter initial approximaion x1 & x2 : ");
		scanf("%f%f",&x1,&x2);
	}while(f(x1)*f(x2)>=0);
	printf("\nEnter Alowwed Error : ");
	scanf("%f",&err);
	int itr=1;
	y=x1;
	printf("\n\nf( %f ) = %f ",x1,f(x1));
	printf("\n\nf( %f ) = %f ",x2,f(x2));
	while(1)
	{
		x=(x1+x2)/2;
		if(fabs(x-y)<err)
		{
			printf("\nResult after %d iterations root x : %f\n",itr,x);
			break;
		}
		if(f(x)*f(x2)<0)
		    x1=x;
   		else if(f(x1)*f(x)<0)
	        x2=x;
   		y=x;
   		printf("\n\n%d iteration x : %f",itr,x);
		printf("\nf( %f ) = %f ",x,f(x));
   		itr++;
	}
	return 0;
}
