#include<bits/stdc++.h>
using namespace std;

int main(){

  int n,ml,mb;
  long long int ans1=0,ans2=0,ans=0;
  cin>>ml>>mb>>n;

  for(int i=0;i<n;i++){

    int l,b;
    cin>>l>>b;

    ans1=(l/ml)*(b/mb);
    ans2=(l/mb)*(b/ml);

    ans+=max(ans1,ans2);
  }

  cout<<ans<<"\n";


}

/*
4 4 1 4 12
output:3
10 10 1 2 1000
output:0
*/
