#include<bits/stdc++.h>
using namespace std;

struct user
{

    string name;
    long long int acc;
    float currentBalance;

};

user u[100000];
int index=-1;
long long int no=2009871034;

void add()
{

    no++;
    cout<<"Name?\n";
    cin>>u[index].name;
    cout<<"Balance?\n";
    cin>>u[index].currentBalance;
    u[index].acc=no;

}

void Withdraw_money()
{
    int w=0;
    while(w<5)
    {

        long long int n,z=0;
        cout<<"Account number?\n";
        cin>>n;

        for(int k=0; k<=index; k++)
        {
            if((u[k].acc)==n)
            {       z=1;
                    float m;
                    cout<<"How much money you want to withdraw?\n";
                    cin>>m;

                    if(u[n].currentBalance<m)
                    {
                        cout<<"Sorry!You can't withdraw this amount of money!\nTry Again!";
                        break;
                    }
                    else
                    {
                        u[n].currentBalance-=m;
                        cout<<"Now current balance is:"<<u[n].currentBalance<<"\n";
                        break;
                    }

                }
        }
        if(z==1) break;
        else{
          cout<<"Invalid acc no!Try Again!!\n";
          w++;
         }
    }
    if(w==5) cout<<"Blocked\n";
}

void Deposit_money(){

 int w=0;
    while(w<5)
    {

        long long int n,z=0;
        cout<<"Account number?\n";
        cin>>n;

        for(int k=0; k<=index; k++)
        {
            if((u[k].acc)==n)
            {       z=1;
                    float m;
                    cout<<"How much money you want to deposit?\n";
                    cin>>m;
                        u[n].currentBalance+=m;
                        cout<<"Now current balance is:"<<u[n].currentBalance<<"\n";
                        break;

                }
        }
        if(z==1) break;
        else{
          cout<<"Invalid acc no!Try Again!!\n";
          w++;
         }
    }
    if(w==5) cout<<"Blocked\n";
}

void balance_check(){

   int w=0;
    while(w<5)
    {

        long long int n,z=0;
        cout<<"Account number?\n";
        cin>>n;

        for(int k=0; k<=index; k++)
        {
            if((u[k].acc)==n)
            {
                z=1;
               cout<<"Current balance is:"<<u[n].currentBalance<<"\n";
                        break;

                }
        }
        if(z==1) break;
        else{
          cout<<"Invalid acc no!Try Again!!\n";
          w++;
         }
    }
    if(w==5) cout<<"Blocked\n";


}

int main()
    {

        while(1)
        {

            cout<<"Select one?\n";
            cout<<"Click 0 for add account\n";
            cout<<"Click 1 for Withdraw money\nClick 2 for Deposit money\nClick 3 for Check Current Balance\n";
            int c;
            cin>>c;
            if(c==0)
            {
                index++;
                add();
            }
            else if(c==1)
            {
                Withdraw_money();
            }
            else if(c==2)
            {
                Deposit_money();
            }
            else if(c==3)
            {
                balance_check();
            }
        }
    }
