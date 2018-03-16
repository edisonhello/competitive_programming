#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; while(cin>>s){
        int ok=0;
        if(s.size()>=8u)++ok;
        bool sm=0,bg=0;
        bool alp=0,num=0,nt=0;
        for(char c:s){
            if(c>='a' && c<='z')sm=1,alp=1;
            else if(c>='A' && c<='Z')bg=1,alp=1;
            else if(c>='0' && c<='9')num=1;
            else nt=1;
        }
        ok+=sm&&bg;
        ok+=alp&&(num||nt);
        cout<<"This password is ";
        if(ok==0)cout<<"WEAK"<<endl;
        else if(ok==1)cout<<"ACCEPTABLE"<<endl;
        else if(ok==2)cout<<"GOOD"<<endl;
        else cout<<"STRONG"<<endl;
    }
}
