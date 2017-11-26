#include<bits/stdc++.h>
using namespace std;

map<int,long long> pos[3];
int a[200005];

int main(){
    ios_base::sync_with_stdio(0);
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]%k==0){
            if(a[i]/k%k==0){
                pos[2][a[i]]+=pos[1][a[i]/k];
            }
            pos[1][a[i]]+=pos[0][a[i]/k];
        }
        ++pos[0][a[i]];
    }
    long long ans=0;
    for(auto &i:pos[2])ans+=i.second;
    cout<<ans<<endl;
}
