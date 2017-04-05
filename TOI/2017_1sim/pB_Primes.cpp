#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll l,r;
bitset<31622789> v;
vector<ll> p;
void init(){
    for(int i=2;i<31622789;++i){
        if(!v[i])p.push_back(i);
//        cout<<i<<endl;
        for(int j=0;(ll)i*p[j]<31622789;++j){
//            cout<<i*p[j]<<endl;
            v[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
    // cout<<p.size()<<endl;  // 1951959
}


bool isp(ll n){
    if(n==1)return 0;
    for(int i=0;p[i]*p[i]<=n;++i){
        if(n%p[i]==0)return 0;
    } return 1;
}

vector<ll> pp;
int main(){
    init();
    ll l,u; cin>>l>>u;
    for(ll i=l;i<=u;++i){
        if(isp(i))pp.push_back(i);
    }
    if(pp.size()<2)return cout<<"0 0 0 0\n",0;
    ll mn=pp[1]-pp[0],mx=pp[1]-pp[0],mnl=pp[0],mnr=pp[1],mxl=pp[0],mxr=pp[1];
    for(int i=2;i<pp.size();++i){
        if(pp[i]-pp[i-1]<mn){
            mn=pp[i]-pp[i-1];
            mnl=pp[i-1],mnr=pp[i];
        }
        if(pp[i]-pp[i-1]>mx){
            mx=pp[i]-pp[i-1];
            mxl=pp[i-1],mxr=pp[i];
        }
    }
    cout<<mnl<<" "<<mnr<<" "<<mxl<<" "<<mxr<<endl;
}
