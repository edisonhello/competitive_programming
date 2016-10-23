#include<iostream>
#include<assert.h>
#include<cstring>
#define m (l+r)/2
using namespace std;
int a[105];
int mxv;

int main(){
	int ts;cin>>ts;

	while(ts--){
		int n;
		cin>>n;
		mxv=-989898;
		int ans=0;
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			mxv=max(a[i],mxv);
			sum+=a[i];
			if(sum<0)sum=0;
			ans=max(ans,sum);
		}
		if(mxv<=0){
			cout<<mxv<<endl;
			// continue;
		}
		else{
			cout<<ans<<endl;
		}

	}
}
