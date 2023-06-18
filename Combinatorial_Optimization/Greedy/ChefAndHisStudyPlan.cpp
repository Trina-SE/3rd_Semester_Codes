#include<bits/stdc++.h>
using namespace std;

int main(){

   int n,q;
   cin>>n>>q;
   vector<pair<int,int>>vn,vq;

    for(int i=0;i<n;i++){
        int s,e;
        cin>>s>>e;
        vn.push_back(make_pair(e,s));

    }
    sort(vn.begin(),vn.end());

     for(int i=0;i<vn.size();i++){

        int temp=vn[i].first;
        vn[i].first=vn[i].second;
        vn[i].second=temp;

    }

  /*  for(int i=0;i<vn.size();i++){
        cout<<vn[i].first<<" "<<vn[i].second<<"\n";
    }*/

   for(int i=0;i<q;i++){
        int s1,e1;
        cin>>s1>>e1;
        vq.push_back(make_pair(s1,e1));

    }
    for(int i=0;i<q;i++){
        int free=0,c=0;
        for(int j=0;i<n;j++){
            if(vq[i].first==vn[j].first){
                if(free<=vn[j].first){
                    c++;
                    free=vn[j].second;
                }
            }
        }
        cout<<c<<"\n";
    }

}

/*
3 3
1 3
5 6
2 4
1 6
1 3
2 3
*/



