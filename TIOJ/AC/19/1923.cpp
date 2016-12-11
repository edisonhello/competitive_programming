#include<iostream>
#include<stack>

using namespace std;

#define ll long long
#define mid (l+r)/2

struct node{
    node *l,*r;
    ll val,tag,mn;
    bool used;
    int mna;
    node(){
        l=r=NULL;
        val=tag=0;mna=-1,mn=(1ll<<58);used=0;
    }
    node(int v){
        l=r=NULL;
        val=v;tag=0;mna=-1,mn=(1ll<<58);used=0;
    }
} *root;
void push(node *now){
    if(now->tag){
        if(now->l)now->l->tag+=now->tag;
        if(now->r)now->r->tag+=now->tag;
        now->val+=now->tag;
        now->tag=0;
    }
}
void pull(node *now){
    if(now->l->used && now->r->used)now->used=1;
    if(now->l->used && now->r->used){
        now->mn=(1ll<<58);
        now->mna=-1;
        return;
    }
    else if(now->l->used){
        now->mn=now->r->mn+now->r->tag;
        now->mna=now->r->mna;
    }
    else if(now->r->used){
        now->mn=now->l->mn+now->l->tag;
        now->mna=now->l->mna;
    }
    else if(now->l->mn+now->l->tag<now->r->mn+now->r->tag){
        now->mn=now->l->mn+now->l->tag;
        now->mna=now->l->mna;
    }
    else{
        now->mn=now->r->mn+now->r->tag;
        now->mna=now->r->mna;
    }
}
int n,d[400005];
ll m[400005];
stack<int> st;

void build(node *now,int l,int r){
    if(l==r){
        now->val=now->mn;
        now->mna=l;
        return;
    }
    now->l=new node();
    now->r=new node();
    build(now->l,l,mid);
    build(now->r,mid+1,r);
    pull(now);
}
void update(node *now,int l,int r,ll val,int ql,int qr){
    if(qr<l || r<ql)return;
    if(ql<=l&&r<=qr){
        now->tag+=val;
        return;
    }
    push(now);
    update(now->l,l,mid,val,ql,qr);
    update(now->r,mid+1,r,val,ql,qr);
    pull(now);
}
void use(node *now,int l,int r,int q){
    if(q<l || r<q)return;
    if(l==q && q==r){
        now->used=1;
        return;
    }
    push(now);
    use(now->l,l,mid,q);
    use(now->r,mid+1,r,q);
    pull(now);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    root=new node();
    build(root,0,n-1);
    for(int i=0;i<n;++i){
        cin>>m[i]>>d[i];
        if(i-d[i]<0){
            update(root,0,n-1,m[i],i-d[i]+n,n-1);
            update(root,0,n-1,m[i],0,i-1);
        }
        else update(root,0,n-1,m[i],i-d[i],i-1);
        if(i+d[i]>=n){
            update(root,0,n-1,m[i],i+1,n-1);
            update(root,0,n-1,m[i],0,i+d[i]-n);
        }
        else update(root,0,n-1,m[i],i+1,i+d[i]);
    }
    for(int i=0;i<n;++i){
        int mna=root->mna;
        st.push(mna);
        use(root,0,n-1,mna);
        if(mna-d[mna]<0){
            update(root,0,n-1,-m[mna],mna-d[mna]+n,n-1);
            update(root,0,n-1,-m[mna],0,mna-1);
        }
        else update(root,0,n-1,-m[mna],mna-d[mna],mna-1);
        if(mna+d[mna]>=n){
            update(root,0,n-1,-m[mna],mna+1,n-1);
            update(root,0,n-1,-m[mna],0,mna+d[mna]-n);
        }
        else update(root,0,n-1,-m[mna],mna+1,mna+d[mna]);
    }
    while(st.size()){
        cout<<st.top()+1<<" ";
        st.pop();
    }
    cout<<endl;
}
