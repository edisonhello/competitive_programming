#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct meow{int v,i;} a[500009];

int BIT[500009];

inline int lowbit(int x){return x&-x;}
int query(int x,int v=0){
    while(x>0){
        v+=BIT[x];
        x-=lowbit(x);
    } return v;
}
void modify(int x,int v){
    while(x<500006){
        BIT[x]+=v;
        x+=lowbit(x);
    }
}

int main(){
    int n;while(cin>>n,n){
        memset(BIT,0,sizeof(BIT));
        for(int i=0;i<n;++i){
            cin>>a[i].v;
            a[i].i=i;
        }
        sort(a,a+n,[](const meow &a,const meow &b)->bool{return a.v<b.v;});
        ll ans=0;
        for(int i=0;i<n;++i){
            ans+=query(n+1)-query(a[i].i+1);
            modify(a[i].i+1,1);
        }
        cout<<ans<<endl;
    }
}
