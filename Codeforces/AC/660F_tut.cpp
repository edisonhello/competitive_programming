#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define f128 __float128

int n,magic;
ll a[200005];
f128 pre[200005],ipre[200005],dp[200005];

struct line{
    f128 m,y,l,r;
    f128 get(f128 x)const{return m*x+y;}
};
bool operator<(const line &a,const line &b){
    if(magic)return a.m<b.m;
    else return a.l<b.l;
}

ld inter(line l1,line l2){
    return (f128)(l2.y-l1.y)/(l1.m-l2.m);
}

/* void print(set<line> st){
    for(auto i:st){
        cout<<"("<<i.m<<" "<<i.y<<" "<<i.l<<" "<<i.r<<")"<<endl;
    }
} */

int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
        ipre[i]=ipre[i-1]+a[i]*i;
    }
    set<line> st;
    st.insert({0,0,-1000000000000000000ll,1000000000000000000ll});
    f128 ans=0;
    for(int i=1;i<=n;++i){
        // cout<<"i: "<<i<<endl;
        magic=0;
        auto it=st.upper_bound({7122,5487,pre[i],20180210}); 
        // cout<<"it=begin "<<(it==st.begin())<<endl;
        if(it==st.begin())exit(7122);
        --it;
        ans=max(ans,dp[i]=it->get(pre[i])+ipre[i]);
        // print(st);
        // cout<<"size of st is "<<st.size()<<endl;
        // cout<<"dp["<<i<<"]: "<<dp[i]<<endl;
        magic=1;
        line nline={-i,-ipre[i]+i*pre[i],-1000000000000000000ll,1000000000000000000ll};
        it=st.lower_bound(nline);
        while(it!=st.end()){
            if(it==--st.end())break;
            else{
                if(it==st.end())exit(7123);
                f128 nowl=it->l,nowr=it->r;
                
                if(it->get(nowl)<=nline.get(nowl) && it->get(nowr)<=nline.get(nowr)){
                    it=st.erase(it);
                }
                else break;
            }
        }
        it=st.upper_bound(nline); if(it!=st.begin()){
            exit(7124);
            --it; while(it!=st.begin()){
                f128 nowl=it->l,nowr=it->r;
                if(it->get(nowl)<=nline.get(nowl) && it->get(nowr)<=nline.get(nowr)){
                    it=st.erase(it);
                    --it;
                }
                else break;
            }
        }
        auto rlineit=st.upper_bound(nline),llineit=rlineit; --llineit;
        bool insecond=(rlineit!=st.begin());
        // auto rlineit=st.begin();
        if(rlineit!=st.end()){
            line rline=*rlineit; st.erase(rlineit);
            f128 rinter=floor(inter(rline,nline));
            nline.r=rinter; rline.l=rinter+1;
            st.insert(rline);
        }
        if(insecond){
            exit(7125);
            line lline=*llineit; st.erase(llineit);
            f128 linter=ceil(inter(lline,nline));
            nline.l=linter; lline.r=linter-1;
            st.insert(lline);
        }
        st.insert(nline);
    }
    cout<<(ll)ans<<endl;

}
// since the slope is always decreasing,
// we don't have to update new line's l and trying to use it to erase other lines left of it.
