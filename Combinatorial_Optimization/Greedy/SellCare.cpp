#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main(){

    int t;
    cin>>t;
     while(t--){
        int n;
        long long int profit=0;
        cin>>n;
        int car[n];
        for(int i=0;i<n;i++){
            cin>>car[i];
        }
        sort(car,car+n);

         int track=n-1;

        for(int i=0;i<n;i++){

            if((car[i]-track)>=0)
                 profit+=(car[i]-track);
                 profit%=mod;
               //  cout<<profit<<"\t";

            track--;
        }

        cout<<profit<<"\n";
     }

}
