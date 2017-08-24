#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct V{ll v,n;};
ll n,k,x,t,nk,i,neg,has0,a[200005];
char c;
bool cmp_abs(const V &a,const V &b){
    return abs(a.v)>abs(b.v);
}
priority_queue<V,vector<V>,decltype(&cmp_abs)> pq(&cmp_abs);
inline ll rit(){
    t=0,nk=1;
    do{
        c=getchar();
        if(c=='-')nk=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*nk;
}
int main(){
    n=rit(),k=rit(),x=rit();
    for(i=0;i<n;++i){
        a[i]=rit();
        if(a[i]<0) ++neg;
        pq.push({a[i],i});
    }
    while(k--){
        V tmp=pq.top();pq.pop();
        if(neg&1){
            if(tmp.v>=0){
                pq.push({tmp.v+x,tmp.n});
                a[tmp.n]+=x;
            }
            else{
                pq.push({tmp.v-x,tmp.n});
                a[tmp.n]-=x;
            }
        }
        else{
            if(tmp.v>=0){
                pq.push({tmp.v-x,tmp.n});
                a[tmp.n]-=x;
                if(a[tmp.n]<0)++neg;
            }
            else{
                pq.push({tmp.v+x,tmp.n});
                a[tmp.n]+=x;
                if(a[tmp.n]>=0)--neg;
            }
        }
    }
    for(i=0;i<n;++i){
        if(i)printf(" ");
        printf("%lld",a[i]);
    }
    printf("\n");
}
