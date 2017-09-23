#include<iostream>
#include<algorithm>
#define X first
#define Y second
using namespace std;
string fi[105];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>fi[i];
		fi[i]="-"+fi[i]+"-";
	}
	for(int i=0;i<=n+1;i++){
		fi[0]+='-';
		fi[n]+='-';
	}
	int dx[8]={0,1,1, 1, 0,-1,-1,-1};
	int dy[8]={1,1,0,-1,-1,-1, 0 ,1};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(fi[i][j]=='*')continue;
			int cnt=0;
			for(int k=0;k<8;k++){
				if(fi[i+dx[k]][j+dy[k]]=='*'){
					cnt++;
				}
			}
			if(cnt){
				fi[i][j]=cnt+'0';
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<fi[i][j];
		}
		cout<<endl;
	}
}
