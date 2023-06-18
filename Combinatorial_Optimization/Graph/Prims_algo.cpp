//Minimum Spanning Tree

#include<bits/stdc++.h>
using namespace std;

int mat[100][100];

int main(){

    int ver,edg,w;
    cin>>ver>>edg;
    char u,v;

    for(int i=0;i<ver;i++){
        for(int j=0;j<ver;j++){
            mat[i][j]=INT_MAX;
        }
    }

    for(int i=0;i<edg;i++){
        cin>>u>>v>>w;
        mat[u-'A'][v-'A']=w;
        mat[v-'A'][u-'A']=w;
    }
    for(int i=0;i<ver;i++){
        for(int j=0;j<ver;j++){
            if(mat[i][j]==INT_MAX) cout<<"N ";
            else cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }

    int selected[ver];
    memset(selected,false,sizeof(selected));
    selected[0]=true;

    int it=0,cost=0;

    cout<<"From--> To : Weight\n";

    while(it<ver-1){

        int r=0,c=0,mi=INT_MAX;

         for(int i=0;i<ver;i++){
            if(selected[i]==true){
                for(int j=0;j<ver;j++){
                    if(selected[j]==false && mat[i][j]!=INT_MAX){
                        if(mi>mat[i][j]){
                            mi=mat[i][j];
                            r=i;
                            c=j;
                        }
                    }
                }
            }
         }
           selected[c]=true;
           it++;
           cost+=mi;
           cout<<" "<< (char)(r+'A') <<"  -->  "<<(char)(c+'A')<<"  : "<<mi<<"\n";

    }

    cout<<"Total cost (MST) = "<<cost<<"\n";


}


/*Input:
6 9
A B 7
A C 8
B D 6
B C 3
C D 4
C E 3
D E 2
D F 5
E F 2
output: 17
*/
