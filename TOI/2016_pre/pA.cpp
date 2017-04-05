#include<iostream>
#include<set>
#include<queue>
#include<map>
#include<sstream>
#include<stack>
#include<utility>
#include<cstring>
#include<assert.h>
#define X first
#define Y second
using namespace std;

int h[500005],cac[50005];
set<int> st;
queue<int> q;
map<int,pair<int,int>> mp;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,c,pt=0,t,i;cin>>n>>c;
    string s;cin.ignore();getline(cin,s);
    stringstream ss(s);
    while(ss>>t)h[pt++]=t;
    if(c==1){
        while(pt>=0 && (int)st.size()<n)st.insert(h[--pt]);
        cin>>t;
        if(st.find(t)!=st.end())cout<<"YES\n";
        else cout<<"NO\n";
    }
    if(c==2){
        for(i=pt-1;i>=0;--i){
            if(st.find(h[i])!=st.end())continue;
            st.insert(h[i]);
            q.push(h[i]);
            if((int)st.size()>=n)break;
        }
        while(q.size()){
            cout<<q.front();q.pop();
            if(q.size())cout<<" ";
        }
        cout<<endl;
    }
    if(c==3){
        memset(cac,-1,sizeof(cac));
        int ptr=0;
        for(i=0;i<pt;++i){
            // cout<<"pss:"<<h[i]<<endl;
            auto mpit=mp.find(h[i]);
            if(mpit!=mp.end()){
                ++(mpit->second.X);
                q.push(h[i]);
            }
            else{
                q.push(h[i]);
                if((int)mp.size()<n){
                    cac[ptr++]=h[i];
                    mp[h[i]]={1,ptr-1};
                }
                else{
                    while(q.size()){
                        auto it=mp.find(q.front());
                        --(it->second.X);
                        if(it->second.X==0){
                            cac[it->second.Y]=h[i];
                            mp[h[i]]={1,it->second.Y};
                            mp.erase(it);
                            break;
                        }
                        q.pop();
                    }
                }
            }
        }
        for(i=0;i<n;++i){
            if(cac[i]==-1)break;
            if(i)cout<<" ";
            cout<<cac[i];
        }
        cout<<endl;
    }
}
