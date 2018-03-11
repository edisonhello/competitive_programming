#include<bits/stdc++.h>
using namespace std;


struct node{
    node *ch[2];
    int cnt,sz,val;
    int gsz(int x){return ch[!!x]?ch[!!x]->sz:0;}
    void psz(){sz=gsz(0)+gsz(1);}
    node():cnt(0),sz(0){memset(ch,0,sizeof(ch));}
} *root;

void insert(node *&now,int ptr,int num){
    if(!now)now=new node();
    if(ptr<0){
        ++now->cnt;
        ++now->sz;
        now->val=num;
        return;
    }
    insert(now->ch[!!(num&(1<<ptr))],ptr-1,num);
    now->psz();
}

int query(node *now,int ptr,int num){
    if(ptr<0){
        if(!(now->sz>0))exit(7122);
        --now->cnt;
        --now->sz;
        return now->val^num;
    }
    --now->sz;
    if(now->gsz(!!(num&(1<<ptr)))==0)return query(now->ch[!(num&(1<<ptr))],ptr-1,num);
    else return query(now->ch[!!(num&(1<<ptr))],ptr-1,num);
}

int a[300005];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i){
        int t; cin>>t;
        insert(root,30,t);
    }
    for(int i=0;i<n;++i){
        cout<<query(root,30,a[i])<<" ";
    }
    cout<<endl;
}
