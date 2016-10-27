#include<iostream>
#include<cstdio>
#include<map>
#define abs(x) (((x)>0)?(x):(-(x)))
using namespace std;
map<long long,bool> m;
int main(){
	int n;
	while(cin>>n){
		m.clear();
		for(int i=0;i<n;++i){
			long long t;cin>>t;
			m[t]^=1;
		}
		for(auto i:m){
			if(i.second){
				cout<<i.first<<'\n';
				break;
			}
		}
	}
}
