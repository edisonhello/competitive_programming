#include<ctime>
#include<cstdio>
#include<climits>
#include<cstdlib>
#include<iostream>
using namespace std;

int N;
int a[255555];
bool append[255555];

int rd(int rg=N){
    int rt=rand()*RAND_MAX+rand();
    rt%=rg;rt+=rg;rt%=rg;return ++rt;
}
int rdp(){
    int primes[4]={6565877,25645343,948112819,446524913};
    return primes[rand()%4];
}

int main(){
    freopen("26.in","w",stdout);
    srand(time(NULL));

    N=20000;
    int empty=rd(N);
    int fill=N-empty;
    // cout<<N<<" "<<empty<<endl;
    for(int iiii=0,ptr=0;iiii<fill;++iiii){
        int lop=rd(N-iiii)-1;
        while(lop){
            while(a[ptr]){++ptr;if(ptr>N)ptr-=N;}
            ++ptr;if(ptr>N)ptr-=N;--lop;
        }
        int app=rd(N);
        while(append[app] && app==ptr)app=rd(N);
        append[app]=1;
        a[ptr]=app;
    }

    cout<<N<<" "<<(rd(5)==1?rdp():rd(123456789))<<endl;
    for(int i=1;i<=N;++i){
        if(!a[i])cout<<-1<<" ";
        else cout<<a[i]<<" ";
    }
    cout<<endl;
}
