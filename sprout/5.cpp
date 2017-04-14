#include<iostream>
#include<stdio.h>

using namespace std;

bool prime(int a){
	bool is = true;
	if(a == 1){
		return false;
	}
	for(int i = 2;i*i <= a;i++){
		if(a%i == 0){
			is = false;
			break;
		}
	}

	return is;
}

int main(){
	ios_base::sync_with_stdio(0);
	int t;cin>>t;
	for(int i = 1;i <= t;i++){
		int findprime;
		cin>>findprime;
		if(prime(findprime)){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
}
