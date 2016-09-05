#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2

inline int rit(){
    int t=0,k=1;
    char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
};

// int n;
map<string,string> imd;
// string said[1000006];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cout<<(imdid["jizz"]=="")<<endl;
    int n;
    cin>>n;
    for(int ii=0;ii<n;ii++){
        int i;
        string cmd;
        cin>>cmd;
        if(cmd[1]=='N' || cmd[1]=='n'){ //　'New','name','said'
            string name = "";
            for(i=7;cmd[i]!='\'';i++)name+=cmd[i];
            string said = "";
            for(i+=3;cmd[i]!='\'';i++)said+=cmd[i];
            // cout<<name<<" "<<said<<endl;
            if(imd[name]!=""){
                cout<<"\'403 IMouTo Unhappy!\',\'"<<name<<"\'\n";
                continue;
            }
            imd[name]=said;
            cout<<"\'201 HaJiMeMaShiTe\',\'"<<name<<"\'\n";
        }
        else if(cmd[1]=='G' || cmd[1]=='g'){ // 'Get','name'
            string name = "";
            for(i=7;cmd[i]!='\'';i++)name+=cmd[i];
            if(imd[name]==""){
                cout<<"\'404 IMouTo Not Found!\',\'"<<name<<"\'\n";
                continue;
            }
            cout<<"\'200 ONiiChaN!\',\'"<<name<<"\',\'"<<imd[name]<<"\'\n";
        }
        else if(cmd[1]=='P' || cmd[1]=='p'){ // 'Post','name','said'
            string name = "";
            for(i=8;cmd[i]!='\'';i++)name+=cmd[i];
            string said = "";
            for(i+=3;cmd[i]!='\'';i++)said+=cmd[i];
            if(imd[name]==""){
                cout<<"\'404 IMouTo Not Found!\',\'"<<name<<"\'\n";
                continue;
            }
            imd[name] += '\\'+said;
            cout<<"\'200 ONiiChaN!\',\'"<<name<<"\'\n";
        }
        else if(cmd[1]=='D' || cmd[1]=='d'){ // 'Delete','name'
            string name = "";
            for(i=10;cmd[i]!='\'';i++)name+=cmd[i];
            if(imd[name]==""){
                cout<<"\'404 IMouTo Not Found!\',\'"<<name<<"\'\n";
                continue;
            }
            imd[name]="";
            cout<<"\'202 SaYouNaRa\',\'"<<name<<"\'\n";
        }
    }
}
