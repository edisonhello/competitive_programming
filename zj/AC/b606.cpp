#include<iostream>
#include<queue>
#define ll long long
#define X first
#define Y second
using namespace std;
int main(){
	int n;
	while(cin>>n,n){
		priority_queue<ll,vector<ll>,greater<ll>> pq;
		for(int i=0;i<n;i++){
			ll t;
			cin>>t;
			pq.push(t);
		}
		long long ans=0;
		while(pq.size()>1){
			ll a=pq.top();pq.pop();
			ll b=pq.top();pq.pop();
			ans+=(a+b);
			pq.push(a+b);
			// cout<<a<<" "<<b<<endl;
		}
		cout<<ans<<endl;
	}
}
