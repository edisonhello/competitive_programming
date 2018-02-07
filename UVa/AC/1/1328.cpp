#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

const ll p=47017;
ll hsh[1000006],pw[1000006];

ll gethh(int l,int r){
    ll hh=hsh[r]; if(l)hh-=hsh[l-1];
    return hh;
}

int main(){
    pw[0]=1;
    for(int i=1;i<1000006;++i)pw[i]=pw[i-1]*p;
    int n,ks=0; while(cin>>n,n){
        string s; cin>>s;
        bool same=1;
        int rep=0;
        ll np=1; for(int i=0;i<n;++i){
            hsh[i]=s[i]*np; np*=p;
            if(i)hsh[i]+=hsh[i-1];
        }
        cout<<"Test case #"<<(++ks)<<endl;
        for(int i=1;i<n;++i){
            if(s[i]!=s[0])same=0;
            if(same)cout<<i+1<<" "<<i+1<<endl;
            else if(rep){
                if((i+1)%rep==0){
                    int LL=0,LR=rep-1,RL=i-rep+1,RR=i;
                    if(gethh(LL,LR)*pw[RL-LL]==gethh(RL,RR)){
                        cout<<i+1<<" "<<(i+1)/rep<<endl;
                    }
                    else rep=0;
                }
            }
            if(!same && !rep){
                if(i&1){
                    int LL=0,LR=i/2,RL=LR+1,RR=i;
                    if(gethh(LL,LR)*pw[RL-LL]==gethh(RL,RR)){
                        rep=i/2+1;
                        cout<<i+1<<" "<<2<<endl;
                    }
                }
            }
        }
        cout<<endl;
    }
}
