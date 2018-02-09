#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll val[101234];
int nxt[101234],prv[101234],front=0,back;

int main(){
    int m; cin>>m;
    for(int i=0;i<m;++i)cin>>val[i],nxt[i]=i+1,prv[i]=i-1;
    nxt[m-1]=-1; back=m-1;
    // cout<<"new array: ";
    // for(int i=0;i<m;++i)cout<<b[i]<<" "; cout<<endl;
    ll ans=0;
    int use=m;
    while(m>2){
        int firstk=front;
        while(nxt[nxt[firstk]]!=-1 && val[firstk]>=val[nxt[nxt[firstk]]]){
            firstk=nxt[firstk];
        }
        // cout<<"firstk: "<<firstk<<endl;
        ll newval=val[firstk]+val[nxt[firstk]];
        if(firstk==front)front=nxt[nxt[firstk]],prv[front]=-1;
        else nxt[prv[firstk]]=nxt[nxt[firstk]];
        if(nxt[firstk]==back)back=prv[firstk],nxt[back]=-1;
        else prv[nxt[nxt[firstk]]]=prv[firstk];
        int insertafter=prv[firstk];
        while(insertafter!=-1 && val[insertafter]<=newval){
            insertafter=prv[insertafter];
        }
        if(insertafter==-1){
            val[use]=newval;
            nxt[use]=front;
            prv[use]=-1;
            prv[front]=use;
            front=use;
            ++use;
        }
        else if(insertafter==back){
            val[use]=newval;
            nxt[use]=-1;
            prv[use]=back;
            nxt[back]=use;
            back=use;
            ++use;
        }
        else{
            val[use]=newval;
            nxt[use]=nxt[insertafter];
            prv[use]=insertafter;
            nxt[insertafter]=use;
            prv[nxt[insertafter]]=insertafter;
            ++use;
        }

        ans+=newval;
        --m;
    }
    cout<<ans+val[front]+val[back]<<endl;
}
