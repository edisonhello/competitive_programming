#include<bits/stdc++.h>
using namespace std;

int ans[1<<21];

int main(){
    int t; cin>>t; while(t--){
        int k; cin>>k;
        int n=(1<<k)-1;
        memset(ans,0,sizeof(ans));
        ans[1]=1;
        set<int> st;
        st.insert(1);
        for(int i=2;i<=n;++i){
            for(int ii:st){
                if(__gcd(ans[ii],i)==1){
                    if(!ans[ii*2])ans[ii*2]=i,st.insert(ii*2);
                    else ans[ii*2+1]=i,st.erase(ii),st.insert(ii*2+1);
                    break;
                }
            }
        }
        for(int i=1;i<=n;++i)cout<<ans[i]<<" "; cout<<endl;
    }
}
