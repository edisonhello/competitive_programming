#include<iostream>
#define ll long long
using namespace std;
int main(){
	int w;
	while(cin>>w){
		ll dp[8005]={0};
		int v[]={1,13,33,43,139,169,1309,2597};
		int n=8;
		dp[0]=1;
		for(int i=0;i<n;i++){
			for(int j=v[i];j<=w;j++){
				dp[j]+=dp[j-v[i]];
			}
		}
		cout<<dp[w]<<endl;
	}
}
