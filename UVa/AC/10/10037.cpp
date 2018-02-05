#include<bits/stdc++.h>
using namespace std;

int cnt[111];
int a[1111];

#define t2 isjdf
#define t3 sofei

int main(){
    int ts; cin>>ts; while(ts--){
        memset(cnt,0,sizeof(cnt));
        int n; cin>>n; while(n--){
            int t; cin>>t; ++cnt[t];
        }
        for(int i=1;i<111;++i){
            while(cnt[i]--){
                a[++n]=i;
            }
        }
        ++n;
        int ans=0;
        vector<pair<int,int>> v;
        while(n>=4){
            int t1=a[0],t2=a[1],t3=a[n-2],t4=a[n-1];
            if(t2+t1+t4+t2<t3+t1+t4+t1){
                v.push_back({t1,t2});
                v.push_back({t1,0});
                v.push_back({t3,t4});
                v.push_back({t2,0});
            }
            else{
                v.push_back({t1,t3});
                v.push_back({t1,0});
                v.push_back({t1,t4});
                v.push_back({t1,0});
            }
            ans+=min(t2+t1+t4+t2,t3+t1+t4+t1);
            n-=2;
        }
        if(n==3)ans+=a[n-3]+a[n-2]+a[n-1],v.push_back({a[0],a[1]}),v.push_back({a[0],0}),v.push_back({a[0],a[2]});
        else if(n==2)ans+=a[1],v.push_back({a[0],a[1]});
        else if(n==1)ans+=a[0],v.push_back({a[0],0});
        cout<<ans<<endl;
        for(auto i:v){
            cout<<i.first;
            if(i.second)cout<<" "<<i.second;
            cout<<endl;
        }
        if(ts)cout<<endl;
    }
}
