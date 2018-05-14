#include "koala.h"
#include<bits/stdc++.h>
using namespace std;

int B[111],R[111];
int minValue(int N, int W) {
    B[0]=W-N+1; playRound(B,R);
    // for(int i=0;i<N;++i)cout<<R[i]<<" ";cout<<endl;
    for(int i=0;i<N;++i) if(!R[i])return i;
    return 7122;
}

int cnt[111];
int maxValue(int N, int W) {
    memset(cnt,0,sizeof(cnt));
    int cc=N,cci=N-1;
    for(int r=0;r<15;++r){
        for(int i=0;i<N;++i){
            if(cnt[i]==r)B[i]=W/cc;
            else B[i]=0;
        }
        playRound(B,R);
        for(int i=0;i<N;++i)cout<<R[i]<<" ";cout<<endl;
        cc=0,cci=-1;
        for(int i=0;i<N;++i){
            if(R[i]>1){
                ++cnt[i];
                ++cc, cci=i;
            }
        }
        if(cc==1)return cci;
    }
    return 7122;
}

int greaterValue(int N, int W) {
    while(1);
    // TODO: Implement Subtask 3 solution here.
    // You may leave this function unmodified if you are not attempting this
    // subtask.
    return 0;
}

void allValues(int N, int W, int *P) {
    while(1);
    if (W == 2*N) {
        // TODO: Implement Subtask 4 solution here.
        // You may leave this block unmodified if you are not attempting this
        // subtask.
    } else {
        // TODO: Implement Subtask 5 solution here.
        // You may leave this block unmodified if you are not attempting this
        // subtask.
    }
}
