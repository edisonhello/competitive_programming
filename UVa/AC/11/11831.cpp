#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,m,s,px,py,dir;
string mp[105];
int main(){
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    ios_base::sync_with_stdio(0);
    while(cin>>n>>m>>s,n){
        px=py=dir=0;
        for(int i=0;i<105;++i)mp[i].clear();
        for(int i=0;i<=m+1;++i)mp[0]+='#',mp[n+1]+='#';
        for(int i=1;i<=n;++i){
            cin>>mp[i];mp[i]="#"+mp[i]+"#";
            if(!(px||py||dir))for(int j=1;j<=m;++j){
                if(mp[i][j]=='N')px=i,py=j,dir=1;
                if(mp[i][j]=='S')px=i,py=j,dir=2;
                if(mp[i][j]=='L')px=i,py=j,dir=3;
                if(mp[i][j]=='O')px=i,py=j,dir=4;
            }
        }
        string opr;cin>>opr;int ans=0;
        for(char c:opr){
            if(c=='D'){
                if(dir==1)dir=3;
                else if(dir==2)dir=4;
                else if(dir==3)dir=2;
                else dir=1;
            }
            else if(c=='E'){
                if(dir==3)dir=1;
                else if(dir==4)dir=2;
                else if(dir==2)dir=3;
                else dir=4;
            }
            else{
                if(dir==1){
                    if(mp[px-1][py]!='#')--px;
                    if(mp[px][py]=='*'){
                        ++ans;
                        mp[px][py]='.';
                    }
                }
                else if(dir==2){
                    if(mp[px+1][py]!='#')++px;
                    if(mp[px][py]=='*'){
                        ++ans;
                        mp[px][py]='.';
                    }
                }
                else if(dir==3){
                    if(mp[px][py+1]!='#')++py;
                    if(mp[px][py]=='*'){
                        ++ans;
                        mp[px][py]='.';
                    }
                }
                else{
                    if(mp[px][py-1]!='#')--py;
                    if(mp[px][py]=='*'){
                        ++ans;
                        mp[px][py]='.';
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
