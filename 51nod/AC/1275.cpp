#include<bits/stdc++.h>
using namespace std;

int a[50005];
vector<pair<int,int>> num;

int main(){
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        num.emplace_back(a[i],i);
    }
    set<int> block;
    for(int i=0;i<=n+1;++i)block.insert(i);
    sort(num.begin(),num.end());
    reverse(num.begin(),num.end());
    int rptr=-1;
    long long ans=0;
    for(auto p:num){
        while(rptr+1<num.size() && p.first-num[rptr+1].first<=k){
            ++rptr;
            block.erase(num[rptr].second);
        }
        auto it=block.upper_bound(p.second);
        int uu=*it; --it; int dd=*it;
        ans+=1ll*(p.second-dd)*(uu-p.second);
        block.insert(p.second);
    }
    cout<<ans<<endl;
}
