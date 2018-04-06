#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;

bitset<50005> inlis;
int a[50005];
int pos[50005],ipos[50005];
int bit[50005];
vector<int> poslist[50005];
ll *BIT[50005];
int BITsize[50005];

void add(int x,int v){
    for(;x<50005;x+=x&-x)bit[x]=max(bit[x],v);
}
int query(int x,int v=0){
    for(;x;x-=x&-x)v=max(v,bit[x]);
    return v;
}

void add(int id,int x,ll v){
    for(;x<BITsize[id];x+=x&-x)BIT[id][x]=(BIT[id][x]+v)%mod;
}
ll Query(int id,int x,ll v=0){
    for(;x;x-=x&-x)v=(v+BIT[id][x])%mod;
    return v;
}

int main(){
    int n; cin>>n;
    vector<int> num;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        num.push_back(a[i]);
    }
    sort(num.begin(),num.end());
    for(int i=1;i<=n;++i){
        a[i]=lower_bound(num.begin(),num.end(),a[i])-num.begin()+1;
    }
    int lislen=0;
    for(int i=1;i<=n;++i){
        int q=query(a[i]-1)+1;
        pos[i]=q;
        add(a[i],q);
        lislen=max(lislen,q);
    }
    reverse(a+1,a+1+n);
    for(int i=1;i<=n;++i)a[i]=50003-a[i];
    memset(bit,0,sizeof(bit));
    for(int i=1;i<=n;++i){
        int q=query(a[i]-1)+1;
        ipos[i]=q;
        add(a[i],q);
    }
    reverse(a+1,a+1+n);
    for(int i=1;i<=n;++i)a[i]=50003-a[i];
    reverse(ipos+1,ipos+1+n);
    for(int i=1;i<=n;++i)if(pos[i]+ipos[i]==lislen+1)inlis[i]=1;
    for(int i=1;i<=n;++i){
        if(inlis[i])poslist[pos[i]].push_back(a[i]);
    }
    for(int i=1;i<=lislen;++i){
        BIT[i]=new ll[BITsize[i]=poslist[i].size()+5];
        for(int j=0;j<BITsize[i];++j)BIT[i][j]=0;
        sort(poslist[i].begin(),poslist[i].end());
    }
    for(int i=1;i<=n;++i){
        if(!inlis[i])continue;
        if(pos[i]==1){
            int pos=lower_bound(poslist[1].begin(),poslist[1].end(),a[i])-poslist[1].begin()+1;
            add(1,pos,1);
        }
        else{
            int uppos=lower_bound(poslist[pos[i]-1].begin(),poslist[pos[i]-1].end(),a[i])-poslist[pos[i]-1].begin();
            ll q=Query(pos[i]-1,uppos);
            int npos=lower_bound(poslist[pos[i]].begin(),poslist[pos[i]].end(),a[i])-poslist[pos[i]].begin()+1;
            add(pos[i],npos,q);
        }
    }
    cout<<Query(lislen,BITsize[lislen]-1)<<endl;
}
