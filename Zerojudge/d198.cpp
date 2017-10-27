#include<iostream>
#include<sstream>
#define ll long long
using namespace std;
int main(){
	ll ts,w,n;
	cin>>ts;
	while(ts--){
		cin>>w>>n;
		unsigned ll a[105][105]={0};
		bool da[105][105]={0};
		cin.ignore();
		string s;
		for(ll i=1,j;i<=w;i++){
			getline(cin,s);
			stringstream ss(s);
			ss>>j;
			while(ss>>j){
				da[i][j]=1;
			}
		}
		a[1][1]=1ll;
		for(ll i=1;i<=w;i++){
			for(int j=1;j<=n;j++){
				if(da[i][j])continue;
				a[i][j]+=a[i-1][j];
				a[i][j]+=a[i][j-1];
			}
		}
		if(da[w][n])cout<<"0"<<endl;
		else cout<<a[w][n]<<endl;
		if(ts)cout<<endl;
	}
}
