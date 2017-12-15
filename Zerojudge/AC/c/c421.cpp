// copy from TIOJ 1911
#include<cstdio>
#include<bitset>
#include<queue>
using namespace std;
struct w{int n,v;};
bool operator<(const w &a,const w &b){return a.v<b.v;}
bool operator>(const w &a,const w &b){return a.v>b.v;}
priority_queue<w,vector<w>,greater<w>> bpq;
priority_queue<w,vector<w>,less<w>> spq;
bitset<500005> v;
int main(){
	int nw=0,tp;bool fstop=0;
	while(scanf("%d",&tp)!=EOF,tp){
		if(tp>0){
			bpq.push({nw,tp});
			spq.push({nw,tp});
			++nw;
		}
		else if(tp==-2){
			while(spq.size() && v[spq.top().n])spq.pop();
			if(spq.empty())continue;
			v[spq.top().n]=1;
			if(fstop)printf(" ");
			fstop=1;
			printf("%d",spq.top().v);
		}
		else if(tp==-1){
			while(bpq.size() && v[bpq.top().n])bpq.pop();
			if(bpq.empty())continue;
			v[bpq.top().n]=1;
			if(fstop)printf(" ");
			fstop=1;
			printf("%d",bpq.top().v);
		}
	}
	printf("\n");
}
