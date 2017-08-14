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
        ll rec[100][100];
        for(int i=0;i<100;++i)for(int j=0;j<100;++j)rec[i][j]=9999999999ll;
        sort(pos.begin(),pos.end());
        pos.resize(unique(pos.begin(),pos.end())-pos.begin());
        if(pos.empty()){
            for(int i=0;i<n;++i){
                ans+=abs(inf[i].s-inf[i].t);
            }
        }
        else if(pos.size()==1u){
            for(int i=0;i<n;++i){
                ans+=abs(inf[i].s-inf[i].t);
                if(!inf[i].same)ans++;
            }
        }
        else{
            for(int i=0;i<pos.size();++i){
                for(int j=i+1;j<pos.size();++j){
                    ll ts=0;
                    for(int k=0;k<n;++k){
                        if(inf[i].same){
                            ts+=inf[i].t-inf[i].s;
                        }
                        else{
                            if((inf[k].s<pos[i] && pos[i]<inf[k].t) || (inf[k].s<pos[j] && pos[j]<inf[k].t)){
                                ts+=inf[k].t-inf[k].s+1;
                            }
                            else{
                                ts+=min(abs(inf[k].s-pos[i])+abs(inf[k].t-pos[i]),abs(inf[k].s-pos[j])+abs(inf[k].t-pos[j]));
                            }
                        }
                    }
                    rec[i][j]=ts;
                    cout<<i<<" "<<j<<" "<<rec[i][j]<<endl;
                }
            }
        }
        cout<<ans<<endl;
    }
}
