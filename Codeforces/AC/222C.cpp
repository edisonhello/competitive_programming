#include<bits/stdc++.h>
using namespace std;

vector<int> f[10000000];
bitset<4000> np;
vector<int> p;
void init(){
    for(int i=2;i<4000;++i){
        if(np[i])continue;
        p.push_back(i);
        for(int j=i*i;j<4000;j+=i){
            np[j]=1;
        }
    }
}

int a[100005],b[100005];

int main(){
    init();
    int n,m; cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
        int x=a[i];
        for(int pp:p){
            if(pp*pp>x)break;
            while(x%pp==0){
                f[pp].push_back(i);
                x/=pp;
            }
        }
        if(x>1)f[x].push_back(i);
    }
    for(int i=0;i<m;++i){
        cin>>b[i];
        // cout<<"do "<<b[i]<<endl;
        int x=b[i];
        for(int pp:p){
            if(pp*pp>x)break;
            while(x%pp==0){
                if(f[pp].size()){
                    a[f[pp].back()]/=pp;
                    f[pp].pop_back();
                    b[i]/=pp;
                    // cout<<"dec "<<pp<<endl;
                }
                x/=pp;
            }
        }
        if(x>1){
            if(f[x].size()){
                a[f[x].back()]/=x;
                f[x].pop_back();
                b[i]/=x;
                // cout<<"dec "<<x<<endl;
            }
        }
    }
    cout<<n<<" "<<m<<endl;
    for(int i=0;i<n;++i)cout<<a[i]<<" "; cout<<endl;
    for(int i=0;i<m;++i)cout<<b[i]<<" "; cout<<endl;
}
