#include<iostream>
#include<string>
#include<assert.h>
#define len length()
using namespace std;

string a,b;

bool small(string a,string b){
    // cout<<"in small "<<a<<" "<<b<<endl;
    if(a.len!=b.len)return a.len<b.len;
    for(int i=0;i<(int)a.len;++i)if(a[i]!=b[i])return a[i]<b[i];
    return 0;
}

string times(string a,int t){
    // cout<<a<<" "<<t<<endl;
    for(auto &c:a){
        c=(c-'0')*t;
    }
    // for(auto c:a)cout<<c+'0'<<" ";cout<<endl;
    for(auto i=a.len-1;i>0;--i){
        while(a[i]>9){a[i]-=10;++a[i-1];}
    }
    while(a[0]>9){
        int of=(a[0])/10;
        a[0]=(a[0])%10;
        a.insert(0,1,of);
    }
    for(auto &c:a)c+='0';
    return a;
}

void mns(string &a,string b){
    cout<<a<<"-"<<b<<endl;
    int sam=0;
    for(;sam<(int)b.len;++sam){
        if(a[sam]!=b[sam])break;
    }
    if(b[0]=='0')sam=1;
    // cout<<sam<<" ";
    for(int i=0;i<(int)b.len;++i){
        a[i]-=b[i]-'0';
    }
    for(auto i=b.len-1;i>0;--i){
        while(a[i]<'0'){a[i]+=10;--a[i-1];}
    }
    // while(sam--){
    //     a.erase(0,1);
    // }
}

string div(string a,string b){
    if(a==b)return "1";
    if(small(a,b))return "0";
    string ans="";
    while(!small(a,b)){
        cout<<"a="<<a<<" b="<<b<<" , nowans="<<ans<<endl;
        int digs=(int)b.len;
        if(a[0]=='0'){
            ++digs;
            a.erase(0,1);
            continue;
        }
        string t;
        while(1){
            t=a.substr(0,digs);
            cout<<t<<" "<<b<<" "<<small(t,b)<<endl;
            if(!small(t,b))break;
            ++digs;
            ans=ans+'0';
        }
        string tt;int tm=0;
        while(1){
            // if(tm>9)return "";
            tt=times(b,tm);
            // cout<<t<<"-"<<tt<<endl;
            if(small(t,tt)){
                --tm;
                tt=times(b,tm);
                break;
            }
            ++tm;
        }
        if(tt.len<t.len)tt="0"+tt;
        mns(a,tt);
        // cout<<a<<" "<<b<<" "<<t<<" "<<tt<<endl;
        ans=ans+(char)('0'+tm);
        // --digs;
    }
    return ans;
}

int main(){
    // cout<<times("9567424173",3)<<endl;
    cin>>a>>b;
    // a="915464274341541",b="9567424173";
    if(b=="0")assert(1==0);
    if(b=="1")cout<<a<<endl;
    else cout<<div(a,b)<<endl;
}
