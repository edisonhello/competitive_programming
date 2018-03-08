#include<bits/stdc++.h>
using namespace std;

string mp[2222];
int gor[2222][2222];

int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<n;++i)cin>>mp[i];
    for(int i=1;i<n;++i){
        for(int j=m-1;j>=0;--j){
            gor[i][j]=1;
            if(j==m-1)continue;
            if((mp[i][j]==mp[i][j+1] && mp[i-1][j]==mp[i-1][j+1]) || (mp[i][j]!=mp[i][j+1] && mp[i-1][j]!=mp[i-1][j+1]))gor[i][j]=gor[i][j+1]+1;
        }
    }
    int area=0;
    for(int j=m-1;j>=0;--j){
        stack<int> iidx;
        iidx.push(0);
        for(int i=1;i<=n;++i){
            // if(j==4)cout<<"gor of "<<i<<" is "<<gor[i][j]<<endl;
            while(iidx.size() && gor[iidx.top()][j]>gor[i][j]){
                int top_gor=gor[iidx.top()][j];
                iidx.pop();
                area=max(area,top_gor*(i-iidx.top()));
                // if(j==4)cout<<"new area "<<top_gor*(i-iidx.top())<<" at "<<i<<endl;
            }
            iidx.push(i);
        }
    }
    cout<<max(area,max(n,m))<<endl;
}
