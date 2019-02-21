#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
#include<cmath>
#include<iomanip>
#define ld long double

struct rea{ld a,e;};
// bool operator<(const rea &a,const rea &b){return a.e/a.a < b.e/b.a;}
bool cmpe(const rea &a,const rea &b){return a.e < b.e;}
bool cmpea(const rea &a,const rea &b){return a.e/a.a < b.e/a.a;}
bool cmpa(const rea &a,const rea &b){return a.a < b.a;}
bool cmpae(const rea &a,const rea &b){return a.a/a.e < b.a/b.e;}
const ld eps=1e-8;

vector<rea> posa,nega,noa;

int main(){
    ios_base::sync_with_stdio(0);
    int ts;cin>>ts;while(ts--){
        posa.clear(),nega.clear(),noa.clear();
        int n;cin>>n;
        while(n--){
            ld u,a,e;cin>>u>>a>>e;
            a/=u,e/=u;
            if(a>0.0)posa.push_back({a,e});
            else if(a<0.0)nega.push_back({-a,e});
            else noa.push_back({a,e});
        }
        ld mx=0.0;
        if(posa.size()){sort(posa.begin(),posa.end(),cmpe); mx=max({mx,posa.back().e});}
        if(noa.size()){sort(noa.begin(),noa.end(),cmpe); mx=max({mx,noa.back().e});}

        if(nega.size() && posa.size()){
            sort(nega.begin(),nega.end(),cmpae); sort(posa.begin(),posa.end(),cmpa); reverse(posa.begin(),posa.end());
            // cout<<"neg: "<<nega[0].a<<" "<<nega[0].e<<", pos: "<<posa[0].a<<" "<<posa[0].e<<endl;
            // cout<<"negs:";for(auto i:nega)cout<<"("<<i.a<<","<<i.e<<") ";cout<<endl;
            // cout<<"poss:";for(auto i:posa)cout<<"("<<i.a<<","<<i.e<<") ";cout<<endl;
            ld a_posa_can_pvd=posa[0].a/nega[0].a;
            ld a_lp_energ=posa[0].e+a_posa_can_pvd*nega[0].e;
            ld a_lp_use_U=1.0+a_posa_can_pvd;
            mx=max({mx,a_lp_energ/a_lp_use_U});
        }
        cout<<fixed<<setprecision(8)<<mx<<endl;
    }
}
// x-y, tb, I->max(y)
