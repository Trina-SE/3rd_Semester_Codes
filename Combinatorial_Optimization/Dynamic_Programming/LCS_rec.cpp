//Recursion

#include<bits/stdc++.h>
using namespace std;

string s,t;

int lcs(int i,int j){

  if(i<0 || j<0) return 0;

  int ans=lcs(i,j-1);
  ans=max(ans,lcs(i-1,j));
  ans=max(ans,lcs(i-1,j-1)+(s[i]==t[j]));

  return ans;


}

int main(){

   cin>>s>>t;

   cout<<lcs(s.size()-1,t.size()-1);

}
/*
Input:
abcbdab
bdcaba
output:
4
*/
