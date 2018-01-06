#include<bits/stdc++.h>
using namespace std;

pair<long long,long long> it[100005];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>it[i].first;
    for(int i=0;i<n;++i)cin>>it[i].second;
    sort(it,it+n,[](const pair<long long,long long> &a,const pair<long long,long long> &b){return (long double)a.first/a.second<(long double)b.first/b.second;});
    long long ans=0,pre=0;
    for(int i=0;i<n;++i){
#ifdef WEAK
        cout<<it[i].first<<" "<<it[i].second<<endl;
#endif
        ans+=pre*it[i].second;
        pre+=it[i].first;
    }
    cout<<ans<<endl;
}
