#include<iostream>
#include<algorithm>
using namespace std;

int a[666],b[666],dp[666][666],pre[666][666];

int main(){
    int ts;cin>>ts;while(ts--){
        int n;cin>>n;
        for(int i=n;i;--i)cin>>a[i];
        for(int i=n;i;--i)cin>>b[i];
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(a)
            }
        }
        for(int i=1;i<=n;++i){
            cout<<dp[i]<<" ";
        }cout<<endl;
    }
}

// 不是是
// 如果a[i] == b[j] 那麼dp[i][j] = max{dp[x][y]|(x,y)<(i,j), y[j] < b[j]}
// 如果a[i] != b[j] 那麼dp[i][j] = 0 嗎
// dp[i][j]的意思是以a[i],b[j]結尾的LCIS長度
// 啊這樣是O(NMM)嘛 你要想辦法把max那一步做到O(1)
// 那就邊DP邊預處理就好了
// 所以就長得像標準作法那樣(?
