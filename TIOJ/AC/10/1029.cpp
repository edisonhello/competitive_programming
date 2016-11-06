#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,a[1005],dpa[1005][1005],tot;
inline void rit(int &__t){
    char __c;__t=0;
    do{__c=getchar();}while((__c<'0'||__c>'9'));
    do{__t=__t*10+__c-'0';__c=getchar();}while(__c>='0'&&__c<='9');
}
int dp(int l,int r){
	if(dpa[l][r])return dpa[l][r];
	if(l==r)return dpa[l][r]=a[l];
	if(l>r)return 0;
	if(!((r-l)&1))return dpa[l][r]=max(dp(l+1,r)+a[l],dp(l,r-1)+a[r]);
	else return dpa[l][r]=min(dp(l+1,r),dp(l,r-1));
}

int main(){
	rit(n);
	for(int i=1;i<=n;++i){
		rit(a[i]);
		tot+=a[i];
	}
	if(n&1)printf("%d %d\n",dp(1,n),tot-dp(1,n));
    else printf("%d %d\n",tot-dp(1,n),dp(1,n));
}
