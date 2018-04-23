#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a%m;
}

struct meow{
    int l,r,v;
};
bool operator<(const meow &a,const meow &b){return tie(a.l,a.r,a.v)<tie(b.l,b.r,b.v);}

int a[100005];

int32_t main(){
    int n,m; ll seed,vmax; cin>>n>>m>>seed>>vmax;
    auto rand=[&](){int rt=seed; seed=(seed*7+13)%1000000007; return rt;};
    for(int i=1;i<=n;++i)a[i]=rand()%vmax+1;
    set<meow> st;
    for(int i=1,j;i<=n;i=j){
        for(j=i+1;j<=n && a[j]==a[i];++j);
        st.insert({i,j-1,a[i]});
    }
    for(int i=1;i<=m;++i){
        int op=rand()%4+1;
        int l=rand()%n+1,r=rand()%n+1;
        if(l>r)swap(l,r);
        // cout<<"op: "<<op<<" , ["<<l<<" , "<<r<<" ] ";
        if(op==1){
            int x=rand()%vmax+1;
            // cout<<"x: "<<x<<endl;
            while(l<=r){
                auto it=st.upper_bound({l,n+1,0}); --it;
                auto p=*it; st.erase(it);
                if(p.l<l){
                    auto cp=p; cp.r=l-1;
                    st.insert(cp);
                    p.l=l;
                }
                if(p.r>r){
                    auto cp=p; cp.l=r+1;
                    st.insert(cp);
                    p.r=r;
                }
                p.v+=x;
                st.insert(p);
                l=p.r+1;
            }
        }
        else if(op==2){
            int x=rand()%vmax+1;
            // cout<<"x: "<<x<<endl;
            int L=l;
            while(l<=r){
                auto it=st.upper_bound({l,n+1,0}); --it;
                auto p=*it; st.erase(it);
                if(p.l<l){
                    auto cp=p; cp.r=l-1;
                    st.insert(cp);
                    p.l=l;
                }
                if(p.r>r){
                    auto cp=p; cp.l=r+1;
                    st.insert(cp);
                    p.r=r;
                }
                l=p.r+1;
            }
            st.insert({L,r,x});
        }
        else if(op==3){
            int x=rand()%(r-l+1)+1;
            // cout<<"x: "<<x<<endl;
            auto it=st.upper_bound({l,n+1,0}); --it;
            set<pair<int,int>> nums;
            while(it!=st.end() && it->l<=r){
                int len=min(it->r,r)-max(it->l,l)+1;
                nums.insert({it->v,len});
                ++it;
            }
            for(auto i:nums){
                x-=i.second;
                if(x<=0){
                    cout<<i.first<<'\n';
                    break;
                }
            }
        }
        else if(op==4){
            int x=rand()%vmax+1;
            int y=rand()%vmax+1;
            // cout<<"x: "<<x<<" , y: "<<y<<endl;
            auto it=st.upper_bound({l,n+1,0}); --it;
            ll ans=0;
            while(it!=st.end() && it->l<=r){
                int len=min(it->r,r)-max(it->l,l)+1;
                ans+=pw(it->v%y,x,y)*len%y;
                ++it;
            }
            cout<<ans%y<<'\n';
        }
        /* for(auto i:st){
            cout<<"["<<i.l<<","<<i.r<<"]: "<<i.v<<" , ";
        } */
        // cout<<endl<<endl;
    }
}
