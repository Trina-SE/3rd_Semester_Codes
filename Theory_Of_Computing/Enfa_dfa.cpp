#include <bits/stdc++.h>
using namespace std;

map<int,string>closure;
map<char,int>charint;
map<int,string>intstring;
char enfa[1000][100][10000];

void NFA_table_Print(int states,char alpha[],int transition){

  cout<<"************E-NFA table************"<<endl;
    cout<<"------------------------------------------------------\n";
    cout<<"State\t  0\t 1\te\n";
    cout<<"------------------------------------------------------\n";
    for(int i=0; i<states; i++){
        cout<<alpha[i]<<"\t";
        for(int j=0; j<transition; j++){
            int r=0;
            for(int k=0; k<states; k++){
                if(enfa[i][j][k]!='0')
                    cout<<enfa[i][j][k];
                else r++;
            }
            if(r==states) cout<<"null";
            cout<<"\t";
        }
        cout<<"\n";
        cout<<"------------------------------------------------------\n";
    }




}

void Eclosure(int states,int transition){

    for(int i=0; i<states; i++){
        closure[i]=intstring[i];
        for(int j=0; j<states; j++){
            if(enfa[i][transition-1][j]!='0'){
                  if(closure[i]!=to_string(enfa[i][transition-1][j])){
                           closure[i]+=enfa[i][transition-1][j];
                  }
            }
        }
    }

     for(int i=0; i<states; i++){
       for(int j=1; j<closure[i].length(); j++){
         if(closure[charint[closure[i][j]]].length()>1){
        for(int k=1; k<closure[charint[closure[i][j]]].length(); k++){
            if(closure[i].find(closure[charint[closure[i][j]]][k])==-1){
                closure[i]+=closure[charint[closure[i][j]]][k];
            }
        }
            }
        }

    }
       cout<<"\n";
       cout<<" E-Closure"<<endl;
       cout<<"------------------------------------------------------\n";

    for(int i=0; i<states; i++)
          cout<<"Epsilon Closure of "<<intstring[i]<<" : "<<closure[i]<<endl;



}

int main(){

    freopen("enfa.txt","r",stdin);
     int states,transition;
     cin>>states>>transition;
    int power=pow(2,states);//highest

       char ch;
       char alpha[states];

    for(int i=0; i<states; i++){
        cin>>ch;
        alpha[i]=ch;
    }
    for(int i=0;i<states;i++){
        intstring[i]=alpha[i];
        charint[alpha[i]]=i;
    }

    for(int i=0; i<states; i++){
        for(int j=0; j<transition; j++){
            for(int k=0; k<states; k++)
                cin>>enfa[i][j][k];
        }
    }

    NFA_table_Print(states,alpha,transition);

    Eclosure(states,transition);

//DFA table

    map<string,int>newstates;

    newstates[closure[0]]=1;

    vector<char>eachstate;
    int start=0,finish=1;

    map<int,map<int,string>>newstatematric;
    string newstates_array[power];
    newstates_array[0]=closure[0];

  for(int t=0;start<finish;t++){
    for(int x=0; x<transition-1; x++){
     for(int i=0; i<newstates_array[start].length(); i++){
      if(enfa[charint[newstates_array[start][i]]][x][0]!='0'){
        for(int j=0; j<states; j++){
            if(enfa[charint[newstates_array[start][i]]][x][j]!='0')
                eachstate.push_back(enfa[charint[newstates_array[start][i]]][x][j]);
            else
                break;
            }
        }

    }
    for(int l=0; l<eachstate.size(); l++){
        for(int k=0; k<closure[charint[eachstate[l]]].length(); k++)
                    if(newstatematric[start][x].find(closure[charint[eachstate[l]]][k])==-1)
                        newstatematric[start][x]+=closure[charint[eachstate[l]]][k];
     }
    eachstate.clear();
        if(newstates[newstatematric[start][x]]!=1){
                newstates_array[finish]=newstatematric[start][x];
                finish++;
            }

            newstates[newstatematric[start][x]]=1;
    }
        start++;
    }
    cout<<"\n";
    cout<<"        DFA table"<<endl;
    cout<<"------------------------------------------------------\n";
    cout<<"State\t  0\t 1\n";
    cout<<"------------------------------------------------------\n";

    for(int i=0; i<newstates.size(); i++){
        cout<<newstates_array[i]<<"\t  ";
        for(int j=0; j<transition-1; j++)
            cout<<newstatematric[i][j]<<"\t";
        cout<<"\n";
        cout<<"------------------------------------------------------\n";
    }

}

