
struct sADD{ int x,mod; sADD(int mod):mod(mod){} } ADD(mod);
sADD& operator<(int x,sADD &op){ op.x=x; return op; }
int operator>(const sADD &op,const int y){ int v=op.x+y; if(v>=op.mod)v-=op.mod; return v; }

struct sSUB{ int x,mod; sSUB(int mod):mod(mod){} } SUB(mod);
sSUB& operator<(int x,sSUB &op){ op.x=x; return op; }
int operator>(const sSUB &op,const int y){ int v=op.x-y; if(v<0)v+=op.mod; return v; }

struct sTMS{ int x,mod; sTMS(int mod):mod(mod){} } TMS(mod);
sTMS& operator<(int x,sTMS &op){ op.x=x; return op; }
int operator>(const sTMS &op,const int y){ int v=1ll*op.x*y%op.mod; return v; }

int POW(int b,int n,int a=1){
    if(!n)return !b?b:a;
    if(n&1)return POW(b<TMS>b,n>>1,a<TMS>b);
    else return POW(b<TMS>b,n>>1,a);
}

struct sINV{ int mod; sINV(int mod):mod(mod){} 
    int operator()(const int x)const{ return POW(x,mod-2); }
} INV(mod);

struct sDIV{ int x,mod; sDIV(int mod):mod(mod){} } DIV(mod);
sDIV& operator<(int x,sDIV &op){ op.x=x; return op; }
int operator>(const sDIV &op,const int y){ int v=op.x<TMS>INV(y); return v; }
