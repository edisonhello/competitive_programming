#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;
int a,b;
stack<bool> s;
// ll rec[65][65];

// int main(){
// 	for(int i=1;i<61;i++){
// 		for(int j=1)
// 	}
// }

int main(){
	while(cin>>a>>b){
	    long long k=1;
	    while(1){
	    	if(a==b){
	    		// cout<<k<<endl;
	    		break;
	    	}
	    	if(a>b){
	    		// k*=2;
	    		s.push(1);
	    		a-=b;
	    	}
	    	else{
	    		swap(a,b);
	    		// k++;
	    		s.push(0);
	    	}
	    }
	    while(s.size()){
	    	if(s.top()){
	    		k*=2;
	    	}
	    	else{
	    		k++;
	    	}
	    	s.pop();
	    }
	    cout<<k<<endl;
	}
}
