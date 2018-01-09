#include<bits/stdc++.h>
using namespace std;

bitset<5005> a[5005];
int main(){
    int t; cin>>t; while(t--){
        int n,r,c; cin>>n>>r>>c;
        int x=1,y=n/2+1,ptr=1;
        for(int i=1;i<=n;++i)a[i].reset();
        while(!a[r][c]){
            a[x][y]=1; ++ptr;
            int xx,yy;
            if(x==1 && y==1)xx=x+1,yy=y;
            else if(x==1)xx=n,yy=y-1;
            else if(y==1)xx=x-1,yy=n;
            else xx=x-1,yy=y-1;
            if(a[xx][yy])xx=x+1,yy=y;
            // cout<<x<<" "<<y<<" "<<xx<<" "<<yy<<endl;
            x=xx,y=yy;
        }
        cout<<ptr-1<<endl;
        #ifdef WEAK
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                cout<<a[i][j]<<" ";
            } cout<<endl;
        }
        #endif
    }
}
