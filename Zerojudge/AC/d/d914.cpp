#include<bits/stdc++.h>
using namespace std;

int a[24][24][2];
int main(){
    int n; cin>>n; while(n--){
        int x,y,c; cin>>x>>y>>c; if(!c)c=-1;
        a[x][y][0]=c;
    }
    cin>>n; while(n--){
        int x,y,c; cin>>x>>y>>c; if(!c)c=-1;
        a[x][y][1]=c;
    }
    int ans=0;
    for(int i=0;i<24;++i)for(int j=0;j<24;++j)ans+=abs(a[i][j][0]-a[i][j][1]);
    cout<<ans<<endl;
}
