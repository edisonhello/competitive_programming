#include<bits/stdc++.h>
#include"lib1168.h"
using namespace std;

struct node{
    int v,st;
    node(int v,int st){
        this->v=v;
        this->st=st;
    }
    friend bool operator < (const node &l,const node &r){
        return l.v<r.v;
    }
    friend bool operator > (const node &l,const node &r){
        return l.v>r.v;
    }
};

priority_queue<node,vector<node>,greater<node> > pqg;
priority_queue<node,vector<node>,   less<node> > pql;
int sz,cnt;
bool ped[1000006];

inline void chk(){
    if(!sz){
        while(pql.size())pql.pop();
        while(pqg.size())pqg.pop();
    }
    else{
        while(ped[pqg.top().st])pqg.pop();
        while(ped[pql.top().st])pql.pop();
    }
}

void pop_big(){
    chk();
    ped[pql.top().st]=1;
    pql.pop();
    sz--;
}
void pop_small(){
    chk();
    ped[pqg.top().st]=1;
    pqg.pop();
    sz--;
}
void push(int s){
    chk();
    pqg.push({s,cnt});
    pql.push({s,cnt});
    cnt++;
    sz++;
}
int big(){
    chk();
    return pql.top().v;
}
int small(){
    chk();
    return pqg.top().v;
}
