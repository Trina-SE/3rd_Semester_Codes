#include<bits/stdc++.h>
using namespace std;

struct id{

  string name,password,gender;
  int age;

};

int index=-1;
id info[5];

void reg(){

 while(1){

    string n,p,g;
    int a,l=0;

  cout<<"Name?\n";
  cin>>n;
  cout<<"Password?\n";
  cin>>p;
  cout<<"Gender\n";
  cin>>g;
  cout<<"Age?\n";
  cin>>a;

       for(int j=0;j<index;j++){
        if(n==info[j].name){
            cout<<"This User ID has already been existed!\nPlease,Give unique User Name\n";
            l=1;
            break;
        }

      }
      if(l==0){
            info[index].name=n;
            info[index].password=p;
            info[index].gender=g;
            info[index].age=a;
            break;
      }

  }

}

void login(){

 int flag=0,wrong=0;

 for(int i=0;i<5;i++){
    string n,p;
    cout<<"User Name?\n";
    cin>>n;
    cout<<"Password?\n";
    cin>>p;

      for(int j=0;j<=index;j++){
        if(n==info[j].name && p==info[j].password){
            cout<<"WELCOME To Facebook\n";
            flag=1;
            break;

        }
      }
      if(flag==1) break;
      else {
        wrong++;
        if(wrong!=5)
             cout<<"Try Again!!\n";
      }

 }
   if(wrong==5) cout<<"Your Account is BLOCKED\n";
}

int main(){

 while(1){

   cout<<"What do you want?\nClick 1 for Registration\nClick 2 for Login\n";
   int click;
   cin>>click;
   if(click==1){
    index++;
    reg();
   }
   else if(click==2){
    login();
   }
   else{
    cout<<"Invalid choose!\n";
    }

  }

  return 0;

}
