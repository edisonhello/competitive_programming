#include<bits/stdc++.h>
using namespace std;

pair<int,int> pts[22];
int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=m;++i)pts[i].second=i;
    while(n--){
        string ans; cin>>ans;
        string fol; getline(cin,fol); stringstream ss(fol); int x; string gus; while(ss>>x>>gus){
            if(gus==ans){++pts[x].first; break;}
        }
    }
    int mx=0;
    for(int i=1;i<=m;++i)mx=max(mx,pts[i].first);
    vector<int> v;
    for(int i=1;i<=m;++i)if(mx==pts[i].first)v.push_back(i);
    bool fst=0; for(int i:v){if(fst){cout<<" ";}fst=1;cout<<i;} cout<<endl;
    for(int i=1;i<=m;++i)cout<<i<<" "<<pts[i].first<<endl;
}
