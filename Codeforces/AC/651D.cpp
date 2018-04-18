#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int32_t main(){
    int n,a,b,t; cin>>n>>a>>b>>t;
    string s; cin>>s; for(char &c:s)c=(c=='w');
    if([&](){
        ll tt=a*(n-1);
        for(char c:s)if(c)tt+=b;
        tt+=n;
        return tt<=t;
    }())exit((cout<<n<<endl,0));
    auto meow=[&](){
        // for(int c:s)cout<<c; cout<<endl;
        int cnt_fan=s[0];
        for(int i=1;i<n;++i)if(s[i])++cnt_fan;
        int rt=0;
        int right_ext=0,more_t=0;
        for(int i=1;i<n;++i){
            if(i>1 && s[i-1])--cnt_fan;
            ll tt=(n-i)*a+cnt_fan*b+(n-i)+1;
            if(tt>t)continue;
            rt=max(rt,n-i+1);
            tt+=(n-i)*a;
            if(tt>t)continue;
            ll ttt=tt+more_t;
            if(ttt<=t)rt=max(rt,n-i+1+right_ext);
            while(ttt<=t){
                ++right_ext;
                more_t+=a+1;
                if(s[right_ext])more_t+=b;
                ttt=tt+more_t;
                if(ttt>t)break;
                rt=max(rt,n-i+1+right_ext);
            }
        }
        return rt;
    };
    cout<<max(max(meow(),[&](){
        reverse(s.begin()+1,s.end());
        ll rt=meow();
        reverse(s.begin()+1,s.end());
        return rt;
    }()),[&](){
        ll tt=s[0]?b:0;
        tt+=1;
        if(tt<=t)return 1ll;
        return 0ll;
    }())<<endl;
}
