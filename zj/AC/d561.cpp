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
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;


int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);
    // ld s;
    // while(cin>>s){
    //     if(s<0){
    //         s=-s;
    //         printf("-%.2llf\n",s+0.00000001);
    //     }
    //     else{
    //         printf("%.2llf\n",s+0.00000001);
    //     }
    // }
    string s;
    while(cin>>s){
        if(s[0]=='-'){
            if(s[5]>='5'){
                s[4]++;
                if(s[4]>'9'){
                    s[4]='0';
                    s[3]++;
                    if(s[3]>'9'){
                        s[3]='0';
                        s[1]++;
                    }
                }
            }
            string o=s.substr(0,5);
            while((int)o.length()<5){
                o+='0';
            }
            if(o=="-0.00"){
                o="0.00";
            }
            cout<<o<<endl;
        }
        else{
            if(s[4]>='5'){
                s[3]++;
                if(s[3]>'9'){
                    s[3]='0';
                    s[2]++;
                    if(s[2]>'9'){
                        s[2]='0';
                        s[0]++;
                    }
                }
            }
            string o=s.substr(0,4);
            while((int)o.length()<4){
                o+='0';
            }
            cout<<o<<endl;
        }
    }
}
