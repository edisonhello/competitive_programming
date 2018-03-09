#include<bits/stdc++.h>
using namespace std;

vector<int> app[1000006];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;++i){
        int t; cin>>t;
        app[t].push_back(i);
    }
    int q; cin>>q; while(q--){
        int m; cin>>m;
        int pos=-1;
        bool ok=1;
        while(m--){
            int t; cin>>t;
            auto it=upper_bound(app[t].begin(),app[t].end(),pos);
            if(it==app[t].end()){ok=0; continue;}
            pos=*it;
        }
        if(ok)cout<<"TAK"<<'\n';
        else cout<<"NIE"<<'\n';
    }
}
