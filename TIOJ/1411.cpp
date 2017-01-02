#include<cstdio>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long

map<ll,int> m;
ll p[1000005];

int main(){
    int n;
    while(~scanf("%d",&n)){
        int mx=0;
        m.clear();
        m[0]=0;
        for(int i=1;i<=n;++i){
            scanf("%lld",&p[i]);
            p[i]+=p[i-1];
            auto it=m.find(p[i]);
            // cout<<i<<" "<<p[i]<<endl;
            if(it!=m.end()){
                mx=max({mx,i-it->second});
            }
            it=m.find(p[i]);
            if(it==m.end()){
                m[p[i]]=i;
            }
        }
        // printf("%d\n",mx);
        cout<<mx<<endl;
    }
}
