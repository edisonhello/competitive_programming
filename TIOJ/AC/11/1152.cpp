#include<bits/stdc++.h>
#define Y second
using namespace std;
vector<int> G[10005];
bitset<10005> v;
int d[10005],n;

int dij0(int st){
    memset(d,0x77,sizeof(d));
    v.reset();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,st});
    d[st]=0;
    int pt=0;
    int lastpoint=-1;
    for(;pt<n;++pt){
        while(pq.size()&&v[pq.top().Y]){
            pq.pop();
        }
        if(pq.empty())break;
        int np=pq.top().Y;
        v[np]=1;
        lastpoint=np;
        // cout<<"dij0 pnt+"<<np<<endl;
        for(int i=0;i<(int)G[np].size();++i){
            if(!v[G[np][i]]&&d[np]+1<d[G[np][i]]){
                d[G[np][i]]=d[np]+1;
                pq.push({d[np]+1,G[np][i]});
            }
        }
    }
    return lastpoint;
}
int dij1(int st){
    memset(d,0x77,sizeof(d));
    v.reset();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,st});
    int pt=0;
    d[st]=0;
    int mxlen=-9;
    for(;pt<n;++pt){
        while(pq.size()&&v[pq.top().Y]){
            pq.pop();
        }
        if(pq.empty())break;
        int np=pq.top().Y;
        v[np]=1;
        mxlen=max(mxlen,d[np]);
        for(int i=0;i<(int)G[np].size();++i){
            if(!v[G[np][i]]&&d[np]+1<d[G[np][i]]){
                d[G[np][i]]=d[np]+1;
                pq.push({d[np]+1,G[np][i]});
            }
        }
    }
    return mxlen;
}

void sol(){
    int farpt=dij0(0);
    // cout<<"farpt: "<<farpt<<endl;
    cout<<dij1(farpt)<<'\n';
}

int main(){
    cin>>n;
    for(int i=0,t;i<n;++i){
        while(cin>>t){
            if(t==-1)break;
            G[i].push_back(t);
            G[t].push_back(i);
        }
    }
    sol();
}
