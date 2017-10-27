#include<cstdio>
using namespace std;
namespace millerRabin{
#define ull unsigned long long
	ull ts[]={17,31};
	inline ull pow(ull b,ull n,ull m,ull a=1){
	    b%=m; while(n){
	        if(n&1)a=a*b%m;
	        b=b*b%m; n>>=1;
	    } return a;
	}
	
	inline bool isPrime(ull n,ull nn=0,ull a=0,int t=0){
	    if(n==2)return 1;
	    if(!(n&1) || n==1)return 0;
	    nn=n-1;
	    while(!(nn&1))nn>>=1,++t;
	    for(int ptr=0;ptr<2;++ptr){
	        a=ts[ptr]%n;
	        if(a==0 || a==1 || a==n-1)continue;
	        a=pow(a,nn,n);
	        if(a==1 || a==n-1)continue;
	        for(int i=0;i<t-1;++i){
	            a=a*a%n;
	            if(a==1)return 0;
	            if(a==n-1)break;
	        }
	        if(a==n-1)continue;
	        return 0;
	    } return 1;
	}
#undef ull
}
int main(){
    int ts; scanf("%d",&ts); while(ts--){
        int l,r,d,c=0; scanf("%d%d",&l,&r);
        d=r-l+1;
        for(int i=0;i<d;++i)if(millerRabin::isPrime(i+l))++c;
        printf("%d\n",c);
    }
}
