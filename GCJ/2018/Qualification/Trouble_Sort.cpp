#include<bits/stdc++.h>
using namespace std;

int a[100005],na[100005],nb[100005],b[100005];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ts,ks=0; cin>>ts; while(ts--){
        int n; cin>>n; 
        int pna=0,pnb=0;
        for(int i=0;i<n;++i){
            cin>>a[i];
            b[i]=a[i];
            if(i&1)na[pna]=a[i],++pna;
            else nb[pnb]=a[i],++pnb;
        }
        sort(na,na+pna);
        sort(nb,nb+pnb);
        sort(b,b+n);
        pna=pnb=0;
        for(int i=0;i<n;++i){
            if(i&1)a[i]=na[pna],++pna;
            else a[i]=nb[pnb],++pnb;
        }
        int err=-1;
        for(int i=0;i<n;++i){
            if(a[i]!=b[i]){
                err=i;
                break;
            }
        }
        cout<<"Case #"<<(++ks)<<": ";
        if(err==-1)cout<<"OK"<<endl;
        else cout<<err<<endl;
    }
}
