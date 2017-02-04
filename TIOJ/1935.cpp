#include<iostream>
using namespace std;
#include<algorithm>
#define ll long long
#include<vector>
#include<cmath>

struct st{bool same;ll s,t;};

vector<ll> pos;
vector<st> inf;

int main(){
    int k,n;cin>>k>>n;
    inf.resize(n);
    for(int i=0;i<n;++i){
        char p,q;
        cin>>p>>inf[i].s>>q>>inf[i].t;
        if(inf[i].s>inf[i].t)swap(inf[i].s,inf[i].t);
        if(p==q){
            inf[i].same=1;
        }
        else{
            inf[i].same=0;
            pos.push_back(inf[i].s);
            pos.push_back(inf[i].t);
        }
    }
    if(k==1){
        ll ans=0;
        if(pos.size()){
            sort(pos.begin(),pos.end());
            ll bat=(pos[pos.size()/2-1]+pos[pos.size()/2])/2;
            for(int i=0;i<n;++i){
                if(inf[i].same){
                    ans+=abs(inf[i].s-inf[i].t);
                }
                else{
                    ans+=abs(inf[i].s-bat)+abs(bat-inf[i].t)+1;
                }
            }
        }
        else{
            for(int i=0;i<n;++i){
                ans+=abs(inf[i].s-inf[i].t);
            }
        }
        cout<<ans<<endl;
    }
    else{
        ll ans=0;
        if(pos.size()){
            sort(pos.begin(),pos.end());
            ll b1=(pos[pos.size()/3-1]+pos[pos.size()/3])/2;
            ll b2=(pos[pos.size()/3*2-1]+pos[pos.size()/3*2])/2;
            for(int i=0;i<n;++i){
                if(inf[i].same){
                    ans+=abs(inf[i].s-inf[i].t);
                }
                else{
                    ans+=min(abs(inf[i].s-b1)+abs(b1-inf[i].t),abs(inf[i].s-b2)+abs(b2-inf[i].t))+1;
                }
            }
        }
        else{
            for(int i=0;i<n;++i){
                ans+=abs(inf[i].s-inf[i].t);
            }
        }
        cout<<ans<<endl;
    }
}
