// TIOJ 1965
#ifndef WEAK
#include"lib1965.h"
#endif

#define ull uint64_t
// ull *a,b[420000];
// int n,nblock,blockSize,blockST[420000][4][16],bigST[20][420000];
ull *a,*b;
int n,nblock,blockSize,*blockST[4][16],*bigST[20],*lg;

inline void jizz(){
    b=new ull[nblock+87];

    for(int i=0;i<4;++i){
        for(int j=0;j<blockSize+1;++j){
            blockST[i][j]=new int[nblock+87];
        }
    }

    int lognblock=ceil(log(nblock)/log(2));
    for(int i=0;i<lognblock+2;++i){
        bigST[i]=new int[nblock];
    }
}
inline void doLog(){
    lg=new int[n+5];
    lg[1]=lg[2]=0;
    for(int i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
}
inline ull buildBlockST(int n,int l,int r){
    int s=r-l+1; ull mx=0;
    for(int i=l;i<=r;++i)blockST[0][i-l][n]=i,mx=max(mx,a[i]);
    for(int i=1,d=1;d<s;++i,d<<=1){
        for(int j=l;j+(d<<1)-1<=r;++j){
            blockST[i][j-l][n] = a[blockST[i-1][j-l][n]] > a[blockST[i-1][j+d-l][n]] ? blockST[i-1][j-l][n] : blockST[i-1][j+d-l][n];
        }
    } return mx;
}
inline void buildBigST(){
    for(int i=0;i<nblock;++i)bigST[0][i]=i;
    for(int i=1,d=1;d<nblock;++i,d<<=1){
        for(int j=0;j+(d<<1)-1<nblock;++j){
            bigST[i][j] = b[bigST[i-1][j]] > b[bigST[i-1][j+d]] ? bigST[i-1][j] : bigST[i-1][j+d];
        }
    }
}
void init(int N,ull C[]){
    a=C; n=N; blockSize=ceil(log(n)/log(2)/2), nblock=ceil((double)n/blockSize);
    jizz(); doLog();
    for(int i=0;i<nblock;++i)b[i]=buildBlockST(i,i*blockSize,min((i+1)*blockSize-1,n-1));
    buildBigST();
}

inline ull queryBlock(int n,int l,int r){
    int d=r-l+1;
    int lv=lg[d],nblockSize=n*blockSize;
    return max(a[blockST[lv][l-nblockSize][n]],a[blockST[lv][r-(1<<lv)+1-nblockSize][n]]);
}
inline ull queryBig(int l,int r){
    if(r<l)return 0;
    int d=r-l+1;
    int lv=lg[d];
    return max(b[bigST[lv][l]],b[bigST[lv][r-(1<<lv)+1]]);
}
ull RMQ(int l,int r){
    if(r-l==1)return a[l]; --r;
    int lblock=l/blockSize;
    int rblock=r/blockSize;
    PDE4(l,r,lblock,rblock);
    if(lblock==rblock){
        return queryBlock(lblock,l,r);
    }
    else{
        return max(queryBlock(lblock,l,(lblock+1)*blockSize-1)
              ,max(queryBig(lblock+1,rblock-1)
                  ,queryBlock(rblock,rblock*blockSize,r)));
    }
}


#ifdef WEAK
ull C[10000007];
int main(){
    int N;cin>>N;
    for(int i=0;i<N;++i)cin>>C[i];
    init(N,C);
    int M;cin>>M;
    for(int i=0;i<M;++i){
        int L,R;cin>>L>>R;
        cout<<RMQ(L,R)<<endl;
    }
}
#endif
