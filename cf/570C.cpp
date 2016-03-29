#include<bits/stdc++.h>
#define mid (l+r)/2
using namespace std;
int m,n,len;
string s;
vector<pair<int,string> >a;

struct node{
    string s;
    int dbdot;
    bool hd,ed;
    node *l,*r;
    node(){
        s="";
        dbdot=0;
        hd=ed=0;
        l=r=NULL;
    }
} *root;

void build(node *now,int l,int r){
    if(l==r){
        now->s = s[l];
        if(now->s=="."){
            now->hd=1;
            now->ed=1;
        }
        return ;
    }

    now->l = new node();
    now->r = new node();
    build(now->l,l,mid);
    build(now->r,mid+1,r);

    now->s = now->l->s + now->r->s;
    now->dbdot = now->l->dbdot + now->r->dbdot;
    if(now->l->ed && now->r->hd)now->dbdot++;
    now->hd = now->l->hd;now->ed = now->r->ed;
}

void update(node *now,int l,int r,int pos,string rep){
        //printf("update l%d r%d want pos%d\n",l,r,pos);
    if(l==r){
        assert(l==pos);
        now->s = rep;
            //printf("l==r %d ",l);
        if(now->s=="."){
                //printf("replace with ");cout<<now->s<<endl;
            now->hd=1;
            now->ed=1;
        }
        else{
                //printf("replace with ");cout<<now->s<<endl;
            now->hd=0;
            now->ed=0;
        }
        return;
    }
    if(pos<=mid){   //printf("call left child\n");
        update(now->l,l,mid,pos,rep);
    }
    else{
        update(now->r,mid+1,r,pos,rep);
    }
    now->s = now->l->s + now->r->s;
    now->dbdot = now->l->dbdot + now->r->dbdot;
    if(now->l->ed && now->r->hd)now->dbdot++;
    now->hd = now->l->hd;now->ed = now->r->ed;
}

int main(){
    cin>>n>>m;
    cin>>s;
    len=s.length();

    root = new node();
    build(root,0,len-1);

    for(int i=0;i<m;i++){
        int p;cin>>p;
        string c;cin>>c;
        a.push_back(make_pair(p,c));
        /*update(root,0,n-1,p-1,c);
        cout<<root->dbdot<<endl;*/
    }
    int i,j;
    sort(a.begin(),a.end());
    for(i=0;i<a.size();i=j){
        for(j=i+1;a[j].first==a[i].first;j++){}
        update(root,0,n-1,a[j-1].first,a[j-1].second);
        cout<<
    }
}
