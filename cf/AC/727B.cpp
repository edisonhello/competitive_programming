#include<iostream>
#include<string>
#include<sstream>

using namespace std;
int itg,dt;

void dec(string &s){
    // cout<<s<<endl;
    stringstream ss;
    int l=(int)s.length();
    if(s[l-3]=='.'){
        ss<<s.substr(l-2,2);
        int tdt;
        ss>>tdt;
        dt+=tdt;
        s.pop_back();s.pop_back();s.pop_back();
        l-=3;
    }
    int tit=0;
    for(char c:s){
        if(c=='.')continue;
        tit=tit*10+c-'0';
    }
    itg+=tit;
}
void print(){
    itg+=dt/100;dt%=100;
    stringstream ss;
    ss<<itg;
    string s;
    ss>>s;
    int l=(int)s.length();
    int cnt=3-l%3;
    for(char c:s){
        cout<<c;
        ++cnt;
        if(cnt%3==0 && !(dt==0 && cnt==(l/3+1)*3)){
            cout<<'.';
        }
    }
    if(dt==0){cout<<endl;return;}
    if(dt<10)cout<<0;
    cout<<dt<<endl;
}

string s;
int main(){
    cin>>s;
    string tmp="";
    for(char c:s){
        if((c>='0'&&c<='9')||c=='.'){
            tmp+=c;
        }
        else{
            if(tmp!="")dec(tmp);
            tmp="";
        }
    }
    if(tmp!="")dec(tmp);
    print();
}
