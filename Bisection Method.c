//x^2+sin(x)-e^x=0
#include<stdio.h>
#include<math.h>	// power, sin, log funtions

double f(double x)	//funtion f(x)
{
	return (x*x+sin(x)-exp(x));
}

void bisection(double*x, double a, double b, int*itr)
{	/*this function performs and prints the results of one iteration*/
	
	++(*itr);
	*x=(a+b)/2;
	printf("Iteration no. %3dx\t=\t%7.5lf\n",*itr,*x);
}

int main()
{
	int itr=0,maxmitr;
	double x,a,b,allerr,x1;
	printf("\nEnter the value of a, b, allowed error, and maximum iterations : \n");
	scanf("%lf%lf%lf%d",&a,&b,&allerr,&maxmitr);
	printf("\na = %6.4lf\t b = %6.4lf\nallowed error = %9.8lf\nmaximum iterations = %d\n\n",a,b,allerr,maxmitr);
	
	bisection(&x,a,b,&itr);
	do
	{
		if(f(a)*f(x)<0)
  		    b=x;
		else
  		    a=x;
		bisection(&x1,a,b,&itr);
		if(fabs(x1-x)<allerr)
		{
			printf("\nAfter %d iteration Root = %6.4lf\n",itr,x1);
			return 0;
		}
		x=x1;
	}while(itr<maxmitr);
	
	printf("\nThe solution does not converge or iterations are not sufficient");
	return 1;
}
