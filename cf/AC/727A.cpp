#include<iostream>
#define ll long long
using namespace std;

ll a,b,ans[50];


int dfs(ll now,int dep){
    if(now>b)return 0;
    if(now==b)return dep;
    ans[dep]=now;
    int _d=dfs(now<<1,dep+1);
    if(_d)return _d;
    _d=dfs(now*10+1,dep+1);
    return _d;
}

int main(){
    cin>>a>>b;
    // ans[0]=a;
    int _d=dfs(a,0);
    if(_d){
        cout<<"YES\n"<<_d+1<<endl;
        for(int i=0;i<_d;++i){
            cout<<ans[i]<<" ";
        }
        cout<<b<<endl;
    }
    else cout<<"NO\n";
}
