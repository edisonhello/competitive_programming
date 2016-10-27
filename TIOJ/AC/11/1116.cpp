#include<iostream>
#include<cstdio>
#define abs(x) (((x)>0)?(x):(-(x)))
using namespace std;
int main(){
	string s;
	while(cin>>s){
		s=s+s+s;
		for(int i=4;i<8;++i){
			if(i-4)cout<<", ";
			if(s[i]=='b'){
				cout<<"X";
				continue;
			}
			bool out=0;
			if(s[i-1]=='b'||s[i-1]=='c'){
				out=1;
				cout<<"A";
			}
			if(s[i+1]=='b'||s[i+1]=='c'){
				out=1;
				cout<<"B";
			}
			if(s[i+2]=='b'||s[i+2]=='c'){
				out=1;
				cout<<"C";
			}
			if(!out){
				cout<<"Y";
			}
		}
		cout<<endl;
	}
}
