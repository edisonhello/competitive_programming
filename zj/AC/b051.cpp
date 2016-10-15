#include<iostream>
#include<algorithm>
#define X first
#define Y second
using namespace std;
struct str{string s;} a[100005];
bool operator < (const str &a,const str &b){

	for(int i=0;i<(int)max(a.s.length(),b.s.length());i++){
		if(a.s[i%a.s.length()]!=b.s[i%b.s.length()])return a.s[i%a.s.length()]<b.s[i%b.s.length()];
	}
	return 1;
}
int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>a[i].s;
		}
		sort(a,a+n);
		reverse(a,a+n);
		for(int i=0;i<n;i++){
			//if(i)cout<<" ";
			cout<<a[i].s;
		}
		cout<<endl;
	}
}
