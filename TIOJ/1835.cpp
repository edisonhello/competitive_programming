#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define pii pair<int,int>
#define rz(x) reserve(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define S0(x) memset((x),0,sizeof(x))
#define SB(x) memset((x),0x7f,sizeof(x))

string dp[1005][1005];
string a,b;

int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        cin>>a>>b;
        S0(dp);
        int i,j;
        for(i=0;i<(int)a.length();i++){
            for(j=0;j<(int)b.length();j++){
                if(a[i]==b[j]){
                    dp[i][j]=(i==0||j==0?""+a[i]:dp[i-1][j-1]+a[i]);
                }
                else{
                    dp[i][j]=(i==0?0:dp[i-1][j].length())==(j==0?0:dp[i][j-1].length())?min(i==0?"":dp[i-1][j],j==0?"":dp[i][j-1]):(i==0?0:dp[i-1][j].length())>(j==0?0:dp[i][j-1].length())?(i==0?"":dp[i-1][j]):(j==0?"":dp[i][j-1]);
                }
            }
        }
        if(dp[a.length()-1][b.length()-1].length()==0){
            cout<<"妹萌えこそ正義なのさ！\n";
        }
        else{
            cout<<dp[a.length()-1][b.length()-1]<<'\n';
        }
    }
}



// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ld long double
// #define PB(x) push_back(x)
// #define pii pair<int,int>
// #define rz(x) reserve(x)
// #define X first
// #define Y second
// // #define m (l+r)/2
// // #define xm (x1+x2)/2
// // #define ym (y1+y2)/2
// #define DE cout<<"de"<<endl;
// #define PQ priority_queue
// #define getchar_unlocked getchar
// #define putchar_unlocked putchar
// #define S0(x) memset((x),0,sizeof(x))
// #define SB(x) memset((x),0x7f,sizeof(x))
//
// vector<string> pos_ans;
// int dp[1005][1005];
// string a,b;
// bool gone[1005][1005];
//
// void dfs(int i,int j,string now){
//     while(i>=0&&j>=0){
//         gone[i][j]=1;
//         // cout<<"dfs:rd:"<<i<<" "<<j<<endl;
//         if(i>0&&j>0&&dp[i][j]==dp[i-1][j]&&dp[i][j]==dp[i][j-1]){
//             if(!gone[i-1][j])dfs(i-1,j,now);
//             if(!gone[i][j-1])dfs(i,j-1,now);
//             return;
//         }
//         else if(i>0&&dp[i][j]==dp[i-1][j]){
//             i--;
//         }
//         else if(j>0&&dp[i][j]==dp[i][j-1]){
//             j--;
//         }
//         else if(i>0&&j>0&&dp[i][j]==dp[i-1][j-1]+1){
//             now=a[i]+now;
//             i--;
//             j--;
//         }
//         else if(j==0&&i>0&&dp[i][j]==dp[i-1][j]+1){
//             now=a[i]+now;
//             i--;
//             break;
//         }
//         else if(i==0&&j>0&&dp[i][j]==dp[i][j-1]+1){
//             now=a[i]+now;
//             j--;
//             break;
//         }
//         else if(i==0&&j==0&&dp[i][j]==1){
//             now=a[i]+now;
//             break;
//         }
//         else if(i==0&&j==0&&dp[i][j]==0){
//             break;
//         }
//     }
//     // cout<<"pushed: "<<now<<endl;
//     assert(now.length()==dp[a.length()-1][b.length()-1]);
//     pos_ans.PB(now);
// }
//
// int main(){
//     // cin.tie(0);
//     ios_base::sync_with_stdio(0);
//     int t;cin>>t;
//     while(t--){
//         cin>>a>>b;
//         pos_ans.clear();
//         S0(dp);
//         S0(gone);
//         int i,j;
//         for(i=0;i<(int)a.length();i++){
//             for(j=0;j<(int)b.length();j++){
//                 if(a[i]==b[j]){
//                     dp[i][j]=(i==0||j==0?1:dp[i-1][j-1]+1);
//                 }
//                 else{
//                     dp[i][j]=max(i==0?0:dp[i-1][j],j==0?0:dp[i][j-1]);
//                 }
//             }
//         }
//         // cout<<"  ";for(int i=0;i<b.length();i++)cout<<b[i]<<" ";cout<<endl;
//         // for(auto i=0;i<a.length();i++){
//         //     cout<<a[i]<<" ";
//         //     for(auto j=0;j<b.length();j++){
//         //         cout<<dp[i][j]<<" ";
//         //     }
//         //     cout<<endl;
//         // }
//         if(dp[a.length()-1][b.length()-1]==0){
//             cout<<"妹萌えこそ正義なのさ！\n";
//         }
//         else{
//             i=a.length()-1,j=b.length()-1;
//             dfs(i,j,"");
//             sort(pos_ans.begin(),pos_ans.end());
//             while(pos_ans.size()==0){} //
//             cout<<pos_ans[0]<<'\n';
//         }
//     }
// }
