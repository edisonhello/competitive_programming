#include<bits/stdc++.h>
using namespace std;

struct node{
    node *l,*r;
    int v;
    node():l(0),r(0),v(1){}
} *root;

int m;

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
}

void modify(node *now,int l,int r,int x,int v){
    if(l==r){
        ++now->v;
        return;
    }
    if(x<=mid)modify(now->l,l,mid,x,v);
    else modify(now->r,mid+1,r,x,v);
    now->v=(1ll*now->l->v*now->r->v)%m;
}

struct fish{
    int mxlen,cnt,type;
} a[500005];
vector<int> len[500005];

int main(){
    int n,k; cin>>n>>k>>m;
    build(root=new node(),1,k);
    for(int i=1;i<=k;++i)a[i].type=i;
    while(n--){
        int l,t; cin>>l>>t;
        ++a[t].cnt;
        a[t].mxlen=max(a[t].mxlen,l);
        len[t].push_back(l);
    }
    for(int i=1;i<=k;++i)sort(len[i].begin(),len[i].end());
    sort(a+1,a+k+1,[](const fish &a,const fish &b){ return a.mxlen<b.mxlen; });
    int ptr=1;
    int ans=0;
    multiset<pair<int,int>> san;
    for(int i=1;i<=k;++i){
        /* while(ptr<i && a[ptr].mxlen<=a[i].mxlen/2){
            now=1ll*now*(a[ptr].cnt+1)%m;
            ++ptr;
        } */
        while(san.size() && san.begin()->first<=a[i].mxlen/2){
            modify(root,1,k,san.begin()->second,1);
            san.erase(san.begin());
        }
        int mymax=upper_bound(len[a[i].type].begin(),len[a[i].type].end(),a[i].mxlen/2)-len[a[i].type].begin();
        ans=(ans+1ll*(root->v)*(mymax+1)%m)%m;
        // cout<<i<<" "<<ptr<<" "<<ans<<" "<<mymax<<endl;
        for(int l:len[a[i].type]){
            san.insert(pair<int,int>(l,a[i].type));
        }
    // }
    cout<<ans<<endl;
}
// after 0
