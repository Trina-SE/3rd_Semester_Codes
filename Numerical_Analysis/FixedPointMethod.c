#include<stdio.h>
#include<math.h>
#define n 200
#define f(x) ((x)*(x)*(x)+4*(x)*(x)-10)
#define g(x) sqrt((10-(x)*(x)*(x))/4)
int main()
{
    int i;
    double x0=1.5,x1,fx1,tol=1e-5;
    printf("Iter       x0          \t   x1     \t  g(x0)      \t  f(x1)\n");
    printf("-------------------------------------------------------------------------------\n");
     for(i=1;i<n;i++){
        x1=g(x0);
        fx1=f(x1);
        printf("%d       %lf\t  %lf\t %lf\t %lf\n",i,x0,x1,g(x0),fx1);
        printf("-----------------------------------------------------------------------------\n");
          if(fabs(fx1)<=tol){
            printf("Root=%lf\nIteration->%d",x1,i);
            break;
          }
          x0=x1;
     }
     if(i==n) printf("Iteration overflow\n");
}
