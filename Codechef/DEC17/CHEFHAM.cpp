#include<bits/stdc++.h>
using namespace std;

int a[100005],b[100005],ans[100005];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; while(t--){
        int n; cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i],b[i]=a[i];
        int md=-1;
        for(int _=0;_<5;++_){
            b[0]=b[1];
            for(int i=1;i<n;++i)b[i]=b[i+1];
            b[n]=b[0];
            int dst=0;
            for(int i=1;i<=n;++i)dst+=a[i]!=b[i];
            if(dst>md){
                for(int i=1;i<=n;++i)ans[i]=b[i];
                md=dst;
            }
        }
        cout<<md<<endl;
        for(int i=1;i<=n;++i)cout<<ans[i]<<" "; cout<<endl;
    }
}
// AC 300
