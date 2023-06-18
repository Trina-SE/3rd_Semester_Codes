//Recursion

#include<bits/stdc++.h>
using namespace std;

int cuts[10000];
int dp[10000][10000];

int optimal(int left,int right,int cuts[]){

   if(left>right) return 0;
   if(dp[left][right]!=-1) return dp[left][right];
    int mi=INT_MAX,cost;

      for(int i=left;i<=right;i++){
        cost=cuts[right+1]-cuts[left-1]+optimal(left,i-1,cuts)+optimal(i+1,right,cuts);
        mi=min(mi,cost);
      }

      return dp[left][right]=mi;

}

int main(){

   int length;
   cin>>length;
   int cut;
   cin>>cut;//5
   int cuts[cut+2];
   cuts[0]=0;
     for(int i=1;i<=cut;i++){
        cin>>cuts[i];
     }
   cuts[cut+1]=length;
   memset(dp,-1,sizeof(dp));
   cout<<"The minimum cost of cutting the bread is "<<optimal(1,cut,cuts);



}



/*
Input:
100
3
25 50 75
output=200
10
3
2 4 7
output=20
7
4
1 3 4 5
output:16
*/
