#define max(a,b) ((a)>(b)?(a):(b))
#ifndef WEAK
    #include"lib1278.h"
    const int N=20000;
#else
    const int N=4;
    void Initialize(){}
    int Query(char *num,int len){
        for(int i=0;i<len;++i){
            cout<<num[i];
        } cout<<endl;
        int rt; cin>>rt; return rt;
    }
    void Answer(char *num,int len){
        for(int i=0;i<len;++i){
            cout<<num[i];
        } cout<<endl;
    }
#endif

char get16(int x){
    if(x<=9)return x+'0';
    else return x-10+'a';
}

char num[N+88],*front;
int len=N;
int main(){
    Initialize();
    for(int i=0;i<=N;++i)num[i]='0';
    front=num;
    for(int i=0;i<N;++i){
        int L=0,R=15;
        while(R>L){
            int M=(L+R+1)>>1;
            num[i]=get16(M);
            if(Query(front,len))R=M-1;
            else L=M;
        }
        num[i]=get16(L);
        if(len+i==N && L==0){
            --len; ++front;
        }
    } Answer(front,max(len,1));
}
