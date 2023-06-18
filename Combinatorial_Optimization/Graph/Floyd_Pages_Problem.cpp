#include<bits/stdc++.h>
using namespace std;


int mat[102][102];
int update[102][102];

void floyd()
{

    for(int i=1; i<=101; i++)
    {
        for(int j=1; j<=101; j++)
        {
            update[i][j]=mat[i][j];
        }
    }
    for(int i=1; i<=101; i++)
    {
        for(int j=1; j<=101; j++)
        {
            for(int k=1; k<=101; k++)
            {
                if(update[j][i]+update[i][k]< update[j][k])
                {
                    if((update[j][i]!=INT_MAX) && (update[i][k]!=INT_MAX))
                        update[j][k]=update[j][i]+update[i][k];
                }
            }
        }
    }


}

int main()
{

    int cas=0;

    while(1)
    {

        int a,b;
        cin>>a>>b;
        if(a==0 && b==0) break;

        for(int i=1; i<=101; i++)
        {
            for(int j=1; j<=101; j++)
            {
                if(i==j) mat[i][j]=0;
                else
                    mat[i][j]=INT_MAX;
            }
        }

        while(1)
        {
            mat[a][b]=1;
            cin>>a>>b;
            if(a==0 && b==0) break;
        }

        /*  cout<<"\nGiven path:\n";
          cout<<"------------------------------------------------\n";
          for(int i=1;i<=4;i++){
             for(int j=1;j<=4;j++){
                 if(mat[i][j]==INT_MAX) cout<<"INF"<<" ";
                 else
                   cout<<mat[i][j]<<" ";
             }
             cout<<"\n";
          }*/

        floyd();

        /*  cout<<"\nShortest Path:\n";
          cout<<"------------------------------------------------\n";

          for(int i=1;i<=4;i++){
             for(int j=1;j<=4;j++){
                 if(update[i][j]==INT_MAX) cout<<"INF"<<" ";
                 else
                   cout<<update[i][j]<<" ";
             }
             cout<<"\n";
          }*/
        cas++;
        cout<<"\n";
        cout<<"Case "<<cas<<":average length between pages = ";
        float sum=0,c=0;
        float res=0.0;
        for(int i=1; i<=101; i++)
        {
            for(int j=1; j<=101; j++)
            {
                if(update[i][j]!=INT_MAX && update[i][j]!=0)
                {
                    sum+=update[i][j];
                    c++;
                }
            }
        }
        // cout<<sum<<"\t"<<c<<"\n";
        res=sum/c;
        printf("%.3f clicks\n\n",res);

    }

}

/*
1 2 2 4 1 3 3 1 4 3 0 0
1 2 1 4 4 2 2 7 7 1 0 0
0 0
*/

