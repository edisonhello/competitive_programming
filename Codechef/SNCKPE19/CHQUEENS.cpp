#include<bits/stdc++.h>
using namespace std;

int zadd[1000],zsub[1000];

int main(){
    int t; cin>>t; while(t--){
        int n,m,x,y; cin>>n>>m>>x>>y;
        memset(zadd,0,sizeof(zadd));
        memset(zsub,0,sizeof(zsub));
        for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
            ++zadd[i+j+500];
            ++zsub[i-j+500];
        }
        int ok=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(i==x && j==y){
                    int add=(n-1)*(m-1);
                    add-=zadd[i+j+500]+zsub[i-j+500]-2;
                    ok-=add;
                    continue;
                }
                /* int add=0;
                cout<<"ij: "<<i<<" "<<j<<endl;
                if(i==x || j==y){
                    add=(n-1)*(m-1);
                    if(i==x){
                        if(j<y)add+=m-y;
                        else add+=y-1;
                    }
                    else{
                        if(i<x)add+=n-x;
                        else add+=x-1;
                    }
                    cout<<"add: "<<add<<endl;
                }
                else{
                    int add=(n-1)*(m-1)-1;
                    cout<<"add: "<<add<<endl;
                } */
                int add=(n-1)*(m-1);
                add-=zadd[i+j+500]+zsub[i-j+500]-2;
                ok+=add;
                // cout<<i<<" "<<j<<" "<<add<<endl;
            }
        }
        // cout<<"old ok "<<ok<<endl;
        ok+=(x-1)*(n-x)*2;
        ok+=(y-1)*(m-y)*2;
        ok+=min(x-1,y-1)*min(n-x,m-y)*2;
        ok+=min(x-1,m-y)*min(y-1,n-x)*2;
        cout<<ok<<endl;
    }
}
