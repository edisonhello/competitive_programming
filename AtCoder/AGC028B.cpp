#include<bits/stdc++.h>
using namespace std;

int cnt[15];
int a[15];

void go(int n){
    memset(cnt,0,sizeof(cnt));
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    do{
        bitset<15> u;
        u[0]=1; u[n+1]=1;
        for(int i:v){
            int ii;
            ii=i-1; while(!u[ii])++cnt[ii],--ii;
            ii=i+1; while(!u[ii])++cnt[ii],++ii;
            ++cnt[i]; u[i]=1;
        }
    }while(next_permutation(v.begin(),v.end()));
    cout<<"cnt: "; for(int i=1;i<=n;++i)cout<<cnt[i]<<" "; cout<<endl;
    cout<<"diff:  "; for(int i=1;i<n;++i)cout<<cnt[i+1]-cnt[i]<<" "; cout<<endl;
}

int main(){
    int n; cin>>n; 
    for(int i=1;i<=10;++i)go(i);
    for(int i=1;i<=n;++i)cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;++i){
        ans+=a[i]*cnt[i];
    }
    cout<<ans<<endl;
}
