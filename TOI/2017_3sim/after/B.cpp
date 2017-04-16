#include<bits/stdc++.h>
using namespace std;

struct event{int p,t,w;};
vector<event> v;

int main(){
    int n;cin>>n;
    for(int i=0;i<n;++i){
        int l,r,w;cin>>l>>r>>w;
        v.push_back({l,1,w});
        v.push_back({r+1,0,w});
    }
    sort(v.begin(),v.end(),[](const event &a,const event &b){return a.p<b.p;});
    int mx=0,now=0,tin=0,prv=-1;
    for(event &e:v){
        if(e.p!=prv){
            if(tin<now)tin=now;
            mx=max(mx,tin);
            prv=e.p;
        }
        if(e.t){
            tin+=e.w;
            now+=e.w;
        }
        else{
            now-=e.w;
        }
    }
    cout<<mx<<endl;
}
// AC
