#include<iostream>
#include<queue>
using namespace std;
struct s{int x,y,d;};
bool ji[102][102],v[102][102];
int n,sx,sy,ex,ey;
int mx[8]={-1,1,3,3,1,-1,-3,-3},
	my[8]={3,3,1,-1,-3,-3,-1,1};
queue<s> q;
int main(){
	cin>>n;
	while(n--){
		int jx,jy;cin>>jx>>jy;
		ji[jx][jy]=1;
	}
	cin>>sx>>sy>>ex>>ey;
	q.push({sx,sy,0});
	v[sx][sy]=1;
	while(q.size()){
		s t=q.front();q.pop();
		if(t.x==ex && t.y==ey){
			cout<<t.d<<endl;
			return 0;
		}
		for(int i=0;i<8;++i){
			if(t.x+mx[i]<0)continue;
			if(t.y+my[i]<0)continue;
			if(t.x+mx[i]>99)continue;
			if(t.y+my[i]>99)continue;
			if((i>>1)==0 && ji[t.x][t.y+1])continue;
			if((i>>1)==1 && ji[t.x+1][t.y])continue;
			if((i>>1)==2 && ji[t.x][t.y-1])continue;
			if((i>>1)==3 && ji[t.x-1][t.y])continue;
			if(!ji[t.x+mx[i]][t.y+my[i]] && !v[t.x+mx[i]][t.y+my[i]]){
				v[t.x+mx[i]][t.y+my[i]]=1;
				q.push({t.x+mx[i],t.y+my[i],t.d+1});
			}
		}
	}
	cout<<"impossible\n";
}
