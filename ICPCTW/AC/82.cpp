#include<bits/stdc++.h>
using namespace std;

long long p[3005],dp[3005][3005];

struct line{
    long long l,r;
    long long m,y;
    long long get(long long x)const{return m*x+y;}
    int usable(line cmp)const{
        int win=0;
        win+=(get(l)>=cmp.get(l));
        win+=(get(r)>=cmp.get(r));
        return win-1;
    }
    line(long long m=0,long long y=0,long long l=-100005,long long r=100005):l(l),r(r),m(m),y(y){}
};

int magic;
bool operator<(const line &a,const line &b){
    if(magic==0)return a.m<b.m;
    else return a.l<b.l;
}
ostream &operator<<(ostream &ostm,const line &a){
    ostm<<"("<<a.m<<" , "<<a.y<<" ,["<<a.l<<" , "<<a.r<<"])";
    return ostm;
}
template<typename T>ostream &operator<<(ostream &ostm,const set<T> x){
    ostm<<"(";
    for(T i:x)ostm<<i<<" , ";
    ostm<<")";
    return ostm;
}

#ifdef NOT_CODE
if choose j and i
then dp[i]=dp[j-1]+p[j]^2-2*p[j]*p[i]+p[i]^2
set is \_/ convex
#endif

long long getval(set<line> &st,long long x){
    magic=1;
    return (--st.upper_bound(line(0,0,x,0)))->get(x);
}

void addline(set<line> &st,line l){
    magic=0;
    auto it=st.lower_bound(l);
    if(it!=st.end() && it->usable(l)==1)return;
    while(it!=st.end() && it->usable(l)==-1)it=st.erase(it);
    if(it!=st.end() && it->usable(l)==0){
        long long L=it->l,R=it->r,M;
        while(R>L){
            M=(L+R+1)>>1;
            if(it->get(M)>=l.get(M))R=M-1;
            else L=M;
        }
        // cout<<L<<" "<<R<<endl;
        line cp=*it;
        st.erase(it);
        cp.l=L+1;
        if(cp.l<=cp.r)st.insert(cp);
        l.r=L;
    }
    else if(it!=st.end())l.r=it->l-1;
    it=st.lower_bound(l);
    // cout<<st<<" "<<(it==st.end())<<endl;
    while(it!=st.begin() && prev(it)->usable(l)==-1)it=st.erase(prev(it));
    if(it!=st.begin() && prev(it)->usable(l)==0){
        --it;
        long long L=it->l,R=it->r,M;
        while(R>L){
            M=(L+R)>>1;
            if(it->get(M)>=l.get(M))L=M+1;
            else R=M;
        }
        // cout<<L<<" "<<R<<endl;
        line cp=*it;
        st.erase(it);
        cp.r=L-1;
        if(cp.l<=cp.r)st.insert(cp);
        l.l=L;
    }
    else if(it!=st.begin())l.l=prev(it)->r+1;
    st.insert(l);
}

int main(){
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>p[i];
    memset(dp,0xb0,sizeof(dp));
    for(int i=0;i<=n;++i)dp[0][i]=0;
    for(int i=1;i<=k;++i){
        set<line> st;
        st.insert(line(-2*p[i*2-1],p[i*2-1]*p[i*2-1]+dp[i-1][i*2-2]));
        // cout<<st<<endl;
        for(int j=i*2;j<=n;++j){
            dp[i][j]=getval(st,p[j])+p[j]*p[j];
            if(dp[i-1][j-1]>=0)addline(st,line(-2*p[j],p[j]*p[j]+dp[i-1][j-1]));
            // cout<<i<<" "<<j<<" "<<st<<" "<<endl;
        }
        // cout<<endl;
        for(int j=1;j<=n;++j)dp[i][j]=max(dp[i][j],dp[i][j-1]);
    }
    /* for(int i=1;i<=k;++i){
        for(int j=1;j<=n;++j){
            if(dp[i][j]<0)dp[i][j]=-1;
            cout<<setw(3)<<dp[i][j]<<" ";
        }
        cout<<endl;
    } */
    cout<<dp[k][n]<<endl;
}
