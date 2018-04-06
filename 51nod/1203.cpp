#include<bits/stdc++.h>
using namespace std;

struct node{
    node *l,*r;
    set<int> bp;
    node():l(0),r(0){}
} *root,pool[150005];
int __ptr;

const int mod=1000000007;

bitset<50005> np;
vector<int> pm;
void init(){
    for(int i=2;i<50000;++i){
        if(np[i])continue;
        pm.push_back(i);
        for(auto j=1ll*i*i;j<50000;j+=i){
            np[j]=1;
        }
    }
}

int a[50005];
short st[50][17][50005];
int prepw[50][30];

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r){
        int x=a[l];
        for(int i=0;;++i){
            if(pm[i]>230)break;
            int cnt=0;
            while(x%pm[i]==0){
                ++cnt;
                x/=pm[i];
            }
            st[i][0][l]=cnt;
        }
        if(x!=1){
            // now->bp[lower_bound(pm.begin(),pm.end(),x)-pm.begin()]=1;
            now->bp.insert(x);
        }
        return;
    }
    build(now->l=&pool[++__ptr],l,mid);
    build(now->r=&pool[++__ptr],mid+1,r);
    // now->bp=now->l->bp|now->r->bp;
    now->bp=now->l->bp;
    now->bp.insert(now->r->bp.begin(),now->r->bp.end());
}

bitset<5140> bp;
void query(node *now,int l,int r,int ql,int qr){
    if(qr<l || r<ql)return;
    if(ql<=l&&r<=qr){
        for(int i:now->bp)bp[i]=1;
        // bp|=now->bp;
        return;
    }
    query(now->l,l,mid,ql,qr);
    query(now->r,mid+1,r,ql,qr);
}

int main(){
    init();
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>a[i];
    build(root=&pool[++__ptr],1,n);
    for(int z=0;z<50;++z){
        for(int i=1,D=1;D<n;++i,D<<=1){
            for(int j=1;j+D<=n;++j){
                st[z][i][j]=max(st[z][i-1][j],st[z][i-1][j+D]);
            }
        }
    }
    for(int z=0;z<50;++z){
        prepw[z][0]=1;
        for(int i=1;i<30;++i){
            prepw[z][i]=1ll*prepw[z][i-1]*pm[z]%mod;
        }
    }
    while(q--){
        int l,r; cin>>l>>r;
        query(root,1,n,l,r);
        int ans=1;
        int d=r-l+1,j=0;
        while(d)d>>=1,++j; --j;
        // cout<<"j: "<<j<<endl;
        for(int z=0;z<50;++z){
            if(l==r)ans=1ll*ans*prepw[z][st[z][0][l]]%mod;
            else ans=1ll*ans*prepw[z][max(st[z][j][l],st[z][j][r-(1<<j)+1])]%mod;
        }
        for(int pos=bp._Find_first();pos<5140;pos=bp._Find_next(pos)){
            ans=1ll*ans*pm[pos]%mod;
            bp[pos]=0;
        }
        cout<<ans<<'\n';
    }
}

