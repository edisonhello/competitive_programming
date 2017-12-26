#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int> &a,const pair<int,int> &b){return a.first==b.first?a.second>b.second:a.first<b.first;}

bitset<200005> dead;
int a[200005];
int host[200005],l[200005],r[200005],len[200005];
int prv[200005],nxt[200005];
set<pair<int,int>,decltype(&cmp)> st(cmp);

#ifdef WEAK
void print(set<int> st){
    cout<<"[";
    for(int i:st){
        cout<<i<<",";
    } cout<<"]\n";
}
void print(set<pair<int,int>,decltype(&cmp)> st){
    for(pair<int,int> i:st){
        cout<<"("<<i.first<<","<<i.second<<") ";
    } cout<<endl;
}
#else 
#define print(x) ;
#endif

int main(){
    // srand(time(0));
    int n; cin>>n;
    // int n=rand()%30+1; cout<<n<<endl;
    a[0]=-1,a[n+1]=1000000009; dead[0]=dead[n+1]=1;
    for(int i=0;i<=n+1;++i)(i&&i<=n?cin>>a[i],7122:5487),nxt[i]=i+1,prv[i]=i-1;
    // for(int i=1;i<=n;++i)a[i]=rand()%5+1,cout<<a[i]<<" "; cout<<endl;
    for(int i=0;i<=n+1;++i)host[i]=i,l[i]=i,r[i]=i;
    for(int i=1;i<=n;++i)if(a[i]==a[i-1]){
        nxt[host[i-1]]=nxt[host[i]];
        prv[host[i]]=prv[host[i-1]];
        host[i]=host[i-1];
        r[host[i]]=i;
    }
    for(int i=1;i<=n;++i)st.insert({len[host[i]]=r[host[i]]-l[host[i]]+1,host[i]});
    int cnt=0;
    while(st.size()){
        print(st);
        pair<int,int> now=*--st.end(); st.erase(--st.end()); 
        if(dead[host[now.second]])continue;
        dead[host[now.second]]=1;
        ++cnt;
        // int lftseg=l[host[now.second]],rgtseg=r[host[now.second]];
        int lftseg=prv[host[now.second]],rgtseg=nxt[host[now.second]];
        nxt[host[lftseg]]=host[rgtseg]; prv[host[rgtseg]]=host[lftseg];
        // cout<<"lftseg: "<<lftseg<<" , rgtseg: "<<rgtseg<<endl;
        if(a[host[lftseg]]==a[host[rgtseg]] && !dead[host[lftseg]] && !dead[host[rgtseg]]){
            int bigL=l[host[lftseg]],bigR=r[host[rgtseg]],lftlen=len[host[lftseg]],rgtlen=len[host[rgtseg]],nwlen=lftlen+rgtlen,rgtlft=l[host[rgtseg]],oldrhost=host[rgtseg];
            nxt[host[lftseg]]=nxt[host[rgtseg]];
            host[rgtseg]=host[lftseg];
            l[host[lftseg]]=bigL;
            r[host[lftseg]]=bigR;
            len[host[lftseg]]=nwlen;
            st.erase({lftlen,host[lftseg]});
            st.erase({rgtlen,oldrhost});
            // auto it1=st.find({lftlen,host[lftseg]});
            // auto it2=st.find({rgtlen,oldrhost});
            // if(it1==st.end())exit(712201);
            // if(it2==st.end())exit(712202);
            // st.erase(it1);
            // st.erase(it2);
            st.insert({nwlen,host[lftseg]});
        }
    }
    cout<<cnt<<endl;
}
