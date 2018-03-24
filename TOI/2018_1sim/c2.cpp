#include<bits/stdc++.h>
using namespace std;
#define lb(x) ((x)&-(x))

const int maxn=500005;

int a[maxn],k,n,nowleaf,ans,ptr;
bool no;

void dfs(int lb,int ub){
    // cout<<"in new"<<endl;
    // cout<<ptr<<" "<<lb<<" "<<ub<<endl;

    if(ptr>n || no){return;}
    ++nowleaf; if(nowleaf==k)++ans;
    int now=ptr; ++ptr;
    if(ptr>n)return;
    if(a[ptr]<lb){no=1; return;}
    if(a[ptr]>ub)return;
    bool subed=0;
    if(a[ptr]<a[now]){
        --nowleaf; subed=1;
        dfs(lb,a[now]);
    }

    // cout<<ptr<<" "<<lb<<" "<<ub<<endl;
    if(ptr>n)return;
    if(a[ptr]<lb){no=1; return;}
    if(a[ptr]>ub)return;
    if(a[ptr]>a[now]){
        if(!subed)--nowleaf;
        dfs(a[now],ub);
    }
    else{no=1; return;}
}

void special(int n){
    for(int i=1;i<n;++i)a[i]=a[i+1]-a[i];
    --n;
    long long ans=0;
    for(int i=1,j;i<=n;i=j){
        for(j=i;j<=n;++j){
            if(1ll*a[i]*a[j]<0)break;
        }
        // cout<<i<<" "<<j<<endl;
        int len=j-i;
        ans+=1ll*len*(len+1)/2;
    }
    cout<<ans+n+1<<endl;
    exit(0);
}

inline int gint(){
    char c; int x=0;
    while((c=getchar()) && (c<'0' || c>'9'));
    do x=x*10+(c&15); while((c=getchar())>='0' && c<='9');
    return x;
}

int main(){
    n=gint(); k=gint();
    for(int i=1;i<=n;++i){
        a[i]=gint();
    }
    // if(k==1)special(n);
    for(int i=1;i<=n;++i){
        nowleaf=0;
        no=0;
        ptr=i;
        dfs(0,1<<30);
    }
    cout<<ans<<endl;

}

