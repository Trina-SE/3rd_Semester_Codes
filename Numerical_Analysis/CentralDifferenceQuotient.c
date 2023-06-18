#include<stdio.h>
#include<math.h>
#define n 10

int main()
{
    int i;
    double a=0.0,b=2.0,h;
    double x[n+1],f[n+1],df[n+1];
    h=(b-a)/n;
    x[0]=a;
    for(i=1;i<n;i++){
        x[i]=x[i-1]+h;
    }
    x[i]=b;
    for(i=0;i<=n;i++){
        f[i]=x[i]*x[i]+1;
    }
    for(i=1;i<n;i++){
        df[i]=(f[i+1]-f[i-1])/(x[i+1]-x[i-1]);
    }
    printf("i   x[i]            f(x[i])        f'(x[i])\n");
    printf("----------------------------------------------\n");
    printf("0   %lf       %lf         ----\n",x[0],f[0]);
    printf("---------------------------------------------\n");
     for(i=1;i<n;i++){
        printf("%d   %lf       %lf       %lf\n",i,x[i],f[i],df[i]);
        printf("---------------------------------------------\n");
     }
     printf("%d  %lf       %lf         ----\n",i,x[i],f[i]);
     printf("---------------------------------------------\n");
}
