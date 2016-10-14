#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
stack<int> step;
int dfs(int l,int pr){
	if(l==0&&pr==1){
		return 1;
	}
	if(l<0||(l==0&&pr!=1)){
		return 0;
	}
	if((pr-1)*(pr-1)/2>l)return 0;
	step.push(pr+1);
	if(dfs(l-pr-1,pr+1))return 1;
	step.pop();
	step.push(pr);
	if(dfs(l-pr,pr))return 1;
	step.pop();
	step.push(pr-1);
	if(dfs(l-pr+1,pr-1))return 1;
	step.pop();
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n){
		step.push(1);
		dfs(n-1,1);
		bool fst=1;
		while(step.size()){
			if(fst){
				fst=0;
				cout<<step.top();
				step.pop();
			}
			else{
				cout<<" "<<step.top();
				step.pop();
			}
		}
		cout<<'\n';
	}
}
