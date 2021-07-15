#include<stdio.h>
int main()
{
    int n=3;
    float co[3][2];
    int i,j,y,k;
    for(i=0;i<3;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%f",&co[i][j]);
        }
    }
    float arr[n][n+1];
    for(i=0;i<n;i++)
    {
        arr[i][0] = co[i][0]*co[i][0];
        arr[i][1] = co[i][0];
        arr[i][2] = 1;
        arr[i][3] = co[i][1];
    }
    int x;
    for(j = 0;j<n-1;j++)
    {
        for(i=j+1;i<n;i++)
        {
            if(arr[j][j]==0)
            {
                for(x= i;x<n;x++)
                {
                    if(arr[x][j]!=0)
                    {
                        for(y= 0;y<n+1;y++)
                            arr[j][y] += arr[x][y];
                        break;
                    }
                }
            }

            float temp = arr[i][j]/arr[j][j];
            for(k=0;k<n+1;k++)
            {
                arr[i][k]= arr[i][k]-temp*arr[j][k];
            }
        }
    }
    int roots[n];
    for(i = n-1;i>=0;i--)
    {
        float sum = 0;
        for(j = n-1;j>i;j--)
            sum += arr[i][j]*roots[j];
        roots[i] = (int)((arr[i][n]-sum)/arr[i][i]);
    }
    printf("y=%dx^2",roots[0]);
    if(roots[1]<0)
    printf("%dx",roots[1]);
    else
    printf("+%dx",roots[2]);
    if(roots[2]<0)
    printf("%d",roots[2]);
    else
    printf("+%d",roots[2]);
    printf("\n");
}