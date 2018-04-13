#include<bits/stdc++.h>
using namespace std;

int a[1000006],pos[1000006],ans[1000006];
void solve(int n){
    for(int i=0;i<n;++i)a[i]=a[i+n]=i+1;
    sort(a,a+n*2);
    int mn=1<<30;
    do{
        memset(pos,0,sizeof(int)*(n+3));
        int nw=0;
        for(int i=0;i<2*n;++i){
            if(pos[a[i]]){
                nw+=(n-a[i])*abs(i+1-pos[a[i]]+a[i]-n);
                // cout<<i<<" "<<a[i]<<" "<<n-a[i]<<" "<<i-pos[a[i]]+a[i]-n<<endl;
            }
            pos[a[i]]=i+1;
        }
        // cout<<"nw: "<<nw<<endl;
        if(nw<mn){
            mn=nw;
            for(int i=0;i<2*n;++i)ans[i]=a[i];
        }
    }while(next_permutation(a,a+2*n));
    cout<<n<<": "<<mn<<": ";
    for(int i=0;i<n*2;++i)cout<<ans[i]<<" ";
    cout<<endl;
}

int main(){
    // int n; cin>>n;
    // for(int i=1;i<8;++i)solve(i);
    int n; cin>>n;
    for(int i=1,p=1;i<n;i+=2,++p){
        a[p]=i;
        a[p+n-i]=i;
    }
    reverse(a+1,a+1+2*n);
    for(int i=2,p=1;i<n;i+=2,++p){
        a[p]=i;
        a[p+n-i]=i;
    }
    for(int i=1;i<=n*2;++i)if(!a[i])a[i]=n;
    for(int i=1;i<=n*2;++i)cout<<a[i]<<" ";
}
