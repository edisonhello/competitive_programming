#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> a[100005];

ll query(const vector<int> &a,const vector<int> &b){
    ll pre[100005];
    pre[0]=0;
    ll rt=0;
    for(int i=0;i<a.size();++i)pre[i+1]=pre[i]+a[i];
    for(int i=0;i<b.size();++i){
        int big=lower_bound(a.begin(),a.end(),b[i])-a.begin();
        rt+=(pre[a.size()]-pre[big])-1ll*b[i]*(a.size()-big)+1ll*b[i]*big-pre[big];
    }
    return rt;
}

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        int s; cin>>s; a[i].resize(s);
        for(int j=0;j<s;++j)cin>>a[i][j];
        sort(a[i].begin(),a[i].end());
    }
    int q; cin>>q; while(q--){
        int i,j; cin>>i>>j;
        cout<<query(a[i],a[j])<<endl;
    }
}
