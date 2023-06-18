#include<bits/stdc++.h>
using namespace std;


int mat[102][102];
int update[102][102];

void floyd(int c)
{

    for(int i=1; i<=c; i++)
    {
        for(int j=1; j<=c; j++)
        {
            update[i][j]=mat[i][j];
        }
    }
    for(int i=1; i<=c; i++)
    {
        for(int j=1; j<=c; j++)
        {
            for(int k=1; k<=c; k++)
            {
                        update[k][j]=update[j][k]=min(update[j][k],max(update[j][i],update[i][k]));
            }
        }
    }


}

int main()
{

    int cas=0;

    while(1)
    {

        int c,s,q;
        cin>>c>>s>>q;
        if(c==0 && s==0 && q==0) break;

        for(int i=1; i<=c; i++)
        {
            for(int j=1; j<=c; j++)
            {
                if(i==j) mat[i][j]=0;
                else
                    mat[j][i]=mat[i][j]=INT_MAX;
            }
        }

        int c1,c2,cost;
        cas++;

        for(int i=1; i<=s; i++)
        {
            cin>>c1>>c2>>cost;
            mat[c1][c2]=cost;
            mat[c2][c1]=cost;
        }
        /*
             cout<<"\nGiven path:\n";
             cout<<"------------------------------------------------\n";
             for(int i=1;i<=c;i++){
                for(int j=1;j<=c;j++){
                    if(mat[i][j]==INT_MAX) cout<<"INF"<<" ";
                    else
                      cout<<mat[i][j]<<" ";
                }
                cout<<"\n";
             }*/

        floyd(c);

        /*  cout<<"\nShortest Path:\n";
          cout<<"------------------------------------------------\n";

          for(int i=1;i<=c;i++){
             for(int j=1;j<=c;j++){
                 if(update[i][j]==INT_MAX) cout<<"INF"<<" ";
                 else
                   cout<<update[i][j]<<" ";
             }
             cout<<"\n";
          }*/
        cout<<"\n";
        cout<<"Case#"<<cas<<"\n";
        for(int i=1; i<=q; i++)
        {
            int a,b;
            cin>>a>>b;
            if(update[a][b]!=INT_MAX)
                cout<<update[a][b]<<"\n";
            else
                cout<<"no path\n";

        }

        cout<<"\n";

    }

}

/*
7 9 3
1 2 50
1 3 60
2 4 120
2 5 90
3 6 50
4 6 80
4 7 70
5 7 40
6 7 140
1 7
2 6
6 2
7 6 3
1 2 50
1 3 60
2 4 120
3 6 50
4 6 80
5 7 40
7 5
1 7
2 4
0 0 0
*/
