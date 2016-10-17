#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define X first
#define Y second
#define S(x) (int)(x).size()
#define rz(x) reserve(x)
#define PB(x) push_back(x)
#define pii pair<int,int>
#define vint vector<int>
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define SS stringstream
#define PQ priority_queue
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
// #define getchar getchar_unlocked
// #define putchar putchar_unlocked
#define PVC(x) for(auto ___:(x))cout<<___<<" ";cout<<endl;
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;

char __c;bool __m;int __t;
inline int rit();
template<typename varType>
inline bool rit(varType &inp);
template<typename varType,typename ...Args>
inline bool rit(varType &inp,Args &...args);
struct __{int x,y,n,r,l,llcp;} _[200005];

int n,lat[200005],hei[200005],mxh;
string s;
bool c1(const __ &a,const __ &b){return (a.x==b.x?a.y<b.y:a.x<b.x);}
bool c2(const __ &a,const __ &b){return a.n<b.n;}

char G(int a,int b){
    return (a+b>=n?'-':s[a+b]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>s;
    // n=s.length();
    for(int i=0;i<n;++i){
        _[i].n=i;
        _[i].l=n-i;
        _[i].x=s[i];
    }


    sort(_,_+n,c1);
    _[0].r=1;
    for(int i=1;i<n;++i){
        if(c1(_[i-1],_[i]))_[i].r=_[i-1].r+1;
        else _[i].r=_[i-1].r;
    }
    for(int i=0;i<n;++i){
        _[i].x=_[i].r;
    }
    sort(_,_+n,c2);

    for(int j=1;j<=n;j<<=1){
        for(int i=0;i<n;++i){
            _[i].y=(i+j<n?_[i+j].x:0);
        }

        sort(_,_+n,c1);
        _[0].r=1;
        for(int i=1;i<n;++i){
            if(c1(_[i-1],_[i]))_[i].r=_[i-1].r+1;
            else _[i].r=_[i-1].r;
        }
        for(int i=1;i<n;++i){
            _[i].x=_[i].r;
        }
        sort(_,_+n,c2);
    }
    sort(_,_+n,c1);
    for(int i=0;i<n;++i){
        lat[_[i].l]=i+1;
    }
    // cout<<"n ";for(int i=0;i<n;++i)cout<<_[i].n<<' ';cout<<endl;
    // cout<<"l ";for(int i=0;i<n;++i)cout<<_[i].l<<' ';cout<<endl;
    // cout<<"lat ";for(int i=1;i<=n;++i)cout<<lat[i]<<' ';cout<<endl;
    for(int i=2,lcpl=0;i<n;++i,lcpl=lcpl<0?0:lcpl){
        // LCP
        while(G(_[lat[i]-2].n,lcpl)==G(_[lat[i]-1].n,lcpl))++lcpl;
        hei[i]=lcpl;
        mxh=max(mxh,hei[i]);
        --lcpl;
    }
    // cout<<"_[i].n ";for(int i=1;i<=n;++i)cout<<_[i].n<<' ';cout<<endl;
    // cout<<"_[i].l ";for(int i=1;i<=n;++i)cout<<_[i].l<<' ';cout<<endl;
    // cout<<"lat[i] ";for(int i=1;i<=n;++i)cout<<lat[i]<<' ';cout<<endl;
    // cout<<"hei[i] ";for(int i=1;i<=n;++i)cout<<hei[i]<<' ';cout<<endl;
    // cout<<endl;
    // for(int i=1;i<=n;++i){
    //     cout<<"h:"<<hei[i]<<" ";
    //     for(int j=0;j<n;++j){
    //         cout<<G(j,_[lat[i]-1].n);
    //     }
    //     cout<<endl;
    // }
    cout<<mxh<<'\n';
    // for(int i=0;i<n;++i)cout<<
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
