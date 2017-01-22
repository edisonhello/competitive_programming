#include<iostream>
#include<cstring>
using namespace std;

int n,N;
int a[(1<<20)];
int lb[(1<<20)],rb[(1<<20)];
int bg[(1<<20)];

inline int lowbit(int x){return x&-x;}
void mod(int *BIT,int k,int pos){
    while(pos<=(1<<20)){
        BIT[pos]+=k;
        pos+=lowbit(pos);
    }
}
int que(int *BIT,int pos){
    int rt=0;
    while(pos){
        rt+=BIT[pos];
        pos-=lowbit(pos);
    }
    return rt;
}
int get(int *BIT,int v){
    int pre=que(BIT,v-1);
    int mx=que(BIT,n);
    // cout<<"mx:"<<mx<<" ,pre:"<<pre;
    if(mx-pre==0)return 999999;
    int dist=pre+((mx-pre-1)>>1)+1; // ?
    // cout<<" ,dist:"<<dist<<endl;
    int L=1,R=N;
    // while(L!=lowbit(L))L-=lowbit(L);
    // while(R!=lowbit(R))R+=lowbit(R);
    while(R>L){
        int M=((L+R)>>1);
        if(que(BIT,M)>=dist){
            R=M;
        }
        else{
            L=M+1;
        }
    }
    return L-1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    N=n;while(N!=lowbit(N))N+=lowbit(N);
    for(int i=0;i<n;++i){cin>>a[i];mod(rb,1,i+1);}
    for(int i=0;i<n;++i){
        mod(rb,-1,a[i]+1);
        int La=get(lb,a[i]+1);
        // cout<<"rb: ";for(int i=1;i<=n;++i)cout<<rb[i]<<" ";cout<<endl;
        int Ra=get(rb,a[i]+1);
        mod(lb, 1,a[i]+1);
        int c=min(La,Ra);
        // cout<<"i="<<i<<" L="<<La<<" R="<<Ra<<" c="<<c<<endl;
        if(c==999999)continue;
        ++bg[c];++bg[a[i]];
    }
    int ans=0;
    for(int i=0;i<n;++i)ans=max(ans,bg[i]);
    cout<<ans<<endl;
}
