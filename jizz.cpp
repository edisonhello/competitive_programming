#include<iostream>
#include<queue>
using namespace std;

struct eg{
    int s,e,c;
    eg& operator=(const eg &a){this->s=a.s,this->e=a.e,this->c=a.c;}
    bool operator<(const eg &a)const{return this->c<a.c;}
    bool operator>(const eg &a)const{return this->c>a.c;}
};

priority_queue<eg,vector<eg>,greater<eg>> pq;
int n,m,djs[10005];

int F(int x){
    if(djs[x]==x)return x;
    else return djs[x]=F(djs[x]);
}
inline void U(int x,int y){
    x=F(x);y=F(y);
    djs[x]=y;
}
inline bool C(int x,int y){
    return F(x)==F(y);
}

int main(){
    ios_base::sync_with_stdio(0);
    while(cin>>n>>m,n){
    while(pq.size())pq.pop();
    eg tmp;while(m--){
        cin>>tmp.s>>tmp.e>>tmp.c;
        pq.push(tmp);
    }
    for(int i=1;i<=n;++i)djs[i]=i;
    int pwr=0,_;
    for(_=0;_<n-1;++_){
        while(pq.size()){
            if(C(pq.top().s,pq.top().e)){
                pq.pop();
            }
            else break;
        }
        if(pq.empty())break;
        // cout<<pq.top().s<<" "<<pq.top().e<<" "<<pq.top().c<<endl;
        pwr+=pq.top().c;
        U(pq.top().s,pq.top().e);
        pq.pop();
    }
    if(_!=n-1)cout<<"-1\n";
    else cout<<pwr<<endl;
}}
