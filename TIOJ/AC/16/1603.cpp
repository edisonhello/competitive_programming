#include<iostream>
#include<iomanip>
#define U unsigned
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
U int mxa[19][100005],mna[19][100005],h[100005];
int n,m;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>h[i];
        mxa[0][i]=mna[0][i]=h[i];
    }
    for(int d=1,e=1;d<n;d<<=1,++e){
        for(int i=1;i+d<=n;++i){
            mxa[e][i]=max(mxa[e-1][i],mxa[e-1][i+d]);
            mna[e][i]=min(mna[e-1][i],mna[e-1][i+d]);
        }
        // for(int i=1;i<=n;++i)cout<<setw(2)<<mxa[e][i]<<" ";cout<<"d="<<d<<" e="<<e<<endl;
    }
    while(m--){
        int s,e,d;cin>>s>>e;d=e-s+1;
        U int mx=0,mn=(1<<31);
        for(int l=1,t=0;l<=d;l<<=1,++t){
            if(l&d){
                // cout<<"get l="<<l<<" t="<<t<<" s="<<s<<" update!"<<endl;
                mx=max(mx,mxa[t][s]);
                mn=min(mn,mna[t][s]);
                s+=l;
            }
        }
        // cout<<mx<<" "<<mn<<" ";
        cout<<mx-mn<<endl;
    }
}
