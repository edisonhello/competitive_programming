#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	while(cin>>s){
		unsigned ans=0;
		unsigned e=0,meow=1;
		bool yn=1;
		for(int i=0;i<s.size();i++){
			if(i!=0&&(s[i]<=s[i-1])){
				cout<<0<<endl;
				yn=0;
				break;
			}
			else{
				cout<<"ans="<<ans<<" meow="<<meow<<endl;
				ans=(ans*meow+s[i]-'a'+1);
				e++;
				meow*=26-(s[i]-'a'+1);
			}
		}
		if(yn)cout<<ans<<endl;
	}
	return 0;
}
