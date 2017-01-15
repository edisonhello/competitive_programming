#include<iostream>
using namespace std;
#include<cstring>

int in[100005],djs[100005];
bool fe[100005];

int F(int X){if(djs[X]==X)return X;return djs[X]=F(djs[X]);}
void U(int x,int y){x=F(x),y=F(y);if(x==y)return;djs[x]=y;}

int main(){
    int ts;cin>>ts;while(ts--){
        int n,m;cin>>n>>m;

        memset(fe,0,sizeof(fe));
        memset(in,0,sizeof(in));
        for(int i=1;i<=n;++i)djs[i]=i;

        while(m--){
            int a,b;cin>>a>>b;
            U(a,b);
            in[b]++;
        }
        int cnt=0;
        for(int i=1;i<=n;++i)if(!in[i]){
            ++cnt;
            fe[F(i)]=1;
        }
        for(int i=1;i<=n;++i){
            if(!fe[F(i)]){
                ++cnt;
                fe[F(i)]=1;
            }
        }
        cout<<cnt<<endl;
    }
}
