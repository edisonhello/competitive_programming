#include<bits/stdc++.h>
using namespace std;

int cnt[3][8];
// vector<bitset<3>> s[3];

int main(){
    int n; cin>>n;
    while(n--){
        int c; cin>>c; --c;
        int q,w,e;
        cin>>q>>w>>e;
        int id=(q<<2)|(w<<1)|e;
        // s[c].push_back(tmp);
        ++cnt[c][id];
    }
    long long  ans=0;
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j){
            for(int k=0;k<8;++k){
                if((i|j|k)!=7)continue;
                ans+=1ll*cnt[0][i]*cnt[1][j]*cnt[2][k];
            }
        }
    }
    cout<<ans<<endl;
}
