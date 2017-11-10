#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int main(){
    int n,l,r,x; cin>>n>>l>>r>>x;
    while(cin>>n){
        v.push_back(n);
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<(1<<v.size());++i){
        int tt=0,ll=0,rr=0;
        for(int ii=0;ii<v.size();++ii){
            if(i&(1<<ii)){
                tt+=v[ii];
                if(!ll)ll=v[ii];
                rr=v[ii];
            }
        }
        // cout<<i<<" "<<r-l<<" "<<tt<<endl;
        if(l<=tt and tt<=r and rr-ll>=x){
            ++ans;
            // cout<<i<<endl;
        }
    }
    cout<<ans<<endl;
}
