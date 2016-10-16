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


int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    string s,ss;
    while(cin>>s>>ss){
        if(s=="END" && ss=="END")break;
        if(s!=ss){
            cout<<"Password settings are not consistent.\n";
            continue;
        }
        if((int)s.length()<8 || (int)s.length()>12){
            cout<<"Password should contain 8 to 12 characters.\n";
            continue;
        }
        {
            bool UC=0,LC=0,NM=0,SP=0;
            string sps="~!@#$%%^&*()_+|`-=\\{}[]:\";\'<>?,./";
            for(char c:s){
                if(c>='A'&&c<='Z')UC=1;
                if(c>='a'&&c<='a')LC=1;
                if(c>='0'&&c<='9')NM=1;
                if(!SP)for(int i=0;i<(int)sps.length();++i)if(c==sps[i]){SP=1;break;}
            }
            if(!UC){
                cout<<"Password should contain at least one upper-case alphabetical character.\n";
                continue;
            }
            if(!LC){
                cout<<"Password should contain at least one lower-case alphabetical character.\n";
                continue;
            }
            if(!NM){
                cout<<"Password should contain at least one number.\n";
                continue;
            }
            if(!SP){
                cout<<"Password should contain at least one special character.\n";
                continue;
            }
        }
        {
            for(int i=0;i<(int)s.length()/2+1;++i){
                if(s[i]!=s[s.length()-1-i])goto notSym;
            }
            cout<<"Symmetric password is not allowed.\n";
            continue;
            notSym:;
        }
        {
            for(int lp=3;lp<=6;++lp){
                for(int i=lp;i<(int)s.length();++i){
                    if(s[i]!=s[i-lp])goto nxt;
                }
                cout<<"Circular password is not allowed.\n";
                goto nextPart;
                nxt:;
            }
            goto FREE;
            nextPart:;
            continue;
            FREE:;
        }
        cout<<"Password is valid.\n";
    }
}
