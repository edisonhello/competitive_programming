#include<bits/stdc++.h>
#include"Boblib.h"
using namespace std;

bitset<1111> is_orgp;
int orig_id[1111],idtrand[1111],infront[1111],inback[1111];
vector<int> G[1111];

void Bob(int n,int m,int *a,int *b){
    // cout<<"Bob "<<n<<" "<<m<<endl;
    for(int i=0;i<m;++i){
        G[a[i]].push_back(b[i]);
        ++infront[a[i]];
        ++inback[b[i]];
        // cout<<"Now Graph: "<<a[i]<<" "<<b[i]<<endl;
    }
    for(int i=0;i<n;++i){
        if(infront[i]==n-12 && inback[i]==0)orig_id[i]=n-1,idtrand[n-1]=i;
        else if(infront[i]==n-11 && inback[i]==0)orig_id[i]=n-2,idtrand[n-2]=i;
    }
    for(auto p:G[idtrand[n-1]]){
        is_orgp[p]=1;
        // cout<<"is orgp: "<<p<<endl;
    }
    // cout<<"as"<<endl;
    int chain_1;
    for(auto p:G[idtrand[n-2]]){
        if(!is_orgp[p])chain_1=p;
    }
    // cout<<"chain_1: "<<chain_1<<endl;
    int chain[11]={idtrand[n-2],chain_1};
    for(int i=1;i<=10;++i){
        for(auto p:G[chain[i]]){
            if(!is_orgp[p])chain[i+1]=p;
        }
    }
    // cout<<"super n+1: "<<idtrand[n-2]<<" , n: "<<idtrand[n-1]<<endl;
    for(int i=1;i<=10;++i)orig_id[chain[i]]=n-13+i,idtrand[n-13+i]=chain[i];
    // cout<<"chain: "; for(int i=0;i<=10;++i)cout<<chain[i]<<" "; cout<<endl;
    for(int i=n-12,j=0;i<n-2;++i,++j){
        for(auto p:G[idtrand[i]]){
            if(is_orgp[p]){
                orig_id[p]|=(1<<j);
            }
        }
    }
    // for(int i=0;i<n;++i)cout<<"orig_id of "<<i<<" id "<<orig_id[i]<<endl;
    vector<pair<int,int>> oG;
    for(int i=0;i<m;++i){
        if(orig_id[a[i]]>=n-12 || orig_id[b[i]]>=n-12)continue;
        oG.emplace_back(orig_id[a[i]],orig_id[b[i]]);
    }
    // cout<<"oG size: "<<oG.size()<<endl;
    InitMap(n-12,oG.size());
    for(auto p:oG){
        // cout<<"oG: "<<p.first<<" to "<<p.second<<endl;
        MakeMap(p.first,p.second);
    }
}
