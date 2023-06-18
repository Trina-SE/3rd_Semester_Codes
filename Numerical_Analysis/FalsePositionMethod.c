#include<stdio.h>
#include<math.h>
#define n 200
#define f(x) ((x)*(x)*(x)+4*(x)*(x)-10)
int main()
{
    int i;
    double a=1.25,b=1.5,c,fa,fb,fc,tol=1e-5;
    fa=f(a);
    fb=f(b);
     if(fa*fb>=0){
        printf("No root..");
        return 0;
     }
    printf("Iter        a          \t    b     \t   c      \t  f(a)      \t  f(b)      \t  f(c)\n");
    printf("---------------------------------------------------------------------------------------------------\n");
     for(i=1;i<n;i++){
        c=(a*fb-b*fa)/(fb-fa);
        fc=f(c);
        printf("%d       %lf\t  %lf\t %lf\t %lf\t %lf\t  %lf\n",i,a,b,c,fa,fb,fc);
        printf("---------------------------------------------------------------------------------------------------\n");
          if(fabs(fc)<=tol){
            printf("Root=%lf\nIteration->%d",c,i);
            break;
          }
          if(fa*fc<0){
            b=c;
            fb=fc;
          }
          else{
            a=c;
            fa=fc;
          }
     }
      if(i==n) printf("Iteration overflow\n");
}
