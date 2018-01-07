#include<bits/stdc++.h>
using namespace std;

struct disjointSet{
    std::vector<int> djs;
    void init(int size){
        djs.resize(size);
        for(int i=0;i<size;++i)djs[i]=i;
    }
    int F(int x){return djs[x]==x?x:djs[x]=F(djs[x]);}
    void U(int x,int y){djs[F(x)]=F(y);}
    bool C(int x,int y){return F(x)==F(y);}
} djs;

int main(){
    int n; cin>>n;
    djs.init(n+10);
    for(int i=0;i<n;++i){
        int t; cin>>t; djs.U(i,t);
    }
    set<int> st;
    for(int i=0;i<n;++i)st.insert(djs.F(i));
    cout<<st.size()<<endl;
}
