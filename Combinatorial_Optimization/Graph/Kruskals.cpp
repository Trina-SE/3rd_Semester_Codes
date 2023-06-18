//Minimum Spanning Tree

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,pair<int,int>>>edges;
int parent[100],sz[100];

void make(int v){

   parent[v]=v;
   sz[v]=1;

}

int find_parent(int v){

    if(parent[v]==v) return v;

    return parent[v]=find_parent(parent[v]);

}

void Union(int u, int v){

  u=find_parent(u);
  v=find_parent(v);

   if(u!=v){
    if(sz[u]<sz[v]){
        swap(u,v);
    }
    parent[v]=u;
    sz[u]+=sz[v];
   }

}

int main(){

   int ver,edg,w;
    cin>>ver>>edg;
    char u,v;

    for(int i=0;i<edg;i++){
        cin>>u>>v>>w;
        edges.push_back({w,{u-'A',v-'A'}});

    }
    sort(edges.begin(),edges.end());

    for(int i=0;i<ver;i++){
        make(i);
    }
    int cost=0;
    cout<<"From--> To : Weight\n";

    for(int i=0;i<edges.size();i++){

        int wt=edges[i].first;
        int a=edges[i].second.first;
        int b=edges[i].second.second;

         if(find_parent(a)==find_parent(b)) continue;

         Union(a,b);
         cost+=wt;
         cout<<" "<< (char)(a+'A') <<"  -->  "<<(char)(b+'A')<<"  : "<<wt<<"\n";
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

output:17
*/
