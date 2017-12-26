#include<bits/stdc++.h>
using namespace std;
#define end soofii

struct seg{
    seg *prv,*nxt;
    int len,val,idx;
    seg():prv(0),nxt(0),len(1),val(-7122),idx(0){}
} *front,*end;

#define Set set<seg*,decltype(&cmp)>
bool cmp(const seg *a,const seg *b){
    return a->len==b->len?a->idx<b->idx:a->len>b->len;
}

int main(){
    int n; cin>>n;
    front=end=new seg(); cin>>end->val; end->idx=1;
    for(int i=2,t;i<=n;++i){
        cin>>t;
        if(t==end->val)++end->len;
        else{
            seg *nw=new seg();
            nw->val=t;
            nw->idx=i;
            nw->prv=end;
            end->nxt=nw;
            end=nw;
        }
    }
    Set st(cmp);
    for(seg *it=front;it;it=it->nxt){
        st.insert(it);
    }
    int ans=0;
    while(st.size()){
        seg *now=*st.begin(); st.erase(st.begin()); ++ans;
        seg *prv=now->prv,*nxt=now->nxt;
        if(prv)prv->nxt=nxt;
        if(nxt)nxt->prv=prv;
        if(now==front)front=nxt;
        if(now==end)end=front;
        delete now;
        if(prv && nxt && prv->val==nxt->val){
            seg *nw=new seg();
            nw->val=prv->val;
            nw->prv=prv->prv;
            nw->nxt=nxt->nxt;
            nw->len=prv->len+nxt->len;
            nw->idx=prv->idx;
            st.erase(prv);
            st.erase(nxt);
            if(nw->prv)nw->prv->nxt=nw;
            else front=nw;
            if(nw->nxt)nw->nxt->prv=nw;
            else end=nw;
            delete prv;
            delete nxt;
            st.insert(nw);
        }
    }
    cout<<ans<<endl;
}
