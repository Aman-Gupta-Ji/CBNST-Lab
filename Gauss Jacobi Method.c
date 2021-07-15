/* Gauss Jacobi Iterative Method */
#include<stdio.h>
#include<math.h>
#define f1(y,z) (17-y+2*z)/20
#define f2(x,z) (-18-3*x+z)/20
#define f3(x,y) (25-2*x+3*y)/20
int main(void)
{
	float x0,y0,z0,x1,y1,z1;
	x0=y0=z0=0.00;
	float err,e1,e2,e3;
	int count=1;
	printf("Enter allowed Error : ");
	scanf("%f",&err);
	printf("Enter Inital apportimation \n");
	scanf("%f%f%f",&x0,&y0,&z0);
	do
	{
		x1=f1(y0,z0);
		y1=f2(x0,z0);
		z1=f3(x0,y0);
		printf("Iteration %d x%d=%f y%d=%f z%d=%f \n",count,count,x1,count,y1,count,z1);
		e1=fabs(x1-x0);
		e2=fabs(y1-y0);
		e3=fabs(z1-z0);
		x0=x1;
		y0=y1;
		z0=z1;
		count++;
	}while(e1>err||e2>err||e3>err);
	printf("Result after %dth iteration \nx=%f y=%f z=%f \n",count-1,x1,y1,z1);
	return 0;
}
/* OUTPUT
Enter allowed Error : 0.000001
Enter Inital apportimation
0       0       0
Iteration 1 x1=0.850000 y1=-0.900000 z1=1.250000
Iteration 2 x2=1.020000 y2=-0.965000 z2=1.030000
Iteration 3 x3=1.001250 y3=-1.001500 z3=1.003250
Iteration 4 x4=1.000400 y4=-1.000025 z4=0.999650
Iteration 5 x5=0.999966 y5=-1.000077 z5=0.999956
Iteration 6 x6=1.000000 y6=-0.999997 z6=0.999992
Iteration 7 x7=0.999999 y7=-1.000000 z7=1.000000
Iteration 8 x8=1.000000 y8=-1.000000 z8=1.000000
Iteration 9 x9=1.000000 y9=-1.000000 z9=1.000000
Result after 9th iteration
x=1.000000 y=-1.000000 z=1.000000
*/
