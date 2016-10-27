#include<iostream>
#include<map>
#include<sstream>
using namespace std;

int main(){
	string line;
	map<string,pair<int,int>> m;
	bool firs=1;
	while(getline(cin,line)){
		if(!firs)cout<<endl;
		firs=0;
		m.clear();
		for(char &c:line)if(!((c>='A'&&c<='Z')||(c>='a'&&c<='z')))c=' ';
		stringstream ss(line);
		while(ss>>line){
			for(char &c:line)if(c>='A'&&c<='Z')c+=32;
			// cout<<line<<" ";
			m[line].first++;
			// cout<<m[line].first<<endl;
		}
		getline(cin,line);
		for(char &c:line)if(!((c>='A'&&c<='Z')||(c>='a'&&c<='z')))c=' ';
		stringstream sss(line);
		while(sss>>line){
			for(char &c:line)if(c>='A'&&c<='Z')c+=32;
			m[line].second++;
		}
		bool out=0;
		for(auto i:m){
			// cout<<i.first<<" ";
			// cout<<i.second.first<<" "<<i.second.second<<endl;
			if(i.second.first>1&&i.second.second>1){
				cout<<i.first<<endl;
				out=1;
			}
		}
		if(!out){
			cout<<"<NONE>\n";
		}
	}
}
