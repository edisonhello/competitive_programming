#include<bits/stdc++.h>
using namespace std;

int n,m,len[35][35],cf[35][35];
string ans,s,t;
unordered_set<string> st;

void dfs(int i,int j){
    // cout<<"dfs: "<<i<<" "<<j<<" "<<len[i][j]<<" "<<cf[i][j]<<endl;
    if(!i || !j){
        st.insert(ans);
        return ;
    }
    if(cf[i][j]&2)dfs(i-1,j);
    if(cf[i][j]&4)dfs(i,j-1);
    if(cf[i][j]&1){
        ans+=s[i];
        dfs(i-1,j-1);
        ans.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ts,ks=0; cin>>ts; while(ts--){
        memset(len,0,sizeof(len));
        memset(cf,0,sizeof(cf));
        cin>>s>>t;
        st.clear(); ans="";
        s="$"+s; t="#"+t;
        n=s.size()-1, m=t.size()-1;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(s[i]==t[j]){
                    len[i][j]=len[i-1][j-1]+1;
                    cf[i][j]=1;
                }
                else len[i][j]=max(len[i-1][j],len[i][j-1]);
                if(len[i-1][j]==len[i][j])cf[i][j]^=2;
                if(len[i][j-1]==len[i][j])cf[i][j]^=4;
            }
        }
        dfs(n,m);
        cout<<"Case #"<<(++ks)<<": "<<st.size()<<endl;
        vector<string> ans;
        for(auto i:st){
            reverse(i.begin(),i.end());
            ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        for(auto &i:ans)cout<<i<<'\n';
        #ifdef WEAK
        fflush(stdout);
        #endif
    }
}
