#include<bits/stdc++.h>
using namespace std;
#define ld long double

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int size=0;
    ld ans=0,prv=0;
    deque<ld> pq;
    int q; cin>>q; while(q--){
        int c; cin>>c; if(c==1){
            ld x; cin>>x;
            if(prv!=0){
                pq.push_back(prv);
                ans-=prv;
                --size;
            }
            prv=x;
            ans+=x;
            ++size;
            while(pq.size() && pq.front()<ans/size){
                ++size;
                ans+=pq.front();
                pq.pop_front();
            }
        }
        else cout<<fixed<<setprecision(10)<<prv-ans/size<<'\n';
    }
}
