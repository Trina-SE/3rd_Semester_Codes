#include<bits/stdc++.h>
using namespace std;

int dp[3000][3000];

int rod(int a[],int b[],int indx,int l){

    if(l<=0) return 0;
    if(indx<0) return 0;
    if(dp[indx][l]!=-1) return dp[indx][l];
    int value=INT_MIN;
    value=max(value,rod(a,b,indx-1,l));
    if((l-a[indx])>=0)
    value=max(value,rod(a,b,indx,l-a[indx])+b[indx]);

    return dp[indx][l]=value;



}

int main()
{
    memset(dp,-1,sizeof(dp));
   int l;
   cin>>l;
   int length[l+1],price[l+1];
    for(int i=0;i<l;i++){
        cin>>length[i]>>price[i];
    }

    cout<<"Maximum cost:"<<rod(length,price,l-1,l)<<"\n";
}

/*Input:
7
1 1
2 5
3 8
4 9
5 10
6 12
7 17
output:
Maximum cost:18
*/
