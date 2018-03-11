#pragma GCC optimize("no-stack-protector")
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#define INT_MAX ((1<<31)-1)
#define ll long long
#define mid ((l+r)>>1)

struct star{
    int x,y,c;
} a[12345];
bool operator<(const star &a,const star &b){return a.x<b.x;}


struct node{
    node *l,*r;
    ll val,tag;
    node():l(0),r(0),val(0),tag(0){}
    void pull(){val=max(l?l->val:0ll,r?r->val:0ll);}
    void addtag(ll x){val+=x, tag+=x;}
    void push(){
        if(!tag)return;
        if(!l)l=new node();
        if(!r)r=new node();
        l->addtag(tag);
        r->addtag(tag);
        tag=0;
    }
} *root;

void modify(node *&now,ll l,ll r,int ml,int mr,ll c){
    if(r<ml || mr<l)return;
    if(!now)now=new node();
    if(ml<=l&&r<=mr){
        now->addtag(c);
        return;
    }
    now->push();
    modify(now->l,l,mid,ml,mr,c);
    modify(now->r,mid+1,r,ml,mr,c);
    now->pull();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,w,h; while(cin>>n>>w>>h){
        vector<int> ys;
        root=0;
        for(int i=0;i<n;++i){   
            cin>>a[i].x>>a[i].y>>a[i].c;
            ys.push_back(a[i].y);
        }
        sort(ys.begin(),ys.end());
        sort(a,a+n);
        ll mx=0;
        for(int L=0,R=0;R<n;++R){
            int LLL=upper_bound(ys.begin(),ys.end(),a[R].y-h)-ys.begin(),RRR=lower_bound(ys.begin(),ys.end(),a[R].y)-ys.begin();
            modify(root,0,ys.size(),LLL,RRR,a[R].c);
            while(a[R].x-a[L].x>=w){
                LLL=upper_bound(ys.begin(),ys.end(),a[L].y-h)-ys.begin(),RRR=lower_bound(ys.begin(),ys.end(),a[L].y)-ys.begin();
                modify(root,0,ys.size(),LLL,RRR,-a[L].c);
                ++L;
            }
            // cout<<L<<" "<<R<<endl;
            mx=max(mx,root->val);
        }
        cout<<mx<<endl;
    }
}
