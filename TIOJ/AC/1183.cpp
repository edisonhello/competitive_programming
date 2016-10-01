#include<iostream>
using namespace std;

string G[21],ans;
int ts,m,n,i,j,x,y,sx,sy,tx,ty;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>ts;
    do{
        cin>>m>>n;
        for(i=0;i<m;++i){
            cin>>G[i];
            for(j=0;j<n;++j){
                if(G[i][j]=='S'){
                    sx=i;
                    sy=j;
                }
                else if(G[i][j]=='T'){
                    tx=i;
                    ty=j;
                }
            }
        }
        x=sx;y=sy;
        ans="";
        while(x!=tx || y!=ty){
            G[x][y]='#';
            if(x>0 && (G[x-1][y]=='.'||G[x-1][y]=='T')){
                --x;
                ans+='U';
            }
            else if(x<m-1 && (G[x+1][y]=='.'||G[x+1][y]=='T')){
                ++x;
                ans+='D';
            }
            else if(y>0 && (G[x][y-1]=='.'||G[x][y-1]=='T')){
                --y;
                ans+='L';
            }
            else if(y<n-1 && (G[x][y+1]=='.'||G[x][y+1]=='T')){
                ++y;
                ans+='R';
            }
        }
        cout<<ans<<'\n';
    }while(--ts);
}
