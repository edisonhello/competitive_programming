#include<iostream>
#include<cstring>
#include<vector>
#define X first
#define Y second
using namespace std;
int main(){
	int n;
	int w;
	int dp[105][10005];
	vector<pair<int,int>> th;
	while(cin>>n){
		th.clear();
		th.resize(n);
		for(int i=0;i<n;i++){
			cin>>th[i].X>>th[i].Y;
		}
		cin>>w;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			for(int j=0;j<=w;j++){
				if(j>=th[i].X){
					dp[i+1][j]=max(dp[i][j],dp[i][j-th[i].X]+th[i].Y);
				}
				else{
					dp[i+1][j]=dp[i][j];
				}
				// cout<<dp[i+1][j]<<" ";
			}
			// cout<<endl;
		}
		cout<<dp[n][w]<<endl;
	}
}
