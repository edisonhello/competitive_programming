#include<bits/stdc++.h>
using namespace std;
#define ll long long

bitset<500> notp;
vector<int> p;
void init(){
    for(int i=2;i<=500;++i){
        if(notp[i])continue;
        p.push_back(i);
        for(int j=i*i;j<=500;j+=i){
            notp[j]=1;
        }
    }
}

bitset<200005> forbid;
int pcnt[200005];
vector<int> primepos;

void decom(int x){
    for(int pp:p){
        if(x%pp==0){
            while(x%pp==0){
                x/=pp;
                ++pcnt[pp];
            }
            primepos.push_back(pp);
        }
    }
    if(x>1)++pcnt[x],primepos.push_back(x);
}

int m;
vector<int> available[200005];

void getcount(int bas){
    for(int i=bas;i<=m;i+=bas){
        if(!forbid[i] && __gcd(i,m)==bas)available[bas].push_back(i);
    }
}

void dfs1(int now,int ptr){
    if(ptr>=primepos.size()){
        getcount(now);
        return;
    }
    for(int i=0;i<=pcnt[primepos[ptr]];++i){
        dfs1(now,ptr+1);
        now*=primepos[ptr];
    }
}

vector<int> G[200005];
int nowpcnt[200005];
bitset<200005> makegraphed;

void makegraph(int now){
    if(now==m)return;
    if(makegraphed[now])return;
    makegraphed[now]=1;
    for(int i=0;i<primepos.size();++i){
        if(nowpcnt[primepos[i]]<pcnt[primepos[i]]){
            G[now].push_back(now*primepos[i]);
            // cout<<"graph add edge "<<now<<" "<<now*primepos[i]<<endl;
            ++nowpcnt[primepos[i]];
            makegraph(now*primepos[i]);
            --nowpcnt[primepos[i]];
        }
    }
}

int dp[200005],go[200005];
bitset<200005> dfs2ed;
void dfs2(int now){
    // cout<<"dfs2 "<<now<<endl;
    if(dfs2ed[now])return;
    dfs2ed[now]=1;
    for(int i:G[now]){
        dfs2(i);
        if(dp[i]>dp[now]){
            dp[now]=dp[i];
            go[now]=i;
        }
    }
    dp[now]+=available[now].size();
}

vector<int> seq;
void makesequence(int now){
    if(!now)return;
    // cout<<now<<endl;
    for(int i:available[now]){
        seq.push_back(i);
    }
    if(now==m)return;
    makesequence(go[now]);
}

int extgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1; y=0;
        return a;
    }
    int r=extgcd(b,a%b,y,x);
    y-=a/b*x;
    return r;
}

ll inv(int x,int m){
    // return pw(x,m-2,m);
    int a=0,b=0;
    int g=extgcd(x,m,a,b);
    if(g!=1)exit(7122);
    // cout<<"get inv of "<<x<<" in "<<m<<" is "<<(a%m+m)%m<<endl;
    return (a%m+m)%m;
}

int main(){
    init();
    int n; cin>>n>>m;
    while(n--){int t; cin>>t; forbid[t]=1;}
    if(forbid[0])forbid[m]=1;
    decom(m);
    dfs1(1,0);
    makegraph(1);
    // cout<<"makegraphed"<<endl;
    dfs2(1);
    makesequence(1);
    // for(int i:seq)cout<<i<<" "; cout<<endl;
    int prepro=1;
    cout<<seq.size()<<endl;
    for(int i:seq){
        ll ggg=__gcd(m,prepro);
        cout<<inv(prepro/ggg,m/ggg)*i/ggg%m<<" ";
        prepro=i;
    }
    cout<<endl;
}
