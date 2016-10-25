#include<bits/stdc++.h>
using namespace std;
int main(){
    int cs;cin>>cs;while(cs--){
        int h,w,n;cin>>h>>w>>n;
        char m[105][105];
        memset(m,0,sizeof(m));
        for(int aaa=0;aaa<n;++aaa){
            int l,u,r,d;char c;cin>>l>>u>>r>>d>>c;
            for(int i=l;i<=r;++i){
                for(int j=u;j<=d;++j){
                    m[j][i]=c;
                }
            }
        }
        for(int i=1;i<=h;++i){
            for(int j=1;j<=w;++j){
                if(!m[i][j])cout<<'o';
                else cout<<m[i][j];
            }
            cout<<endl;
        }
        if(cs)cout<<endl;
    }
}
