#include<iostream>
#include<cstring>
int step[20505][205];
using namespace std;
int main(){
	int n;
	memset(step,0x7f,sizeof(step));
	step[1][1]=1;
	for(int i=1;i<20001;i++){
		// if(i%1000==0)cout<<i<<endl;
		for(int j=1;j<204;j++){
			step[i+j-1][j-1]=min(step[i][j]+1,step[i+j-1][j-1]);
			step[i+j][j]=min(step[i][j]+1,step[i+j][j]);
			step[i+j+1][j+1]=min(step[i][j]+1,step[i+j+1][j+1]);
		}
	}
	while(cin>>n){
		cout<<step[n][1]<<endl;
	}
}
