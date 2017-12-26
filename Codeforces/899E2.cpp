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
    for(int i=1;i<=n;++i)cin>>a[i],nxt[i]=i+1,prv[i]=i-1;
    // for(int i=1;i<=n;++i)a[i]=rand()%5+1,cout<<a[i]<<" "; cout<<endl;
    for(int i=1;i<=n;++i)host[i]=i,l[i]=i,r[i]=i;
    for(int i=1;i<=n;++i)if(a[i]==a[i-1]){
        nxt[host[i-1]]=nxt[host[i]];
        prv[host[i]]=prv[host[i-1]];
        host[i]=host[i-1];
        r[host[i]]=i;
    }
    for(int i=1;i<=n;++i)st.insert({len[host[i]]=r[host[i]]-l[host[i]]+1,l[host[i]]});
    int cnt=0;
    while(st.size()){
        print(st);
        ++cnt;
        pair<int,int> now=*--st.end(); st.erase(--st.end()); 
        dead[host[now.second]]=1;
        // int sL=l[host[now.second]],sR=r[host[now.second]];
        int sL=prv[now.second],sR=nxt[now.second];
        nxt[host[sL]]=host[sR]; prv[host[sR]]=host[sL];
        // cout<<"sL: "<<sL<<" , sR: "<<sR<<endl;
        if(a[host[sL]]==a[host[sR]] && !dead[host[sL]] && !dead[host[sR]]){
            int bL=l[host[sL]],bR=r[host[sR]],lL=len[host[sL]],rL=len[host[sR]],nwlen=lL+rL,rl=l[host[sR]];
            nxt[host[sL]]=nxt[host[sR]];
            host[sR]=host[sL];
            l[host[sL]]=bL;
            r[host[sL]]=bR;
            len[host[sL]]=nwlen;
            auto it1=st.find({lL,bL});
            auto it2=st.find({rL,rl});
            // assert(it1!=st.end() && it2!=st.end());
            st.erase(it1);
            st.erase(it2);
            st.insert({nwlen,bL});
        }
    }
    cout<<cnt<<endl;
}
