#include<bits/stdc++.h>     //想法はない
using namespace std;
inline int rit(){
int jizz;scanf("%d",&jizz);return jizz;
}
inline char rch(){
char jizz;scanf("%c",&jizz);return jizz;
}
struct treap{
    treap *l, *r;
    int pri,key,val,mx;
    treap(){}
    treap(int _key,int _val){
        l = r = NULL;
        pri = rand();
        key = _key;
        val = _val;
        mx  = val;
    }
};




int n,*a,q;
int main(){
    n=rit();
    a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=rit();
    }

    build

    q=rit();
    for(int i=0;i<q;i++){
        char com=rch();
        if(com=='I'){
            int x=rit(),y=rit();
        }
    }
}
