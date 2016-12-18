#include<cstdio>
#include<queue>
#define getchar getchar_unlocked
using namespace std;

inline void clr(),init();

struct node{
    node *l,*r;
    int val;
    node(){
        l=r=NULL;
        val=0;
    }
    node(int v){
        l=r=NULL;
        val=v;
    }
};
node *lst[2000006],*fnt,*ed;
int n,m,a1;
queue<int> ans;

inline int rit(){
    int r=0;char c;
    do{
        c=getchar();
    }while(c<'0'||c>'9');
    do{
        r=r*10+c-'0';
        c=getchar();
    }while(c<='9'&&c>='0');
    return r;
}

inline void solve(){
    long long trash=0;
    {int k,a,b,c;while(m--){
        k=rit(),a=rit(),b=rit(),c=rit();
        if(k==1){
            if(c==1){
                //cout<<"insert "<<a<<" before "<<b<<'\n';
                node *now=new node(a);
                node *base=lst[b];
                base->l->r=now;
                now->l=base->l;
                now->r=base;
                base->l=now;
                lst[a]=now;
            }
            else if(c==2){
                //cout<<"insert "<<a<<" after "<<b<<'\n';
                node *now=new node(a);
                node *base=lst[b];
                base->r->l=now;
                now->r=base->r;
                now->l=base;
                base->r=now;
                lst[a]=now;
            }
        }
        else if(k==2){
            node *cutHead=lst[a],
                 *cutEnd=lst[b],
                 *base=lst[c];
            //cout<<"move from "<<a<<" to "<<b<<" before "<<c<<'\n';
            cutHead->l->r=cutEnd->r;
            cutEnd->r->l=cutHead->l;
            cutHead->l=base->l;
            base->l->r=cutHead;
            base->l=cutEnd;
            cutEnd->r=base;
        }
        else if(k==3){
            if(c==1){
                //cout<<"give "<<b<<" things from "<<a<<" and go L"<<'\n';
                node *now=lst[a];
                node *base=now;
                while(now->val!=-1&&b>0){
                    ans.push(now->val);
                    --b;now=now->l;
                }
                if(b>0){trash+=b;}
                base->r->l=now;
                now->r=base->r;
            }
            else if(c==2){
                //cout<<"give "<<b<<" things from "<<a<<" and go R"<<'\n';
                node *now=lst[a];
                node *base=now;
                while(now->val!=-1&&b>0){
                    ans.push(now->val);
                    --b;now=now->r;
                }
                if(b>0){trash+=b;}
                base->l->r=now;
                now->l=base->l;
            }
        }
    }}
    printf("%lld\n",trash);
    if((int)ans.size()!=n)while(1){}
    while(ans.size()){
        printf("%d\n",ans.front());ans.pop();
    }
}

int main(){
    int ts;ts=rit();while(ts--){
        n=rit(),m=rit(),a1=rit();
        init();
        solve();
        if(ts)clr();
    }
}
inline void clr(){
    while(ans.size())ans.pop();
    for(int i=0;i<2000006;++i){
        delete lst[i];
        lst[i]=NULL;
    }
}
inline void init(){
    lst[a1]=new node(a1);
    lst[a1]->l=new node(-1);fnt=lst[a1]->l;
    lst[a1]->r=new node(-1);ed=lst[a1]->r;
}
