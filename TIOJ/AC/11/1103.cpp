#include<iostream>
#include<iomanip>
using namespace std;
int m[3][20005];
int ans[10005];

void init(){
	m[1][1]=m[1][2]=m[1][3]=1;
	ans[1]=1;
	for(int i=2;i<=10002;++i){
		for(int j=1;j<2*(i+1);++j){
			m[i%2][j]=(m[i%2][j-1]+m[(i-1)%2][j])%10000;
			//cout<<"m["<<i<<"]["<<j<<"]="<<m[i%2][j]<<endl;
		}
		ans[i]=m[i%2][2*(i+1)-1];
	}
}

int main(){
	init();
	int n;while(cin>>n,n){
		if(n>7)cout<<setfill('0')<<setw(4)<<ans[n]<<endl;
		else cout<<ans[n]<<endl;
	}
}
