#include<bits/stdc++.h>
using namespace std;

int a[1555][1555],pre[1555][1555],rans[1555],lans[1555],uans[1555],dans[1555],tmp[1555][1555];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin>>n>>m>>k;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>a[i][j];
        }
    }

    int ans=0;
    auto meow=[&](function<void()> callback){
        memset(pre,0,sizeof(pre));
        memset(rans,0,sizeof(rans));
        memset(lans,0,sizeof(lans));
        memset(uans,0,sizeof(uans));
        memset(dans,0,sizeof(dans));

        auto get=[&](int x,int y){
            if(x<k || y<k)return 0;
            return pre[x][y]-pre[x-k][y]-pre[x][y-k]+pre[x-k][y-k];
        };
        [&](){
            for(int i=1;i<=n;++i){
                for(int j=1;j<=m;++j){
                    pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i][j];
                }
            }
            for(int j=m;j>=1;--j){
                for(int i=1;i<=n;++i){
                    rans[j]=max(max(rans[j],rans[j+1]),get(i,j));
                }
                // cout<<"rans["<<j<<"]="<<rans[j]<<endl;
            }
            for(int j=1;j<=m;++j){
                for(int i=1;i<=n;++i){
                    lans[j]=max(max(lans[j],lans[j-1]),get(i,j));
                }
                // cout<<"lans["<<j<<"]="<<lans[j]<<endl;
            }
            for(int j=1;j<k;++j){
                for(int i=1;i<=n;++i){
                    uans[i]=max(max(uans[i],uans[i-1]),get(i,j));
                }
                for(int i=n;i>=1;--i){
                    dans[i]=max(max(dans[i],dans[i+1]),get(i,j));
                }
            }
        }();
        for(int j=k;j<=m-k;++j){
            for(int i=1;i<=n;++i){
                uans[i]=max(max(uans[i],uans[i-1]),get(i,j));
            }
            for(int i=n;i>=1;--i){
                dans[i]=max(max(dans[i],dans[i+1]),get(i,j));
            }
            /* for(int i=1;i<=n;++i){
                cout<<i<<" "<<j<<" "<<uans[i]<<" "<<dans[i]<<endl;
            } */
            for(int i=1;i<=n;++i){
                ans=max(ans,rans[j+k]+get(i,j)+lans[j-k]);
                // cout<<i<<" "<<j<<" "<<ans<<endl;
                if(i>=k)ans=max(ans,rans[j+k]+get(i,j)+uans[i-k]);
                // cout<<i<<" "<<j<<" "<<ans<<endl;
                if(i+k<=n)ans=max(ans,rans[j+k]+get(i,j)+dans[i+k]);
                // cout<<i<<" "<<j<<" "<<ans<<endl;
            }
        }
        if(callback)callback();
    };

    auto spin=[&](){
        for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)tmp[i][j]=a[i][j];
        for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
            a[m+1-j][i]=tmp[i][j];
        }
        swap(n,m);
    };

    meow(spin);
    // cout<<ans<<endl;
    meow(spin);
    // cout<<ans<<endl;
    meow(spin);
    // cout<<ans<<endl;
    meow(0);
    cout<<ans<<endl;
}
