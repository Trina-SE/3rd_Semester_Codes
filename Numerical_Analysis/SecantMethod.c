#include<stdio.h>
#include<math.h>
#define maxN 200
#define f(x) ((x)*(x)*(x)+4*(x)*(x)-10)
int main()
{
    int i;
    double x0=1.5,x1=2.0,x2,fx0,fx1,fx2,tol=1e-6; printf("%lf\n",tol);
    fx0=f(x0);
    fx1=f(x1);
    printf("Iter       x0          \t   x1     \t  x2      \t  f(x0)      \t  f(x1)      \t  f(x2)\n");
    printf("---------------------------------------------------------------------------------------------------\n");
      for(i=1;i<maxN;i++){
        x2=x1-(x1-x0)/(fx1-fx0)*fx1;
        fx2=f(x2);
        printf("%d       %lf\t  %lf\t %lf\t %lf\t %lf\t  %lf\n",i,x0,x1,x2,fx0,fx1,fx2);
        printf("---------------------------------------------------------------------------------------------------\n");
        if(fabs(fx2)<=tol){
            printf("Root=%lf\nIteration->%d",x2,i);
            break;
        }
        x0=x1;
        x1=x2;
        fx0=fx1;
        fx1=fx2;
      }
      if(i==maxN) printf("Iteration overflow\n");
}
