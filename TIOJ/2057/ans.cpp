#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

int c[10009];

void greedy(int p,int k,int n){
    multiset<pair<int,int>> st;
    for(int i=0;i<p;++i)st.insert({c[i],i+1});
    while(st.size()){
        auto sp=*st.begin(); st.erase(st.begin());
        if(sp.first>=n){
            cout<<sp.second<<" "<<n<<endl;
            sp.first-=n;
            if(sp.first)st.insert(sp);
        }
        else{
            auto ep=*--st.end(); st.erase(--st.end());
            cout<<sp.second<<" "<<sp.first<<" "<<ep.second<<" "<<n-sp.first<<endl;
            ep.first-=n-sp.first;
            if(ep.first)st.insert(ep);
        }
    }
}

void greedy(int n,multiset<pair<int,int>> &st){
    while(st.size()){
        auto sp=*st.begin(); st.erase(st.begin());
        if(sp.first>=n){
            cout<<sp.second+1<<" "<<n<<endl;
            sp.first-=n;
            if(sp.first)st.insert(sp);
        }
        else{
            auto ep=*--st.end(); st.erase(--st.end());
            cout<<sp.second+1<<" "<<sp.first<<" "<<ep.second+1<<" "<<n-sp.first<<endl;
            ep.first-=n-sp.first;
            if(ep.first)st.insert(ep);
        }
    }
}

// bitset<23> aru[23][2210000];
const int __offset=2500000;
bitset<23> trash[5000000];

int main(){
    int p,k,n; cin>>p>>k>>n;
    for(int i=0;i<p;++i)cin>>c[i];
    if(p<=k+1){
        greedy(p,k,n);
        exit(0);
    }
    else{
        /* if(k<=20 && 0){
            for(int i=0;i<(1<<p);++i){
                int sum=0,cnt=0;
                for(int j=0;j<p;++j){
                    if(!(i&(1<<j)))continue;
                    ++cnt; sum+=c[j];
                }
                if(sum==(cnt-1)*n)half_greedy(i,p,n),half_greedy(~i,p,n),exit(0);
            }
            cout<<-1<<endl;
        }
        else{ */
        int p1=p/2;
        for(int i=0;i<(1<<p1);++i){
            int sum=0,cnt=0;
            for(int j=0;j<p1;++j){
                if(!(i&(1<<j)))continue;
                ++cnt; sum+=c[j];
            }
            // aru[cnt][sum]=i;
            trash[sum-cnt*n+n+__offset]=i;
        }
        for(int i=0;i<(1<<(p-p1));++i){
            int sum=0,cnt=0;
            for(int j=0;j<p-p1;++j){
                if(!(i&(1<<j)))continue;
                ++cnt; sum+=c[j+p1];
            }
            // cout<<i<<" "<<cnt<<" "<<sum<<endl;
            if(sum==(cnt-1)*n){
                // cout<<"tree in single "<<i<<" "<<sum<<" "<<cnt<<endl;
                multiset<pair<int,int>> st1,st2;
                for(int j=0;j<p-p1;++j){
                    if(i&(1<<j)){
                        st1.insert({c[j+p1],j+p1});
                    }
                    else{
                        st2.insert({c[j+p1],j+p1});
                    }
                }
                for(int j=0;j<p1;++j)st2.insert({c[j],j});
                greedy(n,st1); greedy(n,st2);
                exit(0);
            }
            if(trash[-sum+n*cnt+__offset].count()){
                multiset<pair<int,int>> st1,st2;
                for(int j=0;j<p1;++j){
                    if(trash[-sum+n*cnt+__offset][j])st1.insert({c[j],j});
                    else st2.insert({c[j],j});
                }
                for(int j=0;j<p-p1;++j){
                    if(i&(1<<j))st1.insert({c[j+p1],j+p1});
                    else st2.insert({c[j+p1],j+p1});
                }
                greedy(n,st1); greedy(n,st2);
                exit(0);
            }
            /* for(int cnt2=1;cnt2<=p1;++cnt2){
                if(aru[cnt2][(cnt+cnt2-1)*n-sum].count()){
                    multiset<pair<int,int>> st1,st2;
                    for(int i=0;i<p1;++i){
                        if(aru[cnt2][(cnt+cnt2-1)*n-sum][i])st1.insert({c[i],i});
                        else st2.insert({c[i],i});
                    }
                    for(int j=0;j<p-p1;++j){
                        if(i&(1<<j))st1.insert({c[j+p1],j+p1});
                        else st2.insert({c[j+p1],j+p1});
                    }
                    greedy(n,st1); greedy(n,st2);
                    exit(0);
                }
            } */
        }
        cout<<-1<<endl;
    }
}
