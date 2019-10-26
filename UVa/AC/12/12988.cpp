#include<bits/stdc++.h>
using namespace std;

string s[4];

void dfs(int x,int y){
    if(x==4){
        bool ok=1;
        for(int i=0;i<3;i+=2){
            for(int j=0;j<3;j+=2){
                set<int> st;
                st.insert(s[i][j]);
                st.insert(s[i][j+1]);
                st.insert(s[i+1][j]);
                st.insert(s[i+1][j+1]);
                if(st.size()!=4u)ok=0;
            }
        }
        if(ok){
            for(int i=0;i<4;++i)cout<<s[i]<<'\n';
        }
        return;
    }
    else{
        if(s[x][y]=='*'){
            for(int t='1';t<='4';++t){
                bool ok=1;
                for(int i=0;i<4;++i){
                    if(s[i][y]==t || s[x][i]==t)ok=0;
                }
                if(ok){
                    s[x][y]=t;
                    if(y==3)dfs(x+1,0);
                    else dfs(x,y+1);
                    s[x][y]='*';
                }
            }
        }
        else{
            if(y==3)dfs(x+1,0);
            else dfs(x,y+1);
        }
    }
}

int main(){
    int t; cin>>t;
    int ks=0; while(t--){
        cout<<"Case #"<<(++ks)<<":\n";
        for(int i=0;i<4;++i)cin>>s[i];
        dfs(0,0);
    }
}
