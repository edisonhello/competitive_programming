#include<bits/stdc++.h>
using namespace std;

int g[1000006];
vector<int> vg[10];

int dec(int x){
    int rt=1;
    while(x){
        if(x%10)rt*=x%10;
        x/=10;
    }
    return rt;
}

int main(){
    for(int i=1;i<10;++i){
        vg[i].push_back(i);
        g[i]=i;
    }
    for(int i=10;i<=1000000;++i){
        int ii=dec(i);
        g[i]=g[ii];
        vg[g[i]].push_back(i);
    }
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin>>q; while(q--){
        int l,r,k; cin>>l>>r>>k;
        cout<<upper_bound(vg[k].begin(),vg[k].end(),r)-lower_bound(vg[k].begin(),vg[k].end(),l)<<endl;
    }
}
