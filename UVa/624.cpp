#include<bits/stdc++.h>
using namespace std;

int track[22];
int main(){
    int l; while(cin>>l){
        int n; cin>>n;
        for(int i=1;i<=n;++i)cin>>track[i];
        int *dp=new int[l+10],*last=new int[l+10];
        for(int i=0;i<l+10;++i)dp[i]=-1,last[i]=0;
        dp[0]=0;
        for(int i=1;i<=n;++i){
            for(int j=l;j>=track[i];--j){
                if(dp[j-track[i]]==-1)continue;
                if(dp[j]<dp[j-track[i]]+1){
                    dp[j]=dp[j-track[i]]+1;
                    last[j]=track[i];
                }
            }
        }
        int most=-1,lasttime=-1;
        for(int i=0;i<=l;++i){
            if(dp[i]>=most){
                most=dp[i];
                lasttime=i;
            }
        }
        stack<int> tracks;
        int sum=lasttime;
        while(lasttime){
            tracks.push(last[lasttime]);
            lasttime-=last[lasttime];
        }
        while(tracks.size()){
            cout<<tracks.top()<<" ";
            tracks.pop();
        }
        cout<<"sum:"<<sum<<endl;
    }
}
