#include<bits/stdc++.h>
using namespace std;

#define Set set<pair<int,int>,decltype(&cmp)>

bool cmp(const pair<int,int> &a,const pair<int,int> &b){return a.first==b.first?a.second<b.second:a.first>b.first;}

bitset<200009> del;
int a[200009],host[200009],segl[200009],segr[200009],len[200009];

int F(int x){return x==host[x]?x:host[x]=F(host[x]);}
void U(int x,int y){
    x=F(x),y=F(y); if(x==y)return;
    host[y]=x;
    segl[x]=min(segl[x],segl[y]);
    segr[x]=max(segr[x],segr[y]);
    len[x]+=len[y];
}

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],host[i]=i,segl[i]=i,segr[i]=i,len[i]=1; a[n+1]=1000000009;
    for(int i=2;i<=n;++i)if(a[i]==a[i-1])U(i,i-1);
    Set st;
    set poss;
    for(int i=1;i<=n;++i)st.insert({len[i],F(i)}),poss.insert(F(i));
    del[0]=del[n+1]=1;
    int ans=0;
    while(st.size()){
        ++ans;
        auto now=*st.begin(); st.erase(st.begin()); poss.erase(now.second);
    }
}
