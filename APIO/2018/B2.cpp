#include<bits/stdc++.h>
using namespace std;
#define int long long

struct cc{
    int x,y,r,i;
} c[300005];
bool operator<(const cc &a,const cc &b){
    return a.r==b.r?a.i<b.i:a.r>b.r;
}
set<cc> cs;
bitset<300005> del;
int bdel[300005];

struct node{
    node *l,*r;
    vector<int> ccc;
    node():l(0),r(0){};
} *root;

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
}
void insert(node *now,int l,int r,int ml,int mr,int x){
    if(r<ml || mr<l)return;
    if(ml<=l&&r<=mr){
        now->ccc.push_back(x);
        return;
    }
    insert(now->l,l,mid,ml,mr,x);
    insert(now->r,mid+1,r,ml,mr,x);
}
void erase(node *now,int l,int r,int ml,int mr,int x){
    if(r<ml || mr<l)return;
    if(ml<=l&&r<=mr){
        for(int i:now->ccc){
            bdel[i]=x;
        }
        now->ccc.clear();
        return;
    }
    erase(now->l,l,mid,ml,mr,x);
    erase(now->r,mid+1,r,ml,mr,x);
}

int32_t main(){
    int n; cin>>n;
    vector<int> nums;
    for(int i=1;i<=n;++i){
        cin>>c[i].x>>c[i].y>>c[i].r;
        c[i].i=i;
        cs.insert(c[i]);
        nums.push_back(c[i].x+c[i].r);
        nums.push_back(c[i].x-c[i].r);
    }
    sort(nums.begin(),nums.end());
    build(root=new node(),0,nums.size()-1);
    for(int i=1;i<=n;++i){
        int l=lower_bound(nums.begin(),nums.end(),c[i].x-c[i].r)-nums.begin();
        int r=upper_bound(nums.begin(),nums.end(),c[i].x+c[i].r)-nums.begin()-1;
        cout<<l<<" "<<r<<endl;
        insert(root,0,nums.size()-1,l,r,i);
    }
    while(cs.size()){
        int id=cs.begin()->i;
        if(bdel[id]){
            cs.erase(cs.begin());
            continue;
        }
        int l=lower_bound(nums.begin(),nums.end(),c[id].x-c[id].r)-nums.begin();
        int r=upper_bound(nums.begin(),nums.end(),c[id].x+c[id].r)-nums.begin()-1;
        erase(root,0,nums.size()-1,l,r,id);
    }
    for(int i=1;i<=n;++i)cout<<bdel[i]<<" ";
    cout<<endl;
}
