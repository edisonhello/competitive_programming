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

int a[1449];
int buys[30];

int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    int t1,t2;cin>>t1>>t2;
    while(n--){
        int who;cin>>who;
        int lin,lot;cin>>lin>>lot;
        if(lin>t2){}
        else if(lot<t1){}
        else{
            if(lin<t1)lin=t1;
            if(lot>t2)lot=t2+1;
            ++a[lin];--a[lot];
        }
        int buy;cin>>buy;
        while(buy--){
            int tm;cin>>tm;
            char in;cin>>in;
            if(tm<t1||tm>t2)continue;
            ++buys[in-'A'];
        }
    }
    int hight=0,now=0;
    for(int i=t1;i<t2+5;++i){
        now+=a[i];
        // cout<<"time:"<<i<<" , now="<<now<<endl;
        hight=max(hight,now);
    }
    cout<<hight<<'\n';
    now=0;
    bool fstt=0;
    for(int i=0;i<1445;++i){
        now+=a[i];
        if(now==hight&&a[i]){
            if(fstt){
                cout<<" ";
            }
            cout<<i;
            fstt=1;
        }
        else if(now-a[i]==hight&&a[i]){
            cout<<" "<<i;
        }
    }
    cout<<'\n';
    int mxb=0;
    for(int i=0;i<26;++i){
        mxb=max(mxb,buys[i]);
    }
    if(mxb==0){
        cout<<"?\n";
    }
    else{
        bool fstt=0;
        for(int i=0;i<26;++i){
            if(buys[i]==mxb){
                if(fstt)cout<<" ";
                cout<<(char)(i+'A');
            }
        }
        cout<<'\n';
    }
}
