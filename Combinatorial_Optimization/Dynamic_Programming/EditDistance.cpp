#include<bits/stdc++.h>
using namespace std;

int dp[3000][3000],total;
char arrow[3000][3000];
int gl,cl;

void operation(string s,string t)
{     int i=gl-1,j=cl-1,cnt=0;
      string p=s;
        while(i>=0 && j>=0){
            if(s[i]==t[j]){
               i--;
               j--;
            }
            else{
                if(arrow[i][j]=='u'){
                    cnt++;
                    p.erase(p.begin()+i);
                    cout<<cnt<<"."<<"Delete "<<i<<"th "<<s[i]<<"->"<<p<<"\n";
                    i--;
                }
                else if(arrow[i][j]=='l'){
                    cnt++;
                    p.insert(p.begin()+j,t[j]);
                    cout<<cnt<<"."<<"Insert "<<j<<"th "<<t[j]<<"->"<<p<<"\n";
                    j--;
                }
                else if(arrow[i][j]=='d'){
                    cnt++;
                    p[i]=t[j];
                    cout<<cnt<<"."<<"Replace "<<i<<"th "<<s[i]<<" by "<<t[j]<<"->"<<p<<"\n";
                    i--;
                    j--;
                }
            }

        }

}

int main(){

   string given,convert;
   cin>>given>>convert;
   given="*"+given;
   convert="*"+convert;


//"given string" to "convert string"

   gl=given.size();
   cl=convert.size();

      for(int i=0;i<=cl;i++){
        dp[0][i]=i;
        arrow[0][i]='l';//l=left
      }
      for(int i=0;i<=gl;i++){
        dp[i][0]=i;
        arrow[i][0]='u';//u=upper
      }

 //make table

    for(int i=1;i<gl;i++){
        for(int j=1;j<cl;j++){
            if(given[i]==convert[j]){
                dp[i][j]=dp[i-1][j-1];
                arrow[i][j]='d';//d=diagonal
            }
            else{
                dp[i][j]=(min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])))+1;

                  if((dp[i-1][j-1]<=dp[i-1][j])) {
                      if((dp[i-1][j-1]<=dp[i][j-1])) arrow[i][j]='d';
                      else arrow[i][j]='l';
                  }
                  else{
                    if((dp[i-1][j]<=dp[i][j-1])) arrow[i][j]='u';
                    else arrow[i][j]='l';
                  }

            }
        }
    }

    total=dp[gl-1][cl-1];

  /*  for(int i=0;i<gl;i++){
        for(int j=0;j<cl;j++){
            cout<<dp[i][j]<<arrow[i][j]<<" ";
        }
        cout<<"\n";
    }*/
     cout<<"Minimum operations need to convert "<<given<<" to "<<convert<<" is:";
     cout<<dp[gl-1][cl-1]<<"\n";
     cout<<"Operations are:\n";
     operation(given,convert);

}

/*
Input:
heater
speak
output:
Minimum operations need to convert heater to speak is:5
Operations are:
----------
Input:
abcdef
azced
output:
Minimum operations need to convert heater to speak is:3
Operations are:
----------
*/
