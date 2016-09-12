#include<bits/stdc++.h>
using namespace std;

int n,c;
vector<int> v,w,t,cs,W;


int dp(int now,int left,int cnt){
    // cout<<"dp for now="<<now<<" left="<<left<<" cnt="<<cnt<<endl;
    cs[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=w[i];j<=c;j++){
            for(int k=0;j-w[i]*k>=0;k++){
                cs[j] = max(cs[j], cs[j-w[i]*k]+v[i]*k);
            }
        }
    }
    return cs[c];
}

int main(){
    cin>>n>>c;
    v.reserve(n+5);
    w.reserve(n+5);
    // W.reserve(c+10);
    t.reserve(n+5);
    cs.reserve(c+5);
    for(int i=0;i<n;i++){
        cin>>v[i]>>w[i]>>t[i];
    }

    cout<<dp(n,c,0)<<endl;
}


// int dp(1)(int now,int left,int cnt){
//     cout<<"dp for now="<<now<<" left="<<left<<" cnt="<<cnt<<endl;
//     DE++;
//     // assert(DE<1000);
//     if(left<=0)return 0;
//     if(cnt>=t[now] && t[now]!=-1 && now>0){
//         return dp(now-1,left,0);
//     }
//     else{
//         int val=now ? dp(now-1,left,0) : 0;
//         for(int i=now;i>0;i--){
//             val = max(val,dp(now,left-w[i],cnt+1)+v[i]);
//         }
//         return val;
//     }
//     return 0;
// }

// int dp(2)(int now,int left,int cnt){
//     cout<<"dp for now="<<now<<" left="<<left<<" cnt="<<cnt<<endl;
//     if(now<0)return 0;
//     if(left<=0)return 0;
//     int mx=-(1<<20);
//     for(int i=1;i<=(cnt<t[now] || t[now]==-1 ? now : now-1);i++){
//         mx=max(mx,max(dp(now-1,left,0),dp(now,left-w[i],cnt+1)+v[i]));
//     }
//     return mx;
// }
