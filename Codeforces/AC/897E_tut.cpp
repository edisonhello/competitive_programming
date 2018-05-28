#include<bits/stdc++.h>
using namespace std;
#define int long long

int seed;
inline int rnd(){
    int rt=seed;
    seed=(7ll*seed+13)%1000000007;
    return rt;
}

struct seg{
    int l,r,val;
    bool operator<(const seg &r)const{
        return l<r.l;
    }
};
set<seg> st;

int pw(int b,int n,int m,int a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

int32_t main(){
    int n,m,V; cin>>n>>m>>seed>>V;
    for(int i=1;i<=n;++i){
        st.insert({i,i,rnd()%V+1});
    }
    int op,l,r,x,y;
    int lineoutput=0;
    for(int i=1;i<=m;++i){
        op=rnd()%4+1;
        l=rnd()%n+1;
        r=rnd()%n+1;
        if(l>r)swap(l,r);
        if(op==3)x=rnd()%(r-l+1)+1;
        else x=rnd()%V+1;
        if(op==4)y=rnd()%V+1;

        // cout<<op<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<endl;

        if(op==1){
            while(l<=r){
                auto it=st.upper_bound(seg{l,l,0}); --it;
                auto tk=*it; st.erase(it);
                if(tk.l<l){
                    auto ano=tk;
                    ano.r=l-1;
                    st.insert(ano);
                    tk.l=l;
                }
                if(tk.r>r){
                    auto ano=tk;
                    ano.l=r+1;
                    st.insert(ano);
                    tk.r=r;
                }
                tk.val+=x;
                st.insert(tk);
                l=tk.r+1;
            }
        }
        else if(op==2){
            int zzl=l;
            while(l<=r){
                auto it=st.upper_bound(seg{l,l,0}); --it;
                auto tk=*it; st.erase(it);
                if(tk.l<l){
                    auto ano=tk;
                    ano.r=l-1;
                    st.insert(ano);
                    tk.l=l;
                }
                if(tk.r>r){
                    auto ano=tk;
                    ano.l=r+1;
                    st.insert(ano);
                    tk.r=r;
                }
                l=tk.r+1;
            }
            st.insert(seg{zzl,r,x});
        }
        else if(op==3){
            multiset<pair<int,int>> stt;
            while(l<=r){
                auto it=st.upper_bound(seg{l,l,0}); --it;
                auto tk=*it; st.erase(it);
                if(tk.l<l){
                    auto ano=tk;
                    ano.r=l-1;
                    st.insert(ano);
                    tk.l=l;
                }
                if(tk.r>r){
                    auto ano=tk;
                    ano.l=r+1;
                    st.insert(ano);
                    tk.r=r;
                }
                st.insert(tk);
                stt.insert(pair<int,int>(tk.val,tk.r-tk.l+1));
                l=tk.r+1;
            }
            int lay=0;
            for(pair<int,int> p:stt){
                if(lay+p.second>=x){
                    cout<<p.first<<'\n';
                    break;
                }
                else lay+=p.second;
            }
            ++lineoutput;
            /* if(lineoutput==306)cout<<"type 3"<<endl;
            if(lineoutput==306){
                cout<<"x: "<<x<<endl;
                for(auto p:stt)cout<<"["<<p.first<<","<<p.second<<"] ";
                cout<<endl;
            } */
        }
        else{
            int out=0;
            while(l<=r){
                auto it=st.upper_bound(seg{l,l,0}); --it;
                auto tk=*it; st.erase(it);
                if(tk.l<l){
                    auto ano=tk;
                    ano.r=l-1;
                    st.insert(ano);
                    tk.l=l;
                }
                if(tk.r>r){
                    auto ano=tk;
                    ano.l=r+1;
                    st.insert(ano);
                    tk.r=r;
                }
                st.insert(tk);
                out+=(tk.r-tk.l+1)*pw(tk.val%y,x,y)%y;
                l=tk.r+1;
            }
            cout<<out%y<<'\n';
            ++lineoutput;
            // if(lineoutput==306)cout<<"type 4"<<endl;
        }
    }
}
