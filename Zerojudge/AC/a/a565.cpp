#include<iostream>
#define X first
#define Y second
using namespace std;
int main(){
	int ts;
    cin.tie(0);
    ios_base::sync_with_stdio(0);
	cin>>ts;
    cin.ignore();
	while(ts--){
		string s;
		cin>>s;
		int l=s.length();
		int ans=0,cnt=0;
		for(int i=0;i<l;i++){
			if(s[i]=='.')continue;
			if(s[i]=='p'){
				cnt++;
			}
			else if(cnt){
				cnt--;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}
