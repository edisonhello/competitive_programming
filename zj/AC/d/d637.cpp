#include<iostream>
#include<algorithm>
#define X first
#define Y second
#define ll long long
using namespace std;
int n;
vector<pair<int,int>> v;
int dp[10005][105];
int main(){
    cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++){
		cin>>v[i].X>>v[i].Y;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=100;j++){
			if(v[i].X<=j){
				dp[i+1][j]=max(dp[i][j],dp[i][j-v[i].X]+v[i].Y);
			}
			else{
				dp[i+1][j]=dp[i][j];
			}
		}
	}
	cout<<dp[n][100]<<endl;
}
