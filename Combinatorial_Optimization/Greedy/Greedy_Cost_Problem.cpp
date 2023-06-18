#include<bits/stdc++.h>
using namespace std;

int city[26][26],total_cost;

int row_min(int row)
{

    int mini=INT_MAX,in;
    for(int i=0; i<26; i++)
    {
        if(city[row][i]<=mini){
            mini=city[row][i];
            in=i;
        }
    }
    total_cost+=mini;
    if(mini==INT_MAX){
        return -1;
    }
    city[row][in]=INT_MAX;
    city[in][row]=INT_MAX;
    return in;

}

int main()
{

    char f,t;
    int cost,a,b;
    cout<<"Input Cities(A-Z) with costs:Format-->>FROM_TO_COST\n";
    cout<<"Click 'e' to stop taking input!!\n";

    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            city[i][j]=INT_MAX;
        }
    }

    for(int i=0;; i++)
    {
        cin>>f;
        if(f=='e') break;
        else
        {
            cin>>t>>cost;
            a=f-'A';
            b=t-'A';
            city[a][b]=cost;
            city[b][a]=cost;

        }
    }

 /*      for(int i=0;i<26;i++){
           for(int j=0;j<26;j++){
               cout<<city[i][j]<<"\t";
           }
           cout<<"\n";
       }
*/
    cout<<"Input Starting Location:\n";
    cin>>f;
    a=f-'A';
    char ch=(char)(a+'A');
    cout<<"Input Ending Location:\n";
    cin>>t;
    b=t-'A';
    cout<<"\nBest route to reach the destination city using greedy algorithm:\n\n";
    cout<<ch;

    int m,term=0;

    while(a!=b){

        cout<<"-->>";
        m=row_min(a);
        if(m==-1){
            cout<<"We Can't reach the destination through GREEDY ALGORITHM\n";
            break;
        }
        a=m;
        char ch=(char)(m+'A');
        cout<<ch;
    }
    if(m!=-1)
       cout<<"\n\n"<<"Total cost="<<total_cost<<"\n";

}

/*
Input:
A B 15
B C 11
C D 27
D E 7
E F 19
F G 13
G A 25
A H 10
H D 20
E H 2
e
A
D
*/
