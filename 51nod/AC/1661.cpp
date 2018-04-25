#pragma GCC optimize("O")
#include<bits/stdc++.h>
using namespace std;

long long get(long long a,long long k){
    if(a<=1)return 0;
    if(a%k==1)return get(a/k,k);
    long long r=a%k; if(!r)r=k; --r;
    long long q=(a-1)/k;
    return q*(k-1)+r;
}

long long Find(long long a,long long dis,long long k){
    // cout<<"find "<<a<<" to "<<dis<<" in "<<k<<endl;
    long long grp=(dis-1)/(k-1);
    long long rem=dis%(k-1); if(!rem)rem=k-1;
    long long pos=grp*k+rem+1;
    if(grp*k/k!=grp)return -1;
    long long l=(a-1)/k+1,r=a-1;
    // cout<<"pos , l , r = "<<pos<<" , "<<l<<" , "<<r<<endl;
    if(dis==0)pos=1;
    bool no=0;
    while(pos<l){
        long long prvpos=pos;
        pos=pos*k+1;
        if((pos-1)/k!=prvpos){
            no=1;
            break;
        }
    }
    return (pos<=r && !no)?pos:-1;
}

long long a[100005],rsg[100005];

int main(){
    /* for(int i=0;i<=100;++i){
        cout<<"find "<<i<<" "<<Find(99,i,3)<<endl;
    } */
    // int K=10,N=100;
    /* for(int k=2;k<=K;++k){
        memset(sg,0,sizeof(sg));
        for(int i=2;i<=N;++i){
            set<int> mex;
            for(int j=(i-1)/k+1;j<i;++j)mex.insert(sg[j]);
            int ptr=0;
            while(mex.find(ptr)!=mex.end())++ptr;
            sg[i]=ptr;
        }
        cout<<" ------------------ "<<endl;
        cout<<"k: "<<k<<endl;
        for(int i=1;i<=N;++i){
            cout<<setw(4)<<get(i,k)<<" ";
            if(i%10==0)cout<<endl;
        }
        cout<<endl;
    } */
    int n; long long k,sg=0; cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        sg^=(rsg[i]=get(a[i],k));
    }
    // cout<<"SG value: "<<sg<<endl;
    if(!sg)exit((cout<<"Bob"<<endl,0));
    cout<<"Alice ";
    for(int i=1;i<=n;++i){
        long long pos=Find(a[i],rsg[i]^sg,k);
        if(pos<0)continue;
        cout<<i<<" "<<pos<<endl;
        exit(0);
    }
    while(1);
}
