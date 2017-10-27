#include<iostream>
using namespace std;

#define i(a,b) if(p==a)p=b
#define ei(a,b) else if(p==a)p=b
#define v(x) void x(int &p)
#define r(a,b,c,d) i(a,b); ei(b,c); ei(c,d); ei(d,a);
#define def(a,b,c,d,e) v(a){r(b,c,d,e)}
def(R,1,5,7,4)
def(L,2,3,8,6)
def(F,1,4,3,2)
def(D,4,7,8,3)
def(U,1,2,6,5)
def(B,5,6,8,7)
#define ei else if
void turn(char t,int c,int &p){
    for(int i=0;i<c;++i){
        if(t=='R')R(p);
        ei(t=='L')L(p);
        ei(t=='F')F(p);
        ei(t=='D')D(p);
        ei(t=='U')U(p);
        else B(p);
    }
}
int main(){
    string s; while(cin>>s){
        int pos=1,ptr=0;
        while(ptr<s.size()){
            int t=1;
            char type=s[ptr]; ++ptr;
            if(ptr<s.size() && s[ptr]=='\'')t=3, ++ptr;
            turn(type,t,pos);
        }
        cout<<"("<<pos<<")"<<endl;
    }
}
