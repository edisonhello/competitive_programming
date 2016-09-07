#include<queue>
#include<vector>
#include<stdio.h>
using namespace std;
#define ll long long
#define DE cout<<"de"<<endl;

int n;
ll t,t1,t2,tt;
ll ans;
char c;

inline int rit(){
    tt=0;
    do{
        c=getchar_unlocked();
    }while(c<'0'||c>'9');
    do{
        tt=tt*10+c-'0';
        c=getchar_unlocked();
    }while(c>='0'&&c<='9');
    return tt;
};

priority_queue<ll,vector<ll>, greater<ll> > pq;

int main(){
    n=rit();
    for(i=0;i<n;i++){
        t=rit();
        pq.push(t);
    }
    while(pq.size()>1){
        t1=pq.top();pq.pop();
        t2=pq.top();pq.pop();
        pq.push(t1+t2);
        ans+=t1+t2;
    }
    printf("%lld\n",ans);
}
