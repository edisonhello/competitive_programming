#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<pair<int,int>> seg(100005);

    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>seg[i].first>>seg[i].second;

    auto cmpl=[&](const int &a,const int &b){ return tie(seg[a].first,a)<tie(seg[b].first,b); };
    auto cmpr=[&](const int &a,const int &b){ return tie(seg[a].second,a)<tie(seg[b].second,b); };

    set<int,decltype(cmpl)> lset(cmpl);
    set<int,decltype(cmpr)> rset(cmpr);

    for(int i=1;i<=n;++i)lset.insert(i);
    for(int i=1;i<=n;++i)rset.insert(i);

    cout<<max([=]()mutable->long long{
        long long rt=0,now=0;
        while(lset.size()){
            int rrr=*--lset.end();
            lset.erase(rrr); rset.erase(rrr);
            if(seg[rrr].first<=now && now<=seg[rrr].second);
            else if(now<=seg[rrr].first)rt+=seg[rrr].first-now,now=seg[rrr].first;
            else rt+=now-seg[rrr].second,now=seg[rrr].second;
            // cout<<"choose "<<rrr<<endl;
            if(lset.empty())break;
            int lll=*rset.begin();
            lset.erase(lll); rset.erase(lll);
            if(seg[lll].first<=now && now<=seg[lll].second);
            else if(now<=seg[lll].first)rt+=seg[lll].first-now,now=seg[lll].first;
            else rt+=now-seg[lll].second,now=seg[lll].second;
            // cout<<"choose "<<lll<<endl;
        }
        // cout<<"fi ov"<<endl;
        return rt+abs(now);
    }(),[=]()mutable->long long{
        long long rt=0,now=0;
        while(rset.size()){
            int lll=*rset.begin();
            lset.erase(lll); rset.erase(lll);
            if(seg[lll].first<=now && now<=seg[lll].second);
            else if(now<=seg[lll].first)rt+=seg[lll].first-now,now=seg[lll].first;
            else rt+=now-seg[lll].second,now=seg[lll].second;
            // cout<<"choose "<<lll<<endl;
            if(rset.empty())break;
            int rrr=*--lset.end();
            lset.erase(rrr); rset.erase(rrr);
            if(seg[rrr].first<=now && now<=seg[rrr].second);
            else if(now<=seg[rrr].first)rt+=seg[rrr].first-now,now=seg[rrr].first;
            else rt+=now-seg[rrr].second,now=seg[rrr].second;
            // cout<<"choose "<<rrr<<endl;
        }
        // cout<<"se ov"<<endl;
        return rt+abs(now);
    }())<<endl;
}
