#include<bits/stdc++.h>
using namespace std;

long long delta,ans=1ll<<60;

vector<pair<int,int>> a;

struct {
    multiset<int> L,R;
    long long sumL=0,sumR=0;
    long long get(){
        return sumR-1ll*R.size()*(*R.begin())+1ll*L.size()*(*R.begin())-sumL;
    }
    void meow(){
        while(L.size()>R.size()+1){
            R.insert(*--L.end());
            sumR+=*L.begin();
            sumL-=*L.begin();
            L.erase(--L.end());
        }
        while(R.size()>L.size()+1){
            L.insert(*R.begin());
            sumL+=*R.begin();
            sumR-=*R.begin();
            R.erase(R.begin());
        }
        while(L.size() && R.size() && *R.begin()<*--L.end()){
            int deltaL=*--L.end(),deltaR=*R.begin();
            sumL=sumL-deltaL+deltaR;
            sumR=sumR-deltaR+deltaL;
            L.erase(L.find(deltaL));
            R.erase(R.find(deltaR));
            L.insert(deltaR);
            R.insert(deltaL);
        }
    }
    void insert(const int a){
        R.insert(a);
        sumR+=a;
        meow();
    }
    void erase(const int a){
        if(a<=*--L.end()){
            L.erase(L.find(a));
            sumL-=a;
        }
        else{
            R.erase(R.find(a));
            sumR-=a;
        }
        meow();
    }
} L,R;

int main(){
    int k,n; cin>>k>>n;
    for(int i=1;i<=n;++i){
        char p,q; int s,t; cin>>p>>s>>q>>t;
        if(p==q)delta+=abs(s-t);
        else{
            ++delta;
            if(t<s)swap(s,t);
            a.emplace_back(s,t);
        }
    }
    sort(a.begin(),a.end(),[](const pair<int,int> &a,const pair<int,int> &b){return a.first+a.second<b.first+b.second;});
    for(auto &p:a)R.insert(p.first),R.insert(p.second);
    if(k==1){
        ans=min(ans,R.get());
    }
    else{
        ans=min(ans,R.get());
        for(int i=1;i<a.size();++i){
            L.insert(a[i-1].first); L.insert(a[i-1].second);
            R.erase(a[i-1].first); R.erase(a[i-1].second);
            ans=min(ans,L.get()+R.get());
        }
    }
    cout<<ans+delta<<endl;
}
