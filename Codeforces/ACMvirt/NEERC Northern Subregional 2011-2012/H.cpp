#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
string s[maxn];

int parse(char c) {
    if(c>='0' && c<='9')return c-'0';
    if(c>='A' && c<='Z')return c-'A'+10;
    if(c>='a' && c<='z')return c-'a'+10+26;
}

map<long long,int> mp[32];
long long ans[6];

int main() {
    freopen("high.in","r",stdin);
    freopen("high.out","w",stdout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> s[i];
        for(int j=0;j<(1<<5);++j){
            long long val=0,base=1;
            int cnt=0;
            for(int k=0;k<5;++k){
                if(j&(1<<k)){
                    ++cnt;
                    val+=base*parse(s[i][k]);
                }
                base*=65;
            }
            ans[cnt]+=mp[j][val];
            ++mp[j][val];
        }
    }
    // for (int i = 0; i <= 5; ++i) cout << ans[i] << ' '; cout << endl;
    ans[4]-=5*ans[5];
    ans[3]-=4*ans[4]+10*ans[5];
    ans[2]-=3*ans[3]+6*ans[4]+10*ans[5];
    ans[1]-=2*ans[2]+3*ans[3]+4*ans[4]+5*ans[5];
    ans[0]-=1*ans[1]+1*ans[2]+1*ans[3]+1*ans[4]+1*ans[5];
    /* for (int i = 0; i <= 5; ++i) {
        for (int j = i - 1; j >= 0; --j) ans[i] -= ans[j];
    } */
    for(int i=5;i>=0;--i)cout<<ans[i]<<" "; cout<<endl;
}
