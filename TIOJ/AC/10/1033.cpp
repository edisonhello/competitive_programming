#include<stdio.h>
char __c;bool __m;int __t;
inline int rit();
template<typename varType>
inline bool rit(varType &inp);
template<typename varType,typename ...Args>
inline bool rit(varType &inp,Args &...args);
int k,n,p[3][55][15];
int main(){
    rit(k,n);
    k=2*k+1;
    for(int i=0;i<n;i++){
        int S=rit();
        for(int j=0;j<3;j++){
            for(int l=0;l<k;l++){
                scanf("%d",&p[j][S][l]);
            }
        }
    }
    for(int i=n;i>0;i--){
        for(int j=1;j<=n;j++){
                // cout<<"NM "<<i<<" "<<j<<endl;
            if(i==j)continue;
            int ii=0,ji=0,win=0;
            while(ii<k && ji<k){
                if(p[0][i][ii]>p[0][j][ji]){
                    ii++,ji++,win++;
                }
                else if(p[0][i][ii]<p[0][j][ji]){
                    ji++;
                }
                else{
                    if(i>j){
                        ji++;
                    }
                    else{
                        ii++,ji++,win++;
                    }
                }
            }
            if(win<=(k>>1))goto thisIjizz;
        }
        printf("%d ",i);
        break;
        thisIjizz:;
    }
    for(int i=n;i>0;i--){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            int ii=0,ji=0,win=0;
            while(ii<k && ji<k){
                if(p[1][i][ii]>p[2][j][ji]){
                    ii++,ji++,win++;
                }
                else if(p[1][i][ii]<p[2][j][ji]){
                    ji++;
                }
                else{
                    if(i>j){
                        ji++;
                    }
                    else{
                        ii++,ji++,win++;
                    }
                }
            }
            if(win<=(k>>1))goto thisIjizz_;
        }
        printf("%d\n",i);
        break;
        thisIjizz_:;
    }
}

inline int rit(){
    __t=0,__m=0;
    do{
        __c=getchar();
    }while((__c<'0'||__c>'9')&&(__c!='-'));
    if(__c=='-')__m=1;
    do{
        __t=__t*10+__c-'0';
        __c=getchar();
    }while(__c>='0'&&__c<='9');
    if(__m)__t=-__t;
    return __t;
}

template<typename varType,typename ...Args>
inline bool rit(varType &inp,Args &...args){
    return rit(inp)&&rit(args...);
}

template<typename varType>
inline bool rit(varType &inp){
    inp=0;__m=0;
    do{
        __c=getchar();
        if(__c==-1)return false;
    }while((__c<'0'||__c>'9')&&__c!='-');
    if(__c=='-')__m=1;
    do{
        inp=inp*10+__c-'0';
        __c=getchar();
    }while(__c>='0'&&__c<='9');
    if(__m)inp=-inp;
    return true;
}
