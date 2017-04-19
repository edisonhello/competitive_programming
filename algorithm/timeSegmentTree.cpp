// TIOJ 1903
namespace std{
    template<> struct hash<pii>{
        int operator()(const pii &i)const{
            return (i.X<<19)^i.Y;
        }
    };
}

struct node{
    node *l,*r;
    vector<pii> e;
} *root,pool[2000005];
int ptr;

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    now->e.clear();
    if(l==r)return;
    build(now->l=&pool[++ptr],l,mid);
    build(now->r=&pool[++ptr],mid+1,r);
}
void modify(node *now,int l,int r,int ml,int mr,const int &u,const int &v){
    if(r<ml || mr<l)return;
    if(ml<=l&&r<=mr){
        now->e.pb(pii(u,v));
        return;
    }
    modify(now->l,l,mid,ml,mr,u,v);
    modify(now->r,mid+1,r,ml,mr,u,v);
}
int djs[500009],sz[500009],cpn;
stack<pair<int*,int>> his;
int F(int x){return x==djs[x]?x:F(djs[x]);}
inline void U(int x,int y,int &cnt){
    x=F(x),y=F(y);if(x==y)return;
    if(sz[x]<sz[y])swap(x,y);
    his.push(pair<int*,int>(&djs[y],djs[y])); djs[y]=x;
    his.push(pair<int*,int>(&sz[x],sz[x])); sz[x]+=sz[y];
    his.push(pair<int*,int>(&cpn,cpn)); --cpn;
    cnt+=3;
}

void go(node *now,int l,int r){
    int cnt=0;
    for(pii i:now->e)U(i.X,i.Y,cnt);
    if(l==r)if(l)printf("%d\n",cpn);else;
    else{
        go(now->l,l,mid);
        go(now->r,mid+1,r);
    }
    while(cnt--){
        *his.top().X=his.top().Y;
        his.pop();
    }
}

unordered_map<pii,pii> mp;
int main(){
    int ts;rit(ts);while(ts--){
        mp.clear(); while(his.size())his.pop(); ptr=-1;
        int n,m,q;rit(n,m,q);
        while(m--){
            int u,v;rit(u,v);if(u>v)swap(u,v);
            auto &p=mp[pii(u,v)];
            if(p==pii(0,0))p=pii(0,1);
            else ++p.Y;
        }
        build(root=&pool[++ptr],0,q);
        for(int i=1;i<=q;++i){
            char c=getchar();int u,v;rit(u,v);if(u>v)swap(u,v);
            if(c=='N'){
                auto &p=mp[pii(u,v)];
                if(p==pii(0,0))p=pii(i,1);
                else ++p.Y;
            }
            else{
                auto &p=mp[pii(u,v)]; --p.Y;
                if(p.Y==0){
                    modify(root,0,q,p.X,i-1,u,v);
                    p=pii(0,0);
                }
            }
        }
        for(auto it=mp.begin();it!=mp.end();++it){
            if(it->Y.Y)modify(root,0,q,it->Y.X,q,it->X.X,it->X.Y);
        }
        for(int i=0;i<=n;++i)djs[i]=i,sz[i]=1; cpn=n;
        go(root,0,q);
    }
}
