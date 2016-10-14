#include<iostream>
#include<sstream>
#define X first
#define Y second
#define ll long long
using namespace std;
ll dp[50005];
int val[]={1,5,10,20,50,100,200,500,1000,2000};
/*ll sol(int us,int lf){
	if(us>=10)return 0;
	cout<<"sol "<<us<<" "<<lf<<endl;
	if(dp[lf])return dp[lf];
	if(lf<0)return 0;
	for(int i=0;i*val[us]<=lf;i++){
		dp[lf]+=sol(us+1,lf-val[us]*i);
	}
	return dp[lf];
}*/
int main(){
	int n;
	string in;
	dp[0]=1;
	for(int i=0;i<10;i++){
		for(int j=val[i];j<50002;j++){
			dp[j]+=dp[j-val[i]];
		}
	}
	while(getline(cin,in)){
		stringstream ss;
		ss<<in;
		int t;
		n=0;
		while(ss>>t){
			n+=t;
		}
		if(n==0)continue;
		cout<<dp[n]-1<<endl;
	}
}
