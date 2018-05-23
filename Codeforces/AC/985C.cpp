#include<bits/stdc++.h>
using namespace std;

vector<int> v;
bitset<100005> use;

int main(){
    int n,k,l; cin>>n>>k>>l;
    for(int i=0;i<n*k;++i){
        int t; cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    int pos=upper_bound(v.begin(),v.end(),v[0]+l)-v.begin();
    if(pos<n)exit((cout<<0<<endl,0));
    long long sum=v[0];
    int ptr=v.size()-1;
    for(int i=pos-1,c=0;c<n-1;++c,--i){
        while(use[i])--i;
        int low=v[i];
        use[i]=1;
        for(int z=1;z<k;++z){
            while(use[ptr])--ptr;
            use[ptr]=1;
            low=min(low,v[ptr]);
        }
        sum+=low;
    }
    cout<<sum<<endl;
}
