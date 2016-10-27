#include<iostream>
#include<cstdio>
#define abs(x) (((x)>0)?(x):(-(x)))
using namespace std;
int step;
void move(int st,int dis,int lv){
	if(st==dis)return;
	if(abs(st-dis)>1){
		printf("#%d : move the dish from #%d to #2\n",step++,st);
		printf("#%d : move the dish from #2 to #%d\n",step++,dis);
	}
	else printf("#%d : move the dish from #%d to #%d\n",step++,st,dis);
}
void hn(int lv,int st,int dis,int md){
	if(lv==1){
		move(st,dis,lv);
		return;
	}
	if(abs(st-dis)>1){
		hn(lv-1,st,dis,md);
		move(st,2,lv);
		hn(lv-1,dis,st,md);
		move(2,dis,lv);
		hn(lv-1,st,dis,md);
		return;
	}
	else{
		hn(lv-1,st,md,dis);
		move(st,dis,lv);
		hn(lv-1,md,dis,st);
		return;
	}
}
int main(){
	int n;cin>>n;
	step++;
	hn(n,1,3,2);
}
