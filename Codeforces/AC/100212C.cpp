#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[2004],pre[2004];
ll dp[2004][2004],tp[2004][2004];
vector<char> op;

void go(int l,int r){
    // cout<<"go "<<l<<" "<<r<<endl;
    if(l==r){
        for(char c:op)cout<<c;
        cout<<'\n';
        return;
    }
    int z=tp[l][r];
    // cout<<l<<" "<<r<<" -> "<<z<<endl;
    op.push_back('0');
    go(l,z-1);
    op.back()='1';
    go(z,r);
    op.pop_back();
}

int main(){
    freopen("codes.in","r",stdin);
    freopen("codes.out","w",stdout);

    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
    for(int len=2;len<=n;++len){
        for(int i=1;i<=n;++i){
            int j=i+len-1;
            if(j>n)break;
            if(len==2){
                dp[i][j]=pre[j]-pre[i-1];
                tp[i][j]=j;
            }
            else{
                ll mn=LLONG_MAX;
                int p=-1;
                for(int z=tp[i][j-1];z<=tp[i+1][j];++z){
                    ll nv=pre[j]-pre[i-1]+dp[i][z-1]+dp[z][j];
                    if(nv<mn){
                        mn=nv;
                        p=z;
                    }
                }
                dp[i][j]=mn;
                tp[i][j]=p;
            }
        }
    }
    go(1,n);
}
