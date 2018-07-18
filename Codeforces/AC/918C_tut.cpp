#include<bits/stdc++.h>
using namespace std;

int a[5005],pre[5005];
vector<int> pos[10055];

int main(){
    string s; cin>>s;
    int n=s.size();
    for(int i=1;i<=n;++i)a[i]=(s[i-1]=='('?1:(s[i-1]==')'?-1:0));
    // for(int i=1;i<=n;++i)cout<<a[i]<<" "; cout<<endl;
    int ans=0;
    for(int i=1;i<=n;++i){
        int lb=0,ub=0;
        for(int j=i;j<=n;++j){
            if(a[j]<=0)--lb; else ++lb;
            if(a[j]>=0)++ub; else --ub;
            if(lb<0)lb+=2;
            if(ub<0)break;
            if((i^j)&1){
                if(!lb)++ans;
            }
        }
    }
    cout<<ans<<endl;
}
