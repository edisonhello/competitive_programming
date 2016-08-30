#include<bits/stdc++.h>
using namespace std;

map<string,int> m;
int cnt;

void spawn(string s,int mx){
    if((int)s.length()>=mx){
        m[s]=cnt;
        cnt++;
        return;
    }
    if(!s.length()){
        for(int i='a';i<='z';i++){
            spawn(s+(char)i,mx);
        }
        return;
    }
    for(int i=s[s.length()-1]+1;i<='z';i++){
        spawn(s+(char)i,mx);
    }
}

void init(){
	cnt=1;
    for(int i=1;i<=5;i++){
        spawn("",i);
    }
}

int main(){
    init();
    string s;
    while(cin>>s){
        int no=0;
        for(int i=1;i<(int)s.length();i++){
            if(s[i]<=s[i-1]){
                cout<<0<<endl;
                no=1;
                break;
            }
        }
        if(!no){
            cout<<m[s]<<endl;
        }
    }
}
