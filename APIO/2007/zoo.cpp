#include<bits/stdc++.h>
using namespace std;

struct child{
    set<int> bad,good;
};
vector<child> cs[10004];
int dp[10004][16];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,c; cin>>n>>c;
    for(int i=0;i<c;++i){
        int e,f,l,t; cin>>e>>f>>l;
        child tmp;
        for(int i=0;i<f;++i)cin>>t,tmp.bad.insert((t-e<0?t-e+n:t-e));
        for(int i=0;i<l;++i)cin>>t,tmp.good.insert((t-e<0?t-e+n:t-e));
        cs[e].push_back(tmp);
    }
    int ans=0;
    for(int st=0;st<16;++st){
        memset(dp,0xb0,sizeof(dp));
        dp[0][st]=0;
        for(int i=1;i<=n-4;++i){
            for(int j=0;j<16;++j){
                int &now=dp[i][j];
                {
                    int status=(j<<1)|1;
                    int from=status&15;
                    int val=dp[i-1][from];
                    for(auto &c:cs[i]){
                        bool add=0;
                        for(int i:c.good){
                            if(status&(1<<i)){
                                add=1;
                                break;
                            }
                        }
                        if(!add)for(int i:c.bad){
                            if(!(status&(1<<i))){
                                add=1;
                                break;
                            }
                        }
                        val+=add;
                    }
                    now=max(now,val);
                }
                {
                    int status=j<<1;
                    int from=status&15;
                    int val=dp[i-1][from];
                    for(auto &c:cs[i]){
                        bool add=0;
                        for(int i:c.good){
                            if(status&(1<<i)){
                                add=1;
                                break;
                            }
                        }
                        if(!add)for(int i:c.bad){
                            if(!(status&(1<<i))){
                                add=1;
                                break;
                            }
                        }
                        val+=add;
                    }
                    now=max(now,val);
                }
            }
        }
        for(int i=n-3;i<=n;++i){
            for(int j=0;j<16;++j){
                if((j>>(n-i))!=(st&(((1<<(i-(n-4)))-1))))continue;
                int &now=dp[i][j];
                {
                    int status=(j<<1)|1;
                    int from=status&15;
                    int val=dp[i-1][from];
                    for(auto &c:cs[i]){
                        bool add=0;
                        for(int i:c.good){
                            if(status&(1<<i)){
                                add=1;
                                break;
                            }
                        }
                        if(!add)for(int i:c.bad){
                            if(!(status&(1<<i))){
                                add=1;
                                break;
                            }
                        }
                        val+=add;
                    }
                    now=max(now,val);
                }
                {
                    int status=j<<1;
                    int from=status&15;
                    int val=dp[i-1][from];
                    for(auto &c:cs[i]){
                        bool add=0;
                        for(int i:c.good){
                            if(status&(1<<i)){
                                add=1;
                                break;
                            }
                        }
                        if(!add)for(int i:c.bad){
                            if(!(status&(1<<i))){
                                add=1;
                                break;
                            }
                        }
                        val+=add;
                    }
                    now=max(now,val);
                }
            }
        }
        for(int i=0;i<16;++i)ans=max(ans,dp[n][i]);
    }
    cout<<ans<<endl;
}
