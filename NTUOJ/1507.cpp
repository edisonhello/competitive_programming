#include<bits/stdc++.h>
using namespace std;

#define data unsigned long long

set<data> st,nwi;
string mp[8]; 
data trap;

#define idx(i,j) (((i)<<3)|((j)))
#define gx(i) ((i)>>3)
#define gy(i) ((i)&7)

int main(){
    int t,ks=0; cin>>t; while(t--){
        st.clear();
        for(int i=0;i<8;++i)cin>>mp[i];
        for(int i=0;i<8;++i)for(int j=0;j<8;++j)if(mp[i][j]=='#')trap|=(1ull<<idx(i,j);
        data now=trap;
        for(int i=0;i<7;++i)for(int j=0;j<7;++j){
            if(mp[i][j]>='A' && mp[i][j]<='D' && mp[i][j]==mp[i+1][j] && mp[i][j]==mp[i][j+1] && mp[i][j]==mp[i+1][j+1])now|=(1ull<<idx(i,j));
        }
        nwi.insert(now);
        while(nwi.size()){
            data now=*nwi.begin(); nwi.erase(nwi.begin());
        }
        cout<<"Case "<<(++ks)<<": "<<st.size()<<endl;
    }
}
