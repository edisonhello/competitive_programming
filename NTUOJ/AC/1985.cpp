// modify from TIOJ 1921
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define i128 __int128

struct machine{
    int d,p,r,g;
    void in(){cin>>d>>p>>r>>g;}
} a[100005];

struct line{
    int m,y;
    int l,r;
    line(int m=0,int y=0,int l=-5,int r=1000000009):m(m),y(y),l(l),r(r){}
    int get(int x)const{return m*x+y;}
    int useful(line le)const{
        return (int)(get(l)>=le.get(l))+(int)(get(r)>=le.get(r));
    }
};

int magic;
bool operator<(const line &a,const line &b){
    if(magic)return a.m<b.m;
    return a.l<b.l;
}

void addline(set<line> &st,line l){
    magic=1;
    auto it=st.lower_bound(l);
    if(it!=st.end() && it->m==l.m && it->useful(l)==2)return;
    while(it!=st.end() && it->useful(l)==0)it=st.erase(it);
    if(it!=st.end() && it->useful(l)==1){
        int L=it->l,R=it->r;
        while(R>L){
            int M=(L+R+1)>>1;
            if(it->get(M)>=l.get(M))R=M-1;
            else L=M;
        }
        line cp=*it;
        st.erase(it);
        cp.l=L+1;
        if(cp.l<=cp.r)st.insert(cp);
        l.r=L;
    }
    else if(it!=st.end())l.r=it->l-1;
    it=st.lower_bound(l);
    while(it!=st.begin() && prev(it)->useful(l)==0)it=st.erase(prev(it));
    if(it!=st.begin() && prev(it)->useful(l)==1){
        --it;
        int L=it->l,R=it->r;
        while(R>L){
            int M=(L+R)>>1;
            if(it->get(M)>=l.get(M))L=M+1;
            else R=M;
        }
        line cp=*it;
        st.erase(it);
        cp.r=L-1;
        if(cp.l<=cp.r)st.insert(cp);
        l.l=L;
    }
    else if(it!=st.begin())l.l=prev(it)->r+1;
    if(l.l<=l.r)st.insert(l);
}

int getval(set<line> &st,int d){
    magic=0;
    return (--st.upper_bound(line(0,0,d,0)))->get(d);
}

ostream &operator<<(ostream &o,line &l){
    o<<"("<<l.m<<","<<l.y<<",["<<l.l<<","<<l.r<<"])";
    return o;
}
template<typename T>ostream& operator<<(ostream &o,set<T> &st){
    o<<"[";
    for(T i:st)o<<i<<" , ";
    o<<"]";
    return o;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,c,d,z=0; while(cin>>n>>c>>d,n){
        for(int i=0;i<n;++i)a[i].in();
        sort(a,a+n,[](const machine &a,const machine &b){return a.d<b.d;});
        set<line> st;
        st.insert(line(0,c));
        for(int z=0;z<n;++z){
            machine m=a[z];
            int $=getval(st,m.d);
            if($<m.p)continue;
            line nl(m.g,$-m.p+m.r-m.g*(m.d+1));
            addline(st,nl);
            // cout<<"st: "<<st<<endl;
        }
        cout<<"Case "<<(++z)<<": ";
        cout<<getval(st,d+1)<<endl;
    }
}
