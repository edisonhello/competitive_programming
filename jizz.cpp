#include<iostream>
#include<iomanip>
#include<cmath>
#include<sstream>
#include<assert.h>
using namespace std;
int main(){
    int ts;cin>>ts;
    while(ts--){
        float r;cin>>r;
        stringstream ss;
        ss<<fixed<<r*r*acos(-1)*3/4;
        string s;
        ss>>s;
        int pos=s.find('.');
        if(pos==(int)string::npos)assert(1==0);
        if(s[pos+3]>'4'){
            s[pos+2]++;
            if(s[pos+2]>'9'){
                s[pos+2]='0';
                s[pos+1]++;
                if(s[pos+1]>'9'){
                    s[pos+1]='0';
                    s[pos-1]++;
                    for(int i=pos-1;i>=0;--i){
                        if(s[i]>'9'){
                            s[i]='0';
                            if(i==0){
                                cout<<1;
                            }
                            else{
                                s[i-1]++;
                            }
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
        cout<<s.substr(0,pos+3)<<endl;
    }
}
