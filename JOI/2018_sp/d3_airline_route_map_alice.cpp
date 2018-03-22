#include<bits/stdc++.h>
#include"Alicelib.h"
using namespace std;


void Alice(int n,int m,int *a,int *b){
    int c_more=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<=10;++j){
            if(i&(1<<j))++c_more;
        }
    }
    c_more+=n+n+10;
    // cout<<"full c_more: "<<c_more<<endl;
    int ptr=-1;
    InitG(n+12,m+c_more);
    for(int i=0;i<m;++i){
        MakeG(++ptr,a[i],b[i]);
        // --c_more;
    }
    for(int i=0;i<10;++i){
        for(int j=0;j<n;++j){
            if((1<<i)&j){
                MakeG(++ptr,n+i,j);
                --c_more;
            }
        }
    }
    for(int i=0;i<n;++i){
        MakeG(++ptr,n+10,i);
        MakeG(++ptr,n+11,i);
        c_more-=2;
    }
    for(int i=0;i<9;++i){
        MakeG(++ptr,n+i,n+i+1);
        --c_more;
    }
    MakeG(++ptr,n+10,n);
    --c_more;
    // cout<<"c_more: "<<c_more<<" , ptr: "<<ptr<<endl;
    // assert(c_more==0);
}
