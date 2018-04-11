#include<bits/stdc++.h>
using namespace std;

int x[200005];
char tp[200005];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x[i]>>tp[i];
    }
    
    long long cost=0;
    int fp=-1,ep=n+3;
    for(int i=1;i<=n;++i){
        if(tp[i]=='P'){
            fp=i; break;
        }
    }
    for(int i=n;i>=1;--i){
        if(tp[i]=='P'){
            ep=i;
            break;
        }
    }
    if(fp==-1){
        vector<int> bs,rs;
        for(int i=1;i<=n;++i){
            if(tp[i]=='B')bs.push_back(x[i]);
            else rs.push_back(x[i]);
        }
        for(int i=1;i<bs.size();++i)cost+=bs[i]-bs[i-1];
        for(int i=1;i<rs.size();++i)cost+=rs[i]-rs[i-1];
        cout<<cost<<endl;
    }
    else{
        vector<int> bs,rs,ps;
        int bprv=-2e9,rprv=-2e9;
        for(int i=1;i<=n;++i){
            if(tp[i]=='B'){
                if(ps.size())bs.push_back(x[i]);
                else if(bprv>=-1e9-10){
                    cost+=x[i]-bprv;
                }
                bprv=x[i];
            }
            else if(tp[i]=='R'){
                if(ps.size())rs.push_back(x[i]);
                else if(rprv>=-1e9-10){
                    cost+=x[i]-rprv;
                    // cout<<cost<<endl;
                }
                rprv=x[i];
            }
            else{
                if(ps.empty()){
                    // cout<<"first p: "<<bprv<<" "<<rprv<<" cost: "<<cost<<endl;
                    if(bprv>=-1e9-10)cost+=x[i]-bprv;
                    if(rprv>=-1e9-10)cost+=x[i]-rprv;
                    // cout<<"cost: "<<cost<<endl;
                }
                ps.push_back(x[i]);
            }
        }
        // cout<<"pre pro: "<<cost<<endl;
        while(bs.size() && bs.back()>ps.back()){
            int pro=bs.back(); bs.pop_back();
            int mnc=pro-ps.back();
            if(bs.size())mnc=min(mnc,pro-bs.back());
            cost+=mnc;
        }
        while(rs.size() && rs.back()>ps.back()){
            int pro=rs.back(); rs.pop_back();
            int mnc=pro-ps.back();
            if(rs.size())mnc=min(mnc,pro-rs.back());
            cost+=mnc;
        }
        // cout<<"pre pro: "<<cost<<endl;
        int bptr=0,rptr=0;
        for(int i=1;i<ps.size();++i){
            int pl=ps[i-1],pr=ps[i];
            vector<int> nbs,nrs;
            while(bptr<bs.size() && bs[bptr]<=pr){
                nbs.push_back(bs[bptr]);
                ++bptr;
            }
            while(rptr<rs.size() && rs[rptr]<=pr){
                nrs.push_back(rs[rptr]);
                ++rptr;
            }
            vector<long long> bds,rds;
            for(int i=1;i<nbs.size();++i)bds.push_back(nbs[i]-nbs[i-1]);
            for(int i=1;i<nrs.size();++i)rds.push_back(nrs[i]-nrs[i-1]);
            /* cout<<pl<<" ";
            if(nbs.size())cout<<nbs[0]<<" ";
            if(nrs.size())cout<<nrs[0]<<" ";
            cout<<endl; */
            if(nbs.size())bds.push_back(nbs[0]-pl),bds.push_back(pr-nbs.back());
            else bds.push_back(pr-pl);
            if(nrs.size())rds.push_back(nrs[0]-pl),rds.push_back(pr-nrs.back());
            else rds.push_back(pr-pl);
            sort(bds.begin(),bds.end());
            sort(rds.begin(),rds.end());
            long long c=0;
            for(int i=0;i<bds.size()-1;++i)c+=bds[i];
            for(int i=0;i<rds.size()-1;++i)c+=rds[i];
            cost+=min(c+pr-pl,(pr-pl)*2ll);
        }
        cout<<cost<<endl;
    }
}
