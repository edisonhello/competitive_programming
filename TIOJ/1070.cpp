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

string err[]={
    "",
    "Password settings are not consistent.\n",
    "Password should contain 8 to 12 characters.\n",
    "Password should contain at least one upper-case alphabetical character.\n",
    "Password should contain at least one lower-case alphabetical character.\n",
    "Password should contain at least one number.\n",
    "Password should contain at least one special character.\n",
    "Symmetric password is not allowed.\n",
    "Circular password is not allowed.\n"
};
string noerr="Password is valid.\n";
string specs="~!@#$%%^&*()_+|`-=\\{}[]:\";\'<>?,./";

string s,ss;
int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(cin>>s>>ss){
        if(s==ss&&s=="END"){
            break;
        }
        if(s!=ss){
            cout<<err[1];
            continue;
        }
        if(s.length()>12||s.length()<8){
            cout<<err[2];
            continue;
        }
        for(int i=0;i<(int)s.length();i++){
            if(s[i]>='A'&&s[i]<='Z'){
                goto hasUpp;
            }
        }
        cout<<err[3];
        continue;
        hasUpp:;
        for(int i=0;i<(int)s.length();i++){
            if(s[i]>='a'&&s[i]<='z'){
                goto hasLow;
            }
        }
        cout<<err[4];
        continue;
        hasLow:;
        for(int i=0;i<(int)s.length();i++){
            if(s[i]>='0'&&s[i]<='9'){
                goto hasNum;
            }
        }
        cout<<err[5];
        continue;
        hasNum:;
        for(int i=0;i<(int)s.length();i++){
            for(int j=0;j<(int)specs.length();j++){
                if(s[i]==specs[j]){
                    goto hasSpc;
                }
            }
        }
        cout<<err[6];
        continue;
        hasSpc:;
        for(int i=0;i<(int)s.length();i++){
            if(s[i]!=s[(int)s.length()-1-i]){
                goto noSym;
            }
        }
        cout<<err[7];
        continue;
        noSym:;
        for(int i=3;i<=6;i++){
            for(int j=0;j+i<(int)s.length();j++){
                if(s[j]!=s[i+j]){
                    goto cirNxt;
                }
            }
            cout<<err[8];
            goto hasCir;
            cirNxt:;
        }
        goto noCir;
        hasCir:;
        continue;
        noCir:;
        cout<<noerr;
        continue;
    }
}
