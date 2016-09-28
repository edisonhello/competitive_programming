#include<bits/stdc++.h>
using namespace std;
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
string mp[25];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int sx,sy,tx,ty;
        for(int i=1;i<=n;i++){
            cin>>mp[i];
            // cout<<mp[i]<<endl;
            mp[i]='#'+mp[i]+'#';
            for(int j=1;j<m;j++){
                if(mp[i][j]=='S'){
                    sx=i,sy=j;
                }
                else if(mp[i][j]=='T'){
                    tx=i,ty=j;
                }
            }
        }
        for(int i=0;i<=m+1;i++){
            mp[0]+='#';
            mp[n+1]+='#';
        }
        int x=sx,y=sy;
        string ans="";
        while(!(x==tx&&y==ty)){
            cout<<x<<" "<<y<<endl;
            mp[x][y]='#';
            for(int i=0;i<4;i++){
                if(mp[x+xx[i]][y+yy[i]]!='#'){
                    x+=xx[i];
                    y+=yy[i];
                    if(i==0)ans+='R';
                    if(i==1)ans+='D';
                    if(i==2)ans+='L';
                    if(i==3)ans+='U';
                    break;
                }
            }
        }
        cout<<ans<<'\n';
    }
}
