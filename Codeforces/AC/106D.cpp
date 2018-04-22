#include<bits/stdc++.h>
using namespace std;

string mp[1111];
int pre[1111][1111];

int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>mp[i];
        mp[i]="#"+mp[i]+"#";
        for(int j=1;j<=m;++j){
            pre[i][j]=(mp[i][j]=='#');
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            pre[i][j]+=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
        }
    }
    vector<pair<char,int>> op;
    int q; cin>>q; while(q--){
        char c; int l; cin>>c>>l;
        op.emplace_back(c,l);
    }
    bool out=0;
    for(int ta='A';ta<='Z';++ta){
        int sx=-1,sy;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(mp[i][j]==ta){
                    sx=i, sy=j;
                }
            }
        }
        if(sx==-1)continue;
        bool ok=1;
        auto ge=[&](int x1,int y1,int x2,int y2){return pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1];};
        for(auto p:op){
            if(p.first=='N'){
                if(sx<=p.second){ok=0; break;}
                if(ge(sx-p.second,sy,sx,sy)){ok=0; break;}
                sx-=p.second;
            }
            else if(p.first=='S'){
                if(sx+p.second>n){ok=0; break;}
                if(ge(sx,sy,sx+p.second,sy)){ok=0; break;}
                sx+=p.second;
            }
            else if(p.first=='W'){
                if(sy<=p.second){ok=0; break;}
                if(ge(sx,sy-p.second,sx,sy)){ok=0; break;}
                sy-=p.second;
            }
            else{
                if(sy+p.second>m){ok=0; break;}
                if(ge(sx,sy,sx,sy+p.second)){ok=0; break;}
                sy+=p.second;
            }
        }
        if(ok){
            cout<<char(ta);
            out=1;
        }
    }
    if(!out)cout<<"no solution"<<endl;
}
