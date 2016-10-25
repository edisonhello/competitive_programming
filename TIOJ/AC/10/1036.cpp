#include<iostream>
using namespace std;
bool pmb[10000007];
int pm[10000007];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	pmb[1]=1;
	for(int i=2;i<10000002;i++){
		if(!pmb[i]){
			for(int j=i*2;j<10000002;j+=i){
				pmb[j]=1;
			}
			pm[i]=pm[i-1]+1;
		}
		else{
			pm[i]=pm[i-1];
		}
	}
	int m;cin>>m;
	while(m--){
		int n;cin>>n;
		cout<<pm[n]<<endl;
	}
}
