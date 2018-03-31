#include<bits/stdc++.h>
using namespace std;

#define left adrjoguieg

void no(){cout<<"-1"<<endl; exit(0);}

vector<int> ans[3000000];
unordered_map<int,vector<int>> left;
bitset<1000006> skip;
int main(){
    int n,p,q; cin>>n>>p>>q;
    if(q<n)no();
    multiset<int> st;
    for(int i=0;i<p;++i)st.insert(q);
    for(int i=0;i<p;++i)left[q].push_back(i);

    for(int i=n;i>=1;--i){
        cout<<i<<endl;
        if(skip[i])continue;
        auto it=--st.end();
        if(*it<i)no();

        int now=*it;
        st.erase(it);

        // cout<<"now:"<<now<<endl;

        int put_in=left[now].back();
        cout<<"putin: "<<put_in<<endl;
        left[now].pop_back();
        cout<<"putin: "<<put_in<<endl;
        ans[put_in].push_back(i);

        cout<<"putin: "<<put_in<<endl;

        int upd=now-i;
        if(upd){
            if(upd<i && !skip[i]){
                ans[put_in].push_back(upd);
                skip[i]=1;
            }
            else{
                st.insert(upd);
                left[upd].push_back(put_in);
            }
        }
    }

    for(int i=0;i<p;++i){
        for(int ii:ans[i])cout<<ii<<" ";

    }
    cout<<endl;
}
