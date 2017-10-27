#include<iostream>
#include<utility>
#include<bitset>
#define X first
#define Y second
using namespace std;
bitset<20000005> prm;
pair<int,int> ds[100005];
int pnt;
int main(){
	prm[0]=1;
	prm[1]=1;
	for(int i=2;i<=20000002 && pnt<100002;i++){
		// if(i%1000000==0){cout<<i<<endl;}
		if(prm[i])continue;
		else{
			for(int j=i*2;j<=20000002;j+=i){
				prm[j]=1;
			}
			if(!prm[i-2]){
				ds[++pnt]={i-2,i};
			}
		}

	}
	int s;
	while(cin>>s){
		cout<<"("<<ds[s].X<<", "<<ds[s].Y<<")"<<endl;
	}
}
