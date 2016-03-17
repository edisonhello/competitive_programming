#include<bits/stdc++.h>

using namespace std;



#define ull unsigned long long
#define ll long long
#define midx (((x1+x2)>>1) - 0.5)
#define midy (((y1+y2)>>1) - 0.5)

ll mid(ll x,ll y){
    ll ret;
    ret = (x+y)>>1;
    ///*debug*/printf("%d\n",ret);
    return ret;
}

const ll BIG = 100000000;
const ll SML =-100000000;

inline ll rit(){
    ll t=0,key=1;char c;
    do{
        c=getchar();
        if(c=='-')key=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }
    while(c>='0'&&c<='9');
    return t*key;
}


struct node{
    node *lu,*ru,*ld,*rd;
    ll val;
    node(){
        lu=ru=ld=rd=NULL;
        val=0;
    }
} *root;

void pull(node *now){
    return ;
}

void build(node *now,ll fx1,ll fy1,ll fx2,ll fy2,ll x1,ll y1,ll x2,ll y2){
    /*debug*/printf("now building %d %d %d %d dis(%d %d %d %d) ",x1,x2,y1,y2,fx1,fx2,fy1,fy2);
    if((fx1>x2||fx2<x1)||(fy1>y2||fy2<y1)){     /*debug*/printf("out\n");
        return;
    }
    if((fx1<=x1&&x2<=fx2)&&(fy1<=y1&&y2<=fy2)){ /*debug*/printf("in\n");

        now->val = (x2-x1+1) * (y2-y1+1);
                            printf("add %d %d %d %d val %d\n",x1,x2,y1,y2,now->val);
        return;
    }
    if(now->lu == NULL)now->lu = new node();
    if(now->ld == NULL)now->ld = new node();
    if(now->ru == NULL)now->ru = new node();
    if(now->rd == NULL)now->rd = new node();/*debug*/printf("split\ncase1 ");
    build(now->lu,fx1,fy1,fx2,fy2,          x1,          y1,mid(x1,x2),mid(y1,y2));/*debug*/printf("case2 ");
    build(now->ld,fx1,fy1,fx2,fy2,          x1,mid(y1,y2)+1,mid(x1,x2),       y2);/*debug*/printf("case3 ");
    build(now->ru,fx1,fy1,fx2,fy2,mid(x1,x2)+1,          y1,        x2,mid(y1,y2));/*debug*/printf("case4 ");
    build(now->rd,fx1,fy1,fx2,fy2,mid(x1,x2)+1,mid(y1,y2)+1,        x2,       y2);

    now->val = now->lu->val + now->ru->val + now->ld->val + now->rd->val;
    //pull(now);
}

int main(){
    int n=rit();
    root = new node();
    for(int i=0;i<n;i++){
        ll x1=rit(),y1=rit(),x2=rit(),y2=rit();
        if(x1>x2)swap(x1,x2);
        if(y1>y2)swap(y1,y2);
        build(root,x1,y1,x2,y2,SML,SML,BIG,BIG);
    }
    /*system*/printf("%I64d\n",root->val);
}
