#include<bits/stdc++.h>
using namespace std;

void no(){cout<<"-1"<<endl; exit(0);}

int main(){
    no();
    int n,p,q; cin>>n>>p>>q;
    if(q<n)no();
    set<int> lef;
    for(int i=1;i<=n;++i)lef.insert(i);
    vector<vector<int>> ans;
    for(int i=0;i<p;++i){
        int le=q;
        vector<int> nw;
        while(le){
            auto it=lef.upper_bound(le);

            if(it==lef.begin())no();

            --it;
            nw.push_back(*it);
            le-=*it;
            lef.erase(it);
        }
        ans.push_back(nw);
    }
    for(auto v:ans){
        for(int i:v)cout<<i<<" ";
        cout<<endl;
    }
}
