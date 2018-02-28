#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double

int n,k;
ld h;
struct lms{
    int i,m,v;
} a[100005];
int pos[100005];
inline int put(ld t){
    int ptr=1;
    for(int i=0;i<n;++i){
        // if(n-i+ptr-1<k)return -1;
        if((ld)ptr<=t*a[i].v){
            pos[ptr]=a[i].i;
            ++ptr;
        }
        // if(ptr>k)return k;
    }
    return ptr-1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k>>h;
    for(int i=0;i<n;++i)a[i].i=i+1;
    for(int i=0;i<n;++i)cin>>a[i].m;
    for(int i=0;i<n;++i)cin>>a[i].v;
    sort(a,a+n,[](const lms &a,const lms &b){return a.m==b.m?a.v<b.v:a.m<b.m;});
    ld L=0,R=1e9,A=R;
    int t=90;
    while(t--){
        ld M=(L+R)/2;
        if(put(M)>=k)R=A=M;
        else L=M;
    }
    put(A);
    for(int i=1;i<=k;++i)cout<<pos[i]<<" "; cout<<endl;
}
