#include<iostream>
using namespace std;

#include<algorithm>
int a[105];
bool v[105];
#include<vector>
vector<int> bs;
#include<cstring>

bool dfs(int now,int st,int dep){
    if(now==st){
        if(dep&1)bs.push_back(dep);
        else bs.push_back(dep>>1);
        return 1;
    }
    if(v[now])return 0;
    v[now]=1;
    return dfs(a[now],st,dep+1);
}

void lcm(int a,int &b){
    int G=__gcd(a,b);
    b=a*b/G;
}

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        if(!v[i]){
            if(!dfs(a[i],i,1)){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    int G=bs[0];
    // for(auto &i:bs)cout<<i<<" ";cout<<endl;
    // for(auto &i:bs)G=__gcd(G,i);//cout<<"G="<<G<<endl;
    // int L=G;
    // for(auto &i:bs)L*=i/G;
    for(auto i=1u;i<bs.size();++i){
        lcm(bs[i-1],bs[i]);
    }
    cout<<bs[bs.size()-1]<<endl;
}
