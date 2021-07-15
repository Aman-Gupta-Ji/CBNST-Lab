/* Gauss Seidel Iterative Method */
#include<stdio.h>
#include<math.h>
#define f1(y,z) (3+y+z)/4
#define f2(x,z) (9+2*x-z)/6
#define f3(x,y) (-6+x-y)/7
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
		y1=f2(x1,z0);
		z1=f3(x1,y1);
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
Iteration 1 x1=0.750000 y1=1.750000 z1=-1.000000
Iteration 2 x2=0.937500 y2=1.979167 z2=-1.005952
Iteration 3 x3=0.993304 y3=1.998760 z3=-1.000780
Iteration 4 x4=0.999495 y4=1.999961 z4=-1.000067
Iteration 5 x5=0.999974 y5=2.000002 z5=-1.000004
Iteration 6 x6=1.000000 y6=2.000000 z6=-1.000000
Iteration 7 x7=1.000000 y7=2.000000 z7=-1.000000
Result after 7th iteration
x=1.000000 y=2.000000 z=-1.000000
*/
