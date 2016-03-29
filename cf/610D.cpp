#include<bits/stdc++.h>

using namespace std;

const int BIG = 100000000;
const int MID = 100000000;
const int SML =-100000000;

#define ull unsigned long long
#define ll long long
#define mid (l+r)/2


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

struct node_2{
    ull val,mx;
    node_2 *_lc, *_rc;
    ull l,r;

    node_2(){val = l = r = 0; _lc = _rc = NULL;}
};

struct node{
    ull val,mx;
    node *lc, *rc;
    ull l,r;

    node_2 *_lc, *_rc;

    node(){val = l = r = 0; lc = rc = NULL; _lc = _rc = NULL;}
} *root;

struct area{
    ll x1,y1,x2,y2;
    void swapx(){
        int t=x1;
        x1=x2;
        x2=t;
        return;
    }
    void swapy(){
        int t=y1;
        y1=y2;
        y2=t;
        return;
    }
};

void pull(node *now){
    now->mx = now->lc->mx + now->rc->mx;
    now->val= now->lc->val+ now->rc->val;
    return ;
}

void pull2(node_2 *now){
    now->mx = now->_lc->mx + now->_rc->mx;
    now->val= now->_lc->val+ now->_rc->val;
    return ;
}

void pull12(node *now){
    now->val = now->_lc->val + now->_rc->val;
    return ;
}

void paint2(area in,int l,int r,node_2 *now){
        /*debug*///printf("painting 2d %d %d %d %d\n",in.y1,in.y2,l,r);
    if(in.y2<l || in.y1>r){     /*debug*///printf("out\n");
        return ;
    }
    if(in.y1<=l&&r<=in.y2){     /*debug*///printf("all in\n");
        now->mx = in.y2-in.y1+1;
        now->val = now->mx;
        now->l = l;
        now->r = r;
        return;
    }                           /*debug*///printf("split\n");
    if(now->_lc == NULL) now->_lc = new node_2();
    if(now->_rc == NULL) now->_rc = new node_2();
    paint2(in,l,mid,now->_lc);
    paint2(in,mid+1,r,now->_rc);
                                    /*debug*///printf("pulling back 2d\n");
    pull2(now);                     /*debug*///printf("pulled back %d %d(dem2)%d %d,val=%d\n",l,r,in.y1,in.y2,now->val);
}

void paint(area in,int l,int r,node *now){
        /*debug*///printf("in paint %d %d %d %d\n",in.x1,in.x2,l,r);
    if(in.x2<l || in.x1>r){     /*debug*///printf("out\n");
        return;
    }
    if(in.x1<=l&&r<=in.x2){        /*debug*///printf("all in\n");
        now->mx = (in.x2-in.x1+1)*2*BIG;
        if(now->_lc == NULL) now->_lc = new node_2();
        if(now->_rc == NULL) now->_rc = new node_2();
                                    /*debug*///printf("go paint2d\n");
        paint2(in,SML,0,now->_lc);
        paint2(in,1,BIG,now->_rc);
        now->l = l;
        now->r = r;                 /*debug*///printf("pull back () %d %d\n",l,r);
        pull12(now);                /*debug*///printf("pulled back () val=%d\n",l,r,now->val);
        return;
    }                               /*debug*///printf("split\n");
    if(now->lc == NULL) now->lc = new node();
    if(now->rc == NULL) now->rc = new node();

    paint(in,l,mid,now->lc);
    paint(in,mid+1,r,now->rc);
                                    /*debug*///printf("pulling back %d %d\n",l,r);
    pull(now);                      /*debug*///printf("pulled back %d %d(dem1)%d %d, val=%d\n",l,r,in.x1,in.x2,now->val);
}

int main(){
    root = new node();

    int n=rit();
    for(int i=0;i<n;i++){
        area tmp;
        tmp.x1=rit();
        tmp.y1=rit();
        tmp.x2=rit();
        tmp.y2=rit();
/*
        tmp.x1=(ull)(x1+MID);
        tmp.x2=(ull)(x2+MID);
        tmp.y1=(ull)(y1+MID);
        tmp.y2=(ull)(y2+MID);
*/
        if(tmp.x1>tmp.x2){tmp.swapx();}
        if(tmp.y1>tmp.y2){tmp.swapy();}
                /*debug*///printf("rec pnt,go pnt %d %d %d %d\n",tmp.x1,tmp.y1,tmp.x2,tmp.y2);
        paint(tmp,SML,BIG,root);
    }

    /*system*/printf("%I64d\n",root->val);
}
