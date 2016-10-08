#include<bits/stdc++.h>
using namespace std;
#define m (l+r)/2
int n,w;
int a[1005];
int SgMx;

bool chk(int t){
    int used=0;
    int noww=0;
    for(int i=0;i<n;++i){
        if(noww+a[i]>t){
            ++used;
            noww=a[i];
            if(used>w){
                return 0;
            }
        }
        else{
            noww+=a[i];
        }
    }
    return 1;
}

int BS(int l,int r){
    bool res=chk(m);
    if(l==r){
        if(res){
            return l;
        }
        else{
            assert(1==0);
        }
    }
    if(l==r-1){
        if(res){
            return l;
        }
        else{
            return r;
        }
    }
    if(res) return BS(l,m);
    else return BS(m,r);
}

int main(){
    ios_base::sync_with_stdio(0);
    while(cin>>n>>w && n){
        int tot=0;
        SgMx=0;
        for(int i=0;i<n;++i){
            cin>>a[i];
            tot+=a[i];
            SgMx=max(SgMx,a[i]);
        }
        cout<<BS(SgMx,tot)<<'\n';
    }
}
