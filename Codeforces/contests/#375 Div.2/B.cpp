#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define pii pair<int,int>
#define rz(x) reserve(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))

int rit_t,rit_k;
char rit_c;
inline int rit();


int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);
    int n;string c;
    cin>>n>>c;
    n++;
    c+='_';
    string tmp="";
    int mx=0,inc=0;
    bool _=0;
    for(int i=0;i<n;i++){
        if(c[i]=='_'){
            if(!_){
                mx=max(mx,(int)tmp.length());
            }
            else{
                if(tmp!=""){
                    inc++;
                }
            }
            tmp="";
        }
        else if(c[i]=='('){
            if(!_){
                mx=max(mx,(int)tmp.length());
            }
            else{
                assert(1==0);
            }
            _=1;
            tmp="";
        }
        else if(c[i]==')'){
            if(!_){
                assert(1==0);
            }
            else{
                if(tmp!=""){
                    inc++;
                }
            }
            _=0;
            tmp="";
        }
        else{
            tmp+=c[i];
        }
    }
    cout<<mx<<" "<<inc<<endl;
}


inline int rit(){
    rit_t=0,rit_k=1;
    do{
        rit_c=getchar_unlocked();
        if(rit_c=='-')rit_k=-1;
    }while(rit_c<'0'||rit_c>'9');
    do{
        rit_t=rit_t*10+rit_c-'0';
        rit_c=getchar_unlocked();
    }while(rit_c>='0'&&rit_c<='9');
    return rit_t*rit_k;
}
