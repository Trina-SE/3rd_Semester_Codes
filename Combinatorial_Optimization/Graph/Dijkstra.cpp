#include<bits/stdc++.h>
using namespace std;

int mat[100][100];

int main(){

    int ver,edg;
    cin>>ver>>edg;
    int source;
    cin>>source;

   for(int i=0;i<ver;i++){
    for(int j=0;j<ver;j++){
        mat[i][j]=INT_MAX;
    }
   }
   for(int i=0;i<edg;i++){
    int u,v,w;
    cin>>u>>v>>w;
    mat[u][v]=w;
    mat[v][u]=w;

   }
   mat[source][source]=0;

   selected[v]

}

/*
8 14
0
0 1 4
0 4 8
1 2 8
1 4 11
2 3 7
2 8 2
2 6 4
4 8 7
4 5 1
5 8 6
5 6 2
6 7 10
7 3 9
3 6 14
*/
