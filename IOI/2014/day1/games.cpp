#include"game.h"
#include<bits/stdc++.h>
using namespace std;

int n,cnt[5555];
void initialize(int N){
    n=N;
}
int hasEdge(int u,int v){
    if(v<u)swap(u,v);
    ++cnt[v];
    return cnt[v]==v;
}

