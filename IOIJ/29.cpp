#include<iostream>
#include<vector>
#include<cstring>
#include<set>
using namespace std;

int djs[100005];

int main(){
    int ts;cin>>ts;while(ts--){
        int n,m;cin>>n>>m;
        for(int i=1;i<=n;++i){
            djs[i]=i;
        }

        while(m--){
            int a,b;cin>>a>>b;
            djs[b]=a;
        }

        int ans=0;

        cout<<ans<<endl;
    }
}
