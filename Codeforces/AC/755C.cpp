#include<iostream>
using namespace std;

int djs[10004];bool v[10005];
int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}
void U(int x,int y){x=F(x),y=F(y);djs[x]=y;}

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;++i)djs[i]=i;
    for(int i=1,t;i<=n;++i){
        cin>>t;
        U(i,t);
    }
    for(int i=1;i<=n;++i)++v[F(i)];
    int cnt=0;
    for(int i=1;i<=n;++i)if(v[i])++cnt;
    cout<<cnt<<endl;
}
