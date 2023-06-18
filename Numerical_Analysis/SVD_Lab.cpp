#include <stdio.h>
#include <math.h>

double a[10][10], d[10][10], s[10][10], s1[10][10], s1t[10][10],trans[10][10],input[10][10],svd[10][10];
double temp[10][10],eigen[100],theta, zero=1e-5, max,pi=3.141592654;
int indx=0,tr=0;

void multiplication (double b[][10],double c[][10],int m,int n){

  int l=n;
  if(m>n) l=m;

 for(int i=0;i<l;i++){
    for(int j=0;j<l;j++){
        a[i][j]=0;
    }
 }

 for(int i=0; i<m; i++){
    for(int j=0; j<m; j++){
       for( int k=0; k<n; k++){
         a[i][j]+=b[i][k]*c[k][j];
       }
    }
  }

}

void jacobi(double a[][10],int n){

    int i,j,flag,p,q;

    for(i=0; i<n; i++){
       for(j=0; j<n; j++){
        d[i][j]= a[i][j];
            if(i==j)
                s[i][j]= 1;
            else
                s[i][j]= 0;
           }
        }

    do
    {
        flag= 0;
        p=0;
        q=1;
        max= fabs(d[p][q]);

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i!=j)
                {
                    if (max < fabs(d[i][j]))
                    {
                        max= fabs(d[i][j]);
                        p = i;
                        q = j;
                    }
                }
            }
        }

        if(d[p][p]==d[q][q])
        {
            if (d[p][q] > 0)
                theta= pi/4;
            else
                theta= -pi/4;
        }
        else
        {
            theta=0.5*atan(2*d[p][q]/(d[p][p]-d[q][q]));
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i==j)
                {
                    s1[i][j]= 1;
                    s1t[i][j]= 1;
                }
                else
                {
                    s1[i][j]= 0;
                    s1t[i][j]= 0;
                }
            }
        }

        s1[p][p]= cos(theta);
        s1t[p][p]= s1[p][p];

        s1[q][q]= cos(theta);
        s1t[q][q]= s1[q][q];

        s1[p][q]= -sin(theta);
        s1[q][p]= sin(theta);

        s1t[p][q]= s1[q][p];
        s1t[q][p]= s1[p][q];

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                temp[i][j]= 0;
                for(p=0; p<n; p++)  temp[i][j]+= s1t[i][p]*d[p][j];
            }
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                d[i][j]= 0;
                for(p=0; p<n; p++)  d[i][j]+= temp[i][p]*s1[p][j];
            }
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                temp[i][j]= 0;
                for(p=0; p<n; p++)  temp[i][j]+= s[i][p]*s1[p][j];
            }
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)  s[i][j]= temp[i][j];
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i!=j)
                    if(fabs(d[i][j]) > zero) flag= 1;
            }
        }
    }
    while(flag==1);

    printf("The eigenvalues are:\n\n");
    double val=0;
    for(i=0; i<n; i++){
        int dup=0.00;
        val=d[i][i];
        printf("%8.4lf ",val);
            for(tr=0;tr<indx;tr++){
                if(abs(eigen[tr]-val)<1e-4){
                    dup=1;
                    break;
                }
            }

            if(dup==0){
                eigen[indx]=val;
                indx++;
            }

    }

    printf("\n\nThe corresponding eigenvectors are:\n\n");

    int r=0,c=0;

    for(j=0; j<n; j++)
    {
        printf("(");
        for(i=0; i<n-1; i++){
             printf("% 8.4lf,",s[i][j]);
             svd[r][c]=s[i][j];
             c++;
        }
        printf("%8.4lf )^T\n",s[n-1][j]);
        svd[r][c]=s[n-1][j];
        r++;
        c=0;

    }
    printf("\n");

}

int main() {

  int m,n, i, j, k, p, q, flag;

  printf("Enter the order of the matrix: ");
  scanf("%d %d",&m,&n);

  printf("Enter the elements row wise:\n");

  for(i=0; i<m; i++) {
    for(j=0; j<n; j++){
       scanf ("%lf", &input[i][j]);
    }
  }

  printf("\nThe given matrix 'M' is:\n");
  printf("-----------------------------------------\n");

  for(i=0; i<m; i++) {
    for(j=0; j<n; j++){
         printf ("%8.4f ", input[i][j]);
    }
    printf ("\n");
  }

  printf ("\n");

   for(i=0; i<n; i++) {
    for(j=0; j<m; j++){
       trans[i][j]=input[j][i];
    }
  }

  printf("Transpose matrix of given matrix is (M^T):\n");
  printf("------------------------------------------------\n");

  for(i=0; i<n; i++) {
    for(j=0; j<m; j++){
         printf ("%8.4f ", trans[i][j]);
    }
    printf ("\n");
  }
  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  printf("\n\t\tCalculating U:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  printf("\nMultiplication of (M * M^T):\n");
  printf("----------------------------------------------\n");

  multiplication(input,trans,m,n);

  for(i=0; i<m; i++) {
    for(j=0; j<m; j++){
         printf ("%8.4f ",a[i][j]);
    }
    printf ("\n");
  }

  printf("\n");

  jacobi(a,m);

  printf("\n 'U' matrix is:\n");
  printf("---------------------------\n");

  for(i=0;i<m;i++){
    for(j=0;j<m;j++){
        printf("%8.4f ",svd[j][i]);
    }
    printf("\n");
  }
  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  printf("\n\t\tCalculating V:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  printf("\nMultiplication of (M^T * M):\n");
  printf("----------------------------------------------\n");

  multiplication(trans,input,n,m);

  for(i=0; i<n; i++) {
    for(j=0; j<n; j++){
         printf ("%8.4f ",a[i][j]);
    }
    printf ("\n");
  }

  printf("\n");

  jacobi(a,n);

  printf("\n 'V' matrix is:\n");
  printf("---------------------------\n");

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        printf("%8.4f ",svd[j][i]);
    }
    printf("\n");
  }

  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  printf("\n\t\tCalculating D:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  for(i=0;i<indx;i++){
    for(j=0;j<indx;j++){
        if(eigen[i]>eigen[j]){
            double tem=eigen[j];
            eigen[j]=eigen[i];
            eigen[i]=tem;
        }
    }
  }
  printf("\nEigenvalues are (According to Descending order):\n");
  printf("---------------------------------------------------\n");

  for(i=0;i<indx;i++) {
        printf("%8.4f ",eigen[i]);
  }
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
        if(i==j){
            a[i][j]=sqrt(eigen[i]);
        }
        else
            a[i][j]=0;
    }
  }
  printf("\n\n'D' matrix is:\n");
  printf("---------------------------\n");

  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
        printf("%8.4f ",a[i][j]);
    }
    printf("\n");
  }


}

/*
3 2
1 1
0 1
-1 1
*/
