namespace millerRabin{
#define ull unsigned long long
	ull ts[]={2,3,5,7,11,13,17,19,23,29,31,37};
	ull mul(ull b,ull n,ull m,ull a=0){
 	    b%=m; while(n){
	        if(n&1)a=(a+b)%m;
	        b=(b+b)%m; n>>=1;
	    } return a;
	}
	
	ull pow(ull b,ull n,ull m,ull a=1){
	    b%=m; while(n){
	        if(n&1)a=mul(a,b,m);
	        b=mul(b,b,m); n>>=1;
	    } return a;
	}
	
	bool isPrime(ull n,ull nn=0,ull a=0,int t=0){
	    if(n==2)return 1;
	    if(!(n&1) || n==1)return 0;
	    nn=n-1;
	    while(!(nn&1))nn>>=1,++t;
	    for(int ptr=0;ptr<12;++ptr){
	        a=ts[ptr]%n;
	        if(a==0 || a==1 || a==n-1)continue;
	        a=pow(a,nn,n);
	        if(a==1 || a==n-1)continue;
	        for(int i=0;i<t-1;++i){
	            a=mul(a,a,n);
	            if(a==1)return 0;
	            if(a==n-1)break;
	        }
	        if(a==n-1)continue;
	        return 0;
	    } return 1;
	}
#undef ull
}
