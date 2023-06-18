#include<bits/stdc++.h>
using namespace std;

string s,t,n;
int sl,tl;
int dp[3005][3005];
char arrow[3005][3005];

string lcs(){

  int i=sl-1,j=tl-1;
         while(i>=1 && j>=1){
             if(s[i]==t[j]){
                n.push_back(s[i]);
                i--;
                j--;
            }
            else{
                if(arrow[i][j]=='l'){
                    j--;
                }
                else if(arrow[i][j]=='u'){
                    i--;
                }
            }
         }

        reverse(n.begin(),n.end());
        return n;
}

int main(){

  cin>>s>>t;
  s="#"+s; //cout<<s<<"\n";
  t="#"+t; //cout<<t<<"\n";
  sl=s.size();  //cout<<sl<<"\n";
  tl=t.size();

  //make table
     for(int i=0;i<sl;i++){
        dp[0][i]=0;
        dp[i][0]=0;
        arrow[0][i]='0';
        arrow[i][0]='0';
     }
     for(int i=1;i<sl;i++){
        for(int j=1;j<tl;j++){
            if(s[i]==t[j]){
               dp[i][j]=dp[i-1][j-1]+1;
               arrow[i][j]='d'; //d=diagonal

        }
        else{
            if(dp[i][j-1]>dp[i-1][j]){
                dp[i][j]=dp[i][j-1];
                arrow[i][j]='l'; //l=left
            }
            else{
                dp[i][j]=dp[i-1][j];
                arrow[i][j]='u'; //u=upper
            }

        }
        }
     }
     cout<<"Length of LCS is:"<<dp[sl-1][tl-1]<<"\n";
     cout<<"LCS:"<<lcs()<<"\n";
}

/*
Input:
abcbdab
bdcaba
output:
bcba
Input:
abcdgh
abedfha
output:
abdh

*/


