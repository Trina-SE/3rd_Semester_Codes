#include<stdio.h>
#include<math.h>
#define n 200
#define f(x) ((x)*(x)*(x)+4*(x)*(x)-10)
#define df(x) (3*(x)*(x)+8*(x))

int main()
{
    int i;
    double x0=1.5,x1,fx0,dfx0,fx1,tol=1e-6;
    fx0=f(x0);
    dfx0=df(x0);
    printf("Iter       x0          \t   x1     \t  f(x0)      \t  f'(x0)      \t  f(x1)\n");
    printf("---------------------------------------------------------------------------------------------------\n");
     for(i=1;i<n;i++){
        x1=x0-(fx0/dfx0);
        fx1=f(x1);
        printf("%d       %lf\t  %lf\t %lf\t %lf\t %lf\n",i,x0,x1,fx0,dfx0,fx1);
        printf("---------------------------------------------------------------------------------------------------\n");
          if(fabs(fx1)<=tol){
            printf("Root=%lf\nIteration->%d",x1,i);
            break;
          }
          x0=x1;
          fx0=fx1;
          dfx0=df(x1);
     }
     if(i==n) printf("Iteration overflow\n");
}
