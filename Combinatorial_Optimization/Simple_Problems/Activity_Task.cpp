#include<bits/stdc++.h>
using namespace std;

struct activities{

 string activity;
 int start,ending;

};

bool cmp(activities ac1,activities ac2)

{

  return ac1.ending<ac2.ending;

}

int main()
{

   int n,ans=0,free=0;
   cin>>n;
   activities act[n];
   for(int i=0;i<n;i++){
        string s;
        char charc;
        cin>>charc;
        getline(cin,s);
        s=charc+s;
        act[i].activity=s;
        cin>>act[i].start>>act[i].ending;
   }
   sort(act,act+n,cmp);

   vector<string>v;

   for(int i=0;i<n;i++){
    if(free<=act[i].start){
        ans++;
        v.push_back(act[i].activity);
        free=act[i].ending;
    }
   }

   cout<<"Maximum Number of Activities:"<<ans<<"\n"<<"Description:\n";

   for(int i=0;i<ans;i++){
    cout<<i+1<<"."<<v[i]<<"\n";
   }


}

/*
Input:
3
prepare bsse tabulation sheet
2 9
print msse flyer
3 6
check bsse scripts
6 8
*/



