#include<bits/stdc++.h>
using namespace std;
int main(){
    int ts;cin>>ts;while(ts--){
        int n;cin>>n;
        int h[1005]={0},a[1005]={0},tot=0;
        for(int i=1;i<=n;++i)cin>>h[i];h[0]=h[1];h[n+1]=h[n];
        for(int i=2;i<=n;++i){
            a[i]=abs(h[i]-h[i-1]);
            tot+=a[i];
        }
        for(int i=1;i<=n;++i){
            int mns=tot+9999,mnj=-1;
            for(int j=1;j<=n;++j){
                swap(h[i],h[j]);h[0]=h[1];h[n+1]=h[n];
                // cout<<"swap:"<<i<<" "<<j<<" : h:";for(int i=1;i<=n;++i)cout<<h[i]<<" ";cout<<" xxx="<<tot-a[i]-a[i+1]-a[j]-a[j+1]+abs(h[i]-h[i-1])+abs(h[i+1]-h[i])+abs(h[j]-h[j-1])+abs(h[j+1]-h[j])<<endl;
                // cout<<"-"<<a[i]<<" "<<a[i+1]<<" "<<a[j]<<" "<<a[j+1]<<endl;
                // cout<<"+"<<abs(h[i]-h[i-1])<<" "<<abs(h[i+1]-h[i])<<" "<<abs(h[j]-h[j-1])<<" "<<abs(h[j+1]-h[j])<<endl;
                if(mns>tot-a[i]-a[i+1]-a[j]-a[j+1]+abs(h[i]-h[i-1])+abs(h[i+1]-h[i])+abs(h[j]-h[j-1])+abs(h[j+1]-h[j])){
                    mns=tot-a[i]-a[i+1]-a[j]-a[j+1]+abs(h[i]-h[i-1])+abs(h[i+1]-h[i])+abs(h[j]-h[j-1])+abs(h[j+1]-h[j]);
                    mnj=j;
                }
                swap(h[i],h[j]);h[0]=h[1];h[n+1]=h[n];
            }
            if(i-1)cout<<" ";
            cout<<mnj;
        }
        cout<<endl;
    }
}
