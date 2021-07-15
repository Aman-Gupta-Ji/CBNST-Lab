#include<stdio.h>
#include<stdlib.h>

float* Solveliner(int n, float A[][n+1], float x[])//Using Gauss Jorden Method
{
	int i, j, k, e, l, m;
	if(n<=0)
	{
		if(n==0)
				n=-1;
		n=n*-1;
	}
	printf("\nMatrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
	 	{
	 		printf("%.4f\t\t",A[i][j]);
	 	}
	 	printf("\n");
	}
	float r;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==i)
			    continue;
			if(A[i][i]==0)
			{
				for(e=0;e<n;e++)
				{
					if(A[e][i]!=0)
					{
						for(k=0;k<=n;k++)
							A[i][k]+=A[e][k];
					}
				}
			}
			r=A[j][i]/A[i][i];
			for(k=0;k<=n;k++)
		  	    A[j][k]=A[j][k]-r*A[i][k];
		}
		printf("\nMatrix in step %d\n",i+1);
		for(l=0;l<n;l++)
		{
			for(m=0;m<=n;m++)
	 		{
	 			printf("%.4f\t\t",A[l][m]);
	 		}
	 		printf("\n");
		}
	}
	printf("\nDiagnoal Matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
	 	{
	 		printf("%.4f\t\t",A[i][j]);
	 	}
	 	printf("\n");
	}
	float sum;
	for(i=0;i<n;i++)
	{
		x[i]=A[i][n]/A[i][i];
	}
	return x;
}


int main(void)
{
	printf("Enter the total no of observations\n");
	int n, i, j;
	scanf("%d",&n);
	if (n<=0)
	{
		if(n==0)
			n=-1;
		n*=-1;
	}
	printf("Enter the data in tabular form\nx\t\ty \n");
	double x[n], y[n], xy[n], xsq[n];
	double sx,sy,sxy,sxsq;
    sx=sy=sxy=sxsq=0;
	for(i=0;i<n;i++) {
		scanf("%lf%lf",&x[i],&y[i]);
        xy[i]=x[i]*y[i];
        xsq[i]=x[i]*x[i];
        sx+=x[i];
        sy+=y[i];
        sxy+=xy[i];
        sxsq+=xsq[i];
    }
	printf("\nTable\nx\t\ty\t\txy\t\tx^2\n");
	for(i=0;i<n;i++)
		printf("%f\t%f\t%f\t%f\n",x[i],y[i],xy[i],xsq[i]);
    printf("\nSum\nx\t\ty\t\txy\t\tx^2\n");
    printf("%f\t%f\t%f\t%f\n",sx,sy,sxy,sxsq);
    printf("\nEquations\n");
    printf("\n%lf a + %lf b = %lf", 1.0*n, sx, sy);
    printf("\n%lf a + %lf b = %lf", sx, sxsq, sxy);
    float Ar[2][3], r[2];
    Ar[0][0]=n;
    Ar[0][1]=sx;
    Ar[0][2]=sy;
    Ar[1][0]=sx;
    Ar[1][1]=sxsq;
    Ar[1][2]=sxy;
    Solveliner(2,Ar,r);
    printf("\nSolution\nY = %lf + %lf x\n",r[0],r[1]);
	return 0;
}