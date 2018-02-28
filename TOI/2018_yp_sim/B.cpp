#include<bits/stdc++.h>
using namespace std;

int a[1000006];
vector<int> cv,dv,ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    int c,d; cin>>c>>d;
    cv.resize(c);
    dv.resize(d);
    for(int i=0;i<c;++i)cin>>cv[i];
    for(int i=0;i<d;++i)cin>>dv[i];
    for(int i=1;i<=n;++i){
        if(a[i]==cv.back()){
            // cout<<"checking i: "<<i<<endl;
            set<int> canpos;
            [&](){
                int ptr=c-2,pos=i-1;
                while(pos>0 && ptr>=0){
                    if(a[pos]==cv[ptr])--ptr;
                    --pos;
                }
                while(pos>0)canpos.insert(a[pos]),--pos;
            }();
            [&](){
                int ptr=d-2,pos=i+1;
                while(pos<=n && ptr>=0){
                    if(a[pos]==dv[ptr])--ptr;
                    ++pos;
                }
                while(pos<=n){
                    if(canpos.find(a[pos])!=canpos.end()){
                        ans.push_back(i);
                        return;
                    }
                    ++pos;
                }
            }();
        }
    }
    cout<<ans.size()<<endl;
    if(ans.empty())cout<<"-1"<<endl;
    else for(int i:ans){
        cout<<i;
        if(i!=ans.back())cout<<" ";
        else cout<<endl;
    }
}
