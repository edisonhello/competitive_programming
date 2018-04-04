#include<bits/stdc++.h>
using namespace std;

void no(){cout<<"NO"<<endl; exit(0);}
void yes(){cout<<"YES"<<endl; exit(0);}

int a[111],q[111],s[111],t[111];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    for(int i=0;i<n;++i)a[i]=i;
    for(int i=0;i<n;++i)cin>>q[i],--q[i];
    for(int i=0;i<n;++i)cin>>s[i],--s[i];
    bool ok=1;
    auto same=[&](){
        bool rt=1;
        for(int i=0;i<n;++i)if(a[i]!=s[i]){rt=0; break;}
        return rt;
    };
    auto go_nex=[&](){
        for(int i=0;i<n;++i)t[i]=a[q[i]];
        for(int i=0;i<n;++i)a[i]=t[i];
        return;
    };
    auto go_prv=[&](){
        for(int i=0;i<n;++i)t[q[i]]=a[i];
        for(int i=0;i<n;++i)a[i]=t[i];
        return;
    };
    auto reset=[&](){
        for(int i=0;i<n;++i)a[i]=i;
    };
    auto print=[&](){
        for(int i=0;i<n;++i)cout<<a[i]<<" "; cout<<endl;
    };
    if(same())no();
    for(int i=1;i<=k;++i){
        go_nex();
        if(same()){
            if((k-i)&1){ok=0; break;}
            if(i==1 && k>1){
                reset();
                go_prv();
                if(same()){ok=0; break;}
            }
            yes();
        }
    }
    reset();
    for(int i=1;i<=k;++i){
        go_prv();
        if(same()){
            if((k-i)&1){ok=0; break;}
            if(i==1 && k>1){
                reset();
                go_nex();
                if(same()){ok=0; break;}
            }
            yes();
        }
    }
    no();
}
