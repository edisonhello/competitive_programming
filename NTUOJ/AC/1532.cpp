#include<bits/stdc++.h>
using namespace std;

bool change(bitset<10000> &i,bitset<10000> &o){
    int it=i._Find_first(),ot=o._Find_first();
    while(it!=10000 || ot!=10000){
        if(it==10000)return 1;
        if(ot==10000)return 0;
        if(it==ot){
            it=i._Find_next(it);
            ot=o._Find_next(ot);
        }
        else{
            if(it>ot)return 1;
            else return 0;
        }
    }
    return 0;
}

int main(){
    int t; cin>>t; while(t--){
        int n,m; cin>>n>>m;
        vector<bitset<10000>> v;
        while(n--){
            bitset<10000> w;
            int z; cin>>z; while(z--){
                int t; cin>>t; w[t]=1;
            }
            for(auto &i:v){
                bitset<10000> t=i^w;
                if(change(t,w))w=t;
            }
            if(w.count())v.push_back(w);
        }
        cout<<v.size()<<endl;
    }
}
