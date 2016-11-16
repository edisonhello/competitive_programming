#include<random>
#include<cstdio>
#include<unordered_map>
#include<utility>
using namespace std;
int v[10005];
unordered_map<int,pair<int,int>> m[10005];
inline int rit(){
    int t=0;char c;
    do{c=getchar();}while(c<'0'||c>'9');
    do{t=t*10+c-'0';c=getchar();}while(c>='0'&&c<='9');
    return t;
}
int main(){
    int n,q,c,s,e,a,t,p,r;
    n=rit(),q=rit();
    srand(712234);
    while(q--){
        c=rit();
        if(c==0){
            s=rit(),e=rit();
            if(e<s)s^=e,e^=s,s^=e;
            if(m[s][e].first==0){
                r=rand();
                m[s][e].second=r;
                v[s]^=r,v[e]^=r;
            }
            ++m[s][e].first;
        }
        else if(c==1){
            s=rit(),e=rit();
            if(e<s)s^=e,e^=s,s^=e;
            if(m[s][e].first==1){
                v[s]^=m[s][e].second;
                v[e]^=m[s][e].second;
            }
            --m[s][e].first;
        }
        else if(c==2){
            t=0;a=rit();
            while(a--){
                p=rit();
                t^=v[p];
            }
            if(t){putchar('0');putchar('\n');}
            else {putchar('1');putchar('\n');}
        }
    }
}
