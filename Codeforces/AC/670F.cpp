#include<bits/stdc++.h>
using namespace std;

int cnt[12];

int getdig(string &s){
    if(s.size()<=10)return s.size()-1;
    if(s.size()<=101)return s.size()-2;
    if(s.size()<=1002)return s.size()-3;
    if(s.size()<=10003)return s.size()-4;
    if(s.size()<=100004)return s.size()-5;
    if(s.size()<=1000005)return s.size()-6;
    exit(7122);
}
void subdig(int dig){
    while(dig){
        --cnt[dig%10];
        dig/=10;
    }
}
void substr(const string &t){
    for(char c:t)--cnt[c-'0'];
}

string tfirst;

void firstnot0(string &ans,const string &t){
    if(t[0]!='0'){
        tfirst=t;
        for(int i=0;i<=9;++i)for(int _=0;_<cnt[i];++_)tfirst+=(char)(i+'0');
    }
    if(t[0]=='0')for(int i=1;i<=9;++i){
        if(cnt[i]){
            --cnt[i];
            ans+=(char)('0'+i);
            return;
        }
    }
    bool tallsame=1,bigger=1; for(int i=0;i<t.size()-1;++i)if(t[i]!=t[i+1]){tallsame=0,bigger=t[i+1]>t[i]; break;}
    for(int i=1;i<=9;++i){
        if(cnt[i]){
            --cnt[i];
            ans+=(char)('0'+i);
            break;
        }
    }
}
void compare(string &ans,const string &t){
    if(ans.empty())return;
    bool tallsame=1,bigger=1,puted=0; for(int i=0;i<t.size()-1;++i)if(t[i]!=t[i+1]){tallsame=0,bigger=t[i+1]>t[i]; break;}
    for(int i=0;i<=9;++i){
        if(i+'0'==t[0] && !puted && (!bigger || tallsame)){
            ans+=t;
            puted=1;
        }
        while(cnt[i]--){
            ans+=(char)(i+'0');
        }
        if(i+'0'==t[0] && !puted && (bigger)){
            ans+=t;
            puted=1;
        }
    }
}

int main(){
    string s,t; cin>>s>>t;
    // if(s.size()>20)cout<<t<<endl;
    for(char c:s)++cnt[c-'0'];
    int dig=getdig(s);
    subdig(dig);
    substr(t);
    string ans;
    firstnot0(ans,t);
    compare(ans,t);
    if(tfirst.empty() && ans.empty())cout<<0<<endl;
    else if((tfirst.size() && tfirst<ans) || ans.empty())cout<<tfirst<<endl;
    else cout<<ans<<endl;
}
