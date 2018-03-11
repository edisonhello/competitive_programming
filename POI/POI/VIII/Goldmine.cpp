#pragma GCC optimize("no-stack-protector")
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#define INT_MAX ((1<<31)-1)
#define mid ((l+r)>>1)

struct star{
    int x,y;
} a[16345];
bool operator<(const star &a,const star &b){return a.x<b.x;}


struct node{
    node *l,*r;
    int val,tag;
    node():l(0),r(0),val(0),tag(0){}
    void pull(){val=max(l?l->val:0,r?r->val:0);}
    void addtag(int x){val+=x, tag+=x;}
    void push(){
        if(!tag)return;
        if(!l)l=new node();
        if(!r)r=new node();
        l->addtag(tag);
        r->addtag(tag);
        tag=0;
    }
} *root;

void modify(node *&now,int l,int r,int ml,int mr,int c){
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
    int n,w,h; cin>>w>>h>>n;
    vector<int> ys;
    for(int i=0;i<n;++i){   
        cin>>a[i].x>>a[i].y;
        ys.push_back(a[i].y);
    }
    sort(ys.begin(),ys.end());
    sort(a,a+n);
    int mx=0;
    for(int L=0,R=0;R<n;++R){
        int LLL=lower_bound(ys.begin(),ys.end(),a[R].y-h)-ys.begin(),RRR=lower_bound(ys.begin(),ys.end(),a[R].y)-ys.begin();
        modify(root,0,ys.size(),LLL,RRR,1);
        while(a[R].x-a[L].x>w){
            LLL=lower_bound(ys.begin(),ys.end(),a[L].y-h)-ys.begin(),RRR=lower_bound(ys.begin(),ys.end(),a[L].y)-ys.begin();
            modify(root,0,ys.size(),LLL,RRR,-1);
            ++L;
        }
        // cout<<L<<" "<<R<<endl;
        mx=max(mx,root->val);
    }
    cout<<mx<<endl;
}
