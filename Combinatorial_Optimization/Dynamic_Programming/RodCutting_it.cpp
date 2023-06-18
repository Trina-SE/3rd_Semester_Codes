#include<bits/stdc++.h>
using namespace std;

int rod(int n,int price[],int length[])
{
    int dp[n+1];
    dp[0] = 0;
    int i,j;
    for(j=1;j<=n;j++)
    {
         int max_val = INT_MIN;
        for(i=1;i<=j;i++)
        {

             max_val   = max(max_val,(price[i]+dp[j-i]));
            dp[j]= max_val;
        }
    }

    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    int length[n], price[n];
    length[0]=price[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>length[i]>>price[i];
    }
   cout<< rod(n,price,length);
}
/*
7
1 1
2 5
3 8
4 9
5 10
6 12
7 17
*/

