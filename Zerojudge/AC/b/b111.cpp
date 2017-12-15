// copy from TIOJ 1155
#include<cstdio>
#include<queue>
#define ld double
using namespace std;
priority_queue<ld,vector<ld>,greater<ld>> pq;
int main(){
    int n;char c[10];ld ch,tot;
    while(scanf("%d",&n)!=-1){
    while(pq.size())pq.pop();
    ch=tot=0;
    while(n--){
        scanf("%s%lf",c,&ch);
        pq.push(ch);
    }
    while(pq.size()>1){
        ld a=pq.top();pq.pop();
        ld b=pq.top();pq.pop();
        tot+=a+b;
        pq.push(a+b);
    }
    printf("%.2f\n",tot);
}}
