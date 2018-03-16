#include<bits/stdc++.h>
using namespace std;

int mx[240000],tag[240000];

void push(int id){
    if(!tag[id])return;
    tag[id*2]+=tag[id];
    mx[id*2]+=tag[id];
    tag[id*2+1]+=tag[id];
    mx[id*2+1]+=tag[id];
    tag[id]=0;
}
void pull(int id){
    mx[id]=max(mx[id*2],mx[id*2+1]);
}

#define mid ((l+r)>>1)
int query(int id,int l,int r,int ql,int qr){
    if(r<ql || qr<l)return 0;
    if(ql<=l&&r<=qr)return mx[id];
    push(id);
    return max(query(id*2,l,mid,ql,qr),query(id*2+1,mid+1,r,ql,qr));
}
void modify(int id,int l,int r,int ml,int mr,int c){
    if(r<ml || mr<l)return;
    if(ml<=l&&r<=mr){
        mx[id]+=c;
        tag[id]+=c;
        return;
    }
    push(id);
    modify(id*2,l,mid,ml,mr,c);
    modify(id*2+1,mid+1,r,ml,mr,c);
    pull(id);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,s,r; cin>>n>>s>>r;
    while(r--){
        int l,r,c; cin>>l>>r>>c; --r;
        if(query(1,1,n,l,r)+c<=s){
            modify(1,1,n,l,r,c);
            cout<<"T\n";
        }
        else cout<<"N\n";
    }
}
