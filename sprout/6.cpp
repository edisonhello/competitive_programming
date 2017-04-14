#include <iostream>

using namespace std;

int fc(int a){
	int cnt=0,b;for(b=1;b*b<a;b++){if(a%b==0){cnt+=2;}}
	if(b*b==a){cnt++;}return cnt;
}

int main(){
	ios_base::sync_with_stdio(0);int t;cin>>t;
	for(int i=1;i<=t;i++){int a;cin>>a;cout<<fc(a)<<endl;}
}
