#include<math.h>
#include<stdlib.h>
#define M 4

void main()
{
    double arraycons[M][M]={{2.04,-1,0,0},
                            {-1,2.04,-1,0},
                            {0,-1,2.04,-1},
                            {0,0,-1,2.04}};
    double arrayres[M]={{40.8},
                        {0.8},
                        {0.8},
                        {200.8}};
    double alpha[M];
    double g[M];
    double u[M];
    int i,j;
    double epsilon[M];

    alpha[0]=arraycons[0][0];
    for(i=1;i<M;i++)
    {
        alpha[i]=arraycons[i][i]-(arraycons[i][i-1]*arraycons[i-1][i])/alpha[i-1];
    }


    g[0]=arrayres[0];
    for(i=1;i<M;i++)
    {
        g[i]=arrayres[i]-((arraycons[i][i-1]*g[i-1])/alpha[i-1]);
    }



    u[M-1]=g[M-1]/alpha[M-1];
    for(i=M-2;i>=0;i--)
    {
        j=-1*(i-M)-1;
        u[i]=(g[i]-arraycons[i][i+1]*u[i+1])/alpha[i];
    }

    for(i=1;i<M-1;i++)
    {
        epsilon[i]=(arraycons[i][i-1]*u[i-1]+arraycons[i][i]*u[i]+arraycons[i-1][i]*u[i+1]-arrayres[i])/(fabs(arraycons[i][i-1]*u[i-1])+fabs(arraycons[i][i]*u[i])+fabs(arraycons[i-1][i]*u[i+1])+fabs(arrayres[i]));
        if (epsilon[i]>0.0001)
        printf("epsilon too large\n");
    }
    printf("U Values:\tEpsilon Values:\n");
    for(i=0;i<M;i++)
    {
        printf("%f\t%f",u[i]);
        printf("\n");
    }
}
