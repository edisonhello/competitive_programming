#include<bits/stdc++.h>
using namespace std;
int n,m;
int djs[10005];

int F(int a){
    if(djs[a]==a)return a;
    else return djs[a] = F(djs[a]);
}
void U(int a,int b){
    a=F(a);
    b=F(b);
    if(b>a)swap(a,b);
    djs[a]=b;
}
void P(){
    cout<<"djs:";for(int i=1;i<=n;i++)cout<<djs[i]<<" ";cout<<endl;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(cin>>n>>m){
        memset(djs,0,sizeof(djs));
        for(int i=1;i<=n;i++)djs[i]=i;
        while(m--){
            int a,b;
            cin>>a>>b;
            U(a,b);
            // P();
        }
        int k;
        cin>>k;
        cout<<F(k)<<'\n';
    }
}
