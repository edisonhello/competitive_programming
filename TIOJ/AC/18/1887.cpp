#include<bits/stdc++.h>
#define ull unsigned long long
#define db double
#define mid (l+r)/2

using namespace std;

const int MOD = 1000000007;

inline ull rit(){
    ull t=0,k=1;char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c<='9'&&c>='0');
    return t*k;
}
ull n;
vector<ull>x,y;

struct node{
    node *lc,*rc;
    ull orival;
    ull orisum;
    db lgval;
    db lgsum;
    //jizz
    node(){
        lc = rc = NULL;
        orival = orisum = 0;
        lgval = lgsum = 0;
    }
    node(int l,int r){
        if(l==r){
            orisum = x[l];
            lgsum = log(x[l]);
            orival = y[l];
            lgval = log(y[l]);
            return ;
        }cout<<"jizz";
        lc = new node(l,mid);
        rc = new node(mid+1,r);
        //pull
        orisum = lc->orisum*rc->orisum%MOD;
        lgsum = lc->lgsum+rc->lgsum;
        lgval = max(lc->lgval,lc->lgsum+lc->lgval);
        if(lc->lgval > lc->lgsum+lc->lgval){
            lgval = lc->lgval;
            orival = lc->orival;
        }
        else{
            lgval = lc->lgsum+lc->lgval;
            orival = lc->orisum*rc->orival%MOD;
        }
    }
    void updateval(int l,int r,int dis,ull val){
        if(l==r){
            assert(l==dis);
            orival = val;
            lgval = log(val);
            return;
        }
        if(dis<=mid){
            lc->updateval(l,mid,dis,val);
        }
        else if(dis>mid){
            rc->updateval(mid+1,r,dis,val);
        }
        orisum = lc->orisum*rc->orisum%MOD;
        lgsum = lc->lgsum+rc->lgsum;
        lgval = max(lc->lgval,lc->lgsum+lc->lgval);
        if(lc->lgval > lc->lgsum+lc->lgval){
            lgval = lc->lgval;
            orival = lc->orival;
        }
        else{
            lgval = lc->lgsum+lc->lgval;
            orival = lc->orisum*rc->orival%MOD;
        }
    }
    void updatesum(int l,int r,int dis,ull val){
        if(l==r){
            assert(l==dis);
            orisum = val;
            lgsum = log(val);
            return;
        }
        if(dis<=mid){
            lc->updatesum(l,mid,dis,val);
        }
        else if(dis>mid){
            rc->updatesum(mid+1,r,dis,val);
        }
        orisum = lc->orisum*rc->orisum%MOD;
        lgsum = lc->lgsum+rc->lgsum;
        lgval = max(lc->lgval,lc->lgsum+lc->lgval);
        if(lc->lgval > lc->lgsum+lc->lgval){
            lgval = lc->lgval;
            orival = lc->orival;
        }
        else{
            lgval = lc->lgsum+lc->lgval;
            orival = lc->orisum*rc->orival%MOD;
        }
    }
} *root;

using namespace std;
int main(){
    ull t=rit();
    while(t--){
        n=rit();
        x.clear();y.clear();
        x.resize(n);y.resize(n);
        for(int i=0;i<n;i++){
            x[i]=rit();
        }
        for(int i=0;i<n;i++){
            y[i]=rit();
        }

        root = new node(0,n-1);

        printf("%llu\n",root->orival*root->orisum%MOD);

        int m=rit();
        for(int i=0;i<m;i++){
            int k=rit(),p=rit();ull v=rit();
            if(k==1)root->updatesum(0,n-1,p,v);
            else root->updateval(0,n-1,p,v);
            printf("%llu\n",root->orival);
        }




    }
}
