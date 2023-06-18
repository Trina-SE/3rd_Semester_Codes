#include <stdio.h>
#include <math.h>

#define N 11

double M[N][4];
double T[4][N];
double multi_TM[4][4];
double col[N][1];
double multi_Tcol[4][4];
double augmented[4][5];

int main(){

  double x[N]= { 0.0,0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0 };
  double f[N]= { 1.0,1.04,1.16,1.36,1.64,2.0,2.44,2.96,3.56,4.24,5.0 };

  //f(x)= c0 + c1x + c2x^2 + c3x^3

  for(int i=0;i<N;i++){
    for(int j=0;j<4;j++){
        M[i][j]= pow(x[i],j);
    }
  }

  printf("Matrix M (11 x 4) is:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("   x    |     c0         c1          c2          c3    \n");

  for(int i=0;i<N;i++){
        printf("%lf|",x[i]);
    for(int j=0;j<4;j++){
        printf(" %lf   ",M[i][j]);
    }
    printf("\n");
  }

  printf("\nColumn Matrix col (11 x 1) is:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  for(int i=0;i<N;i++){
    for(int j=0;j<1;j++){
        col[i][j]= f[i];
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<1;j++){
        printf(" %lf ",col[i][j]);
    }
    printf("\n");
  }

  printf("\nTranspose matrix of M (4 x 11) is:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  for(int i=0;i<4;i++){
    for(int j=0;j<N;j++){
        T[i][j]= M[j][i];
    }
  }

  for(int i=0;i<4;i++){
    for(int j=0;j<N;j++){
        printf(" %lf ",T[i][j]);
    }
    printf("\n");
  }

  printf("\nMultiplication_(T * M) is:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
        for(int k=0; k<N; k++){
            multi_TM[i][j]+=(T[i][k]*M[k][j]);
        }
    }
  }

  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        printf(" %lf ",multi_TM[i][j]);
    }
    printf("\n");
  }

  printf("\nMultiplication_(T * col) is:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  for(int i=0; i<4; i++){
    for(int j=0; j<1; j++){
        for(int k=0; k<N; k++){
            multi_Tcol[i][j]+=(T[i][k]*col[k][j]);
        }
    }
  }

  for(int i=0;i<4;i++){
    for(int j=0;j<1;j++){
        printf(" %lf ",multi_Tcol[i][j]);
    }
    printf("\n");
  }

  printf("\nAugmented Matrix (multi_TM | multi_Tcol):\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  for(int i=0;i<4;i++){
    for(int j=0;j<5;j++){
        if(j==4)
           augmented[i][j]=multi_Tcol[i][0];
        else
           augmented[i][j]=multi_TM[i][j];
    }
  }

  for(int i=0;i<4;i++){
    for(int j=0;j<5;j++){
        if(j==3)
           printf(" %lf  |",augmented[i][j]);
        else
           printf(" %lf ",augmented[i][j]);
    }
    printf("\n");
  }

  double d,op;

  for (int i=0; i<4; i++) {
    d = augmented[i][i];
    for (int j=i; j<5; j++) {
        augmented[i][j] = (augmented[i][j])/d;
    }
    for (int k=0; k<4; k++) {
      if (k != i) {
         op = (augmented[k][i]) * (-1);
        for (int j=i; j<5; j++) {
          augmented[k][j] = augmented[k][j] + op*augmented[i][j];
        }
      }
    }
  }

  printf("\nDiagonal Matrix:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  for(int i=0;i<4;i++){
    for(int j=0;j<5;j++){
        if(j==3)
           printf(" %lf  |",augmented[i][j]);
        else
           printf(" %lf ",augmented[i][j]);
    }
    printf("\n");
  }

  printf("\nThe Co-efficients are:\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  for(int i=0;i<4;i++){
     printf("Co-efficient of X^%d = %lf\n",i,augmented[i][4]);
  }

}

