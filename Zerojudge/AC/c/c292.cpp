#include<bits/stdc++.h>
using namespace std;

int a[55][55];
int dx[]={0,-1,0,1},dy[]={-1,0,1,0};
int main(){
    int n,d; cin>>n>>d;
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)cin>>a[i][j];
    int _step=2,x=n/2,y=n/2,cnt=0;
    while(cnt<n*n){
        int step=_step/2; ++_step;
        cnt+=step;
        for(int i=0;i<step;++i){
            cout<<a[x][y];
            x+=dx[d]; y+=dy[d];
        }
        d=(d+1)%4;
    }
    cout<<endl;
}
