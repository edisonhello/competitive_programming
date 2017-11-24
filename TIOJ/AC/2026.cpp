#include<bits/stdc++.h>
using namespace std;

#ifdef WEAK
#define readchar getchar
#endif

inline char readchar(){
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

template <class T> void rit(T& a){
    static char p;
    while ((p = readchar()) < '0') ;
    a = p ^ '0';
    while ((p = readchar()) >= '0') a *= 10, a += p ^ '0';
}

vector<pair<int,int>> qs;
int counting[1000006];
int val[10000007],nxt[10000007],prv[10000007];
vector<int> pos[1000006];

struct lili{
    int front,back,point,move,expire,dx;
    lili(){
        front=0,back=-1,point=-1;
        move=1,expire=0,dx=0;
    }
    void push_back(int x){
        val[++back]=x;
        nxt[back-1]=back;
        prv[back]=back-1;
        if(move==1)move=0,++point;
        else ++move;
    }
    void _remove(int pos){
        int nxtpnt=nxt[pos],prvpnt=prv[pos];
        nxt[prvpnt]=nxtpnt;
        prv[nxtpnt]=prvpnt;
    }
    void remove(int x){
        int rpos=pos[x].back(); pos[x].pop_back();
        if(point==rpos)expire=1;
        else if(rpos>point)++dx;
        else --dx;
        _remove(rpos);
        if(dx>1 || (dx==1 && expire))point=prv[point],expire=0,dx=0;
        if(dx<-1 || (dx==-1 && expire))point=nxt[point],expire=0,dx=0;
    }
} operat;

void sort_them(){
    for(auto &i:qs)if(i.first==1)++counting[i.second];
    for(int i=1;i<=1000000;++i)while(counting[i]>0){
        operat.push_back(i);
        --counting[i];
        pos[i].push_back(operat.back);
    }
}

int main(){
    int n; rit(n); qs.resize(n);
    for(int i=0;i<n;++i){
        rit(qs[i].first);
        if(qs[i].first==1)rit(qs[i].second);
    }
    while(qs.back().first!=2)qs.pop_back();
    sort_them();
    reverse(qs.begin(),qs.end());
    stack<int> ans;
    for(auto &i:qs){
        if(i.first==2)ans.push(val[operat.point]);
        else operat.remove(i.second);
    }
    while(ans.size()){
        printf("%d\n",ans.top());
        ans.pop();
    }
}
