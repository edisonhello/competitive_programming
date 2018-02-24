#include<bits/stdc++.h>
using namespace std;
#define ld long double

ld x[28],y[28],d[28];

inline ld dis(int i,int j){
    return sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
}

int perm[28];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    srand(time(0));
    int t; cin>>t; while(t--){
        int shuffletime=30000;
        int n; cin>>n;
        for(int i=0;i<n;++i)cin>>x[i]>>y[i];
        for(int i=0;i<n;++i)perm[i]=i;
        ld mn=1e20;
        while(shuffletime--){
            random_shuffle(perm,perm+n);
            vector<int> nowp;
            nowp.push_back(perm[0]);
            nowp.push_back(perm[1]);
            int inspos=-1;
            for(int i=2;i<n;++i){
                ld now=0;
                for(int i=1;i<nowp.size();++i)now+=dis(nowp[i-1],nowp[i]);
                ld mn=now+dis(perm[i],nowp[0]);
                int inspos=-1;
                if(now+dis(perm[i],nowp.back())<mn){
                    mn=now+dis(perm[i],nowp.back());
                    inspos=nowp.size();
                }
                for(int ii=1;ii<nowp.size();++ii){
                    ld tmp=now-dis(nowp[ii],nowp[ii-1])+dis(nowp[ii],perm[i])+dis(nowp[ii-1],perm[i]);
                    if(tmp<mn){
                        mn=tmp;
                        inspos=ii;
                    }
                }
                vector<int> nvec;
                if(inspos==-1)nvec.push_back(perm[i]);
                for(int ii=0;ii<nowp.size();++ii){
                    if(ii==inspos)nvec.push_back(perm[i]);
                    nvec.push_back(nowp[ii]);
                }
                if(inspos==nowp.size())nvec.push_back(perm[i]);
                nowp=nvec;
            }
            ld nowdd=0;
            for(int i=1;i<nowp.size();++i)nowdd+=dis(nowp[i-1],nowp[i]);
            mn=min(mn,nowdd);
            // for(int i=0;i<nowp.size();++i)cout<<nowp[i]<<" "; cout<<" : "<<nowdd<<endl;
        }
        cout<<fixed<<setprecision(2)<<mn<<endl;
    }
}
