#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#define X first
#define Y second
using namespace std;
map<string,int> id;
unordered_map<int,int> m;
int GI(string in){
	auto f=id.find(in);
	if(f==id.end()){
		return id[in]=id.size();
	}
	return f->Y;
}
pair<string,int> GN(int n){
	for(auto i:id){
		if(i.Y==n){
			return i;
		}
	}
}
int main(){
	int ts;cin>>ts;
	for(int i=1;i<=ts;i++){
		cout<<"Case #"<<i<<":\n";
		id.clear();
		m.clear();
		// cout<<id.size()<<" "<<m.size()<<endl;
		for(int i=0;i<10;i++){
			string add;cin>>add;
			int n;cin>>n;
			int id=GI(add);
			m[id]+=n;
		}
		int mx=0;
		for(auto i:m){
			mx=max(mx,i.Y);
		}
		vector<pair<int,string>> anss;
		for(auto i:m){
			if(i.Y==mx){
				auto rt=GN(i.X);
				anss.push_back({rt.Y,rt.X});
			}
		}
		sort(anss.begin(),anss.end());
		for(auto i:anss){
			cout<<i.Y<<endl;
		}
	}
}
