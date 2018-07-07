#include<bits/stdc++.h>
using namespace std;

bitset<1000006> app,np;
int a[1000006],mnf[1000006];
vector<int> p;

void init(int n=1000000){
    mnf[2]=2; np[1]=1;
    for(int i=2;i<=n;++i){
        if(np[i])continue;
        mnf[i]=i;
        p.push_back(i);
        for(auto j=1ll*i*i;j<=n;j+=i){
            mnf[j]=i;
            np[j]=1;
        }
    }
}

void dfs(map<int,int> &mp,map<int,int>::iterator it,int now,vector<int> &res){
    if(it==mp.end()){
        res.push_back(now);
        return;
    }
    int pro=1;
    for(int i=0;i<=it->second;++i){
        dfs(mp,next(it),now*pro,res);
        pro*=it->first;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    int ts; cin>>ts; while(ts--){
        // app.reset();
        memset(a,0,sizeof(a));
        int n; cin>>n;
        // vector<int> num;
        set<int> num;
        for(int i=1,t;i<=n;++i)cin>>t,++a[t],num.insert(t);
        long long sum=0;
        for(;num.size();){
            int i=*num.begin(); num.erase(num.begin());
            for(int j=i*2;j<1000006;j+=i){
                a[i]+=a[j];
                a[j]=0;
                num.erase(j);
            }
        }
        for(int i=1;i<1000006;++i){
            sum+=1ll*i*a[i];
        }
        /* for(int i=1;i<=n;++i){
            map<int,int> mp;
            int x=a[i];
            while(x>1){
                ++mp[mnf[x]];
                x/=mnf[x];
            }
            vector<int> fac;
            dfs(mp,mp.begin(),1,fac);
            int add=1e8;
            for(int i:fac){
                if(app[i])add=min(add,i);
            }
            sum+=add;
        } */
        cout<<sum<<endl;
    }
}
