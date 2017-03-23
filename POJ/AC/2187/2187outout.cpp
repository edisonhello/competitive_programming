#include<iostream>
#include<cstdlib>
#include<unistd.h>
using namespace std;
int main(){
    freopen("out","r",stdin);
    cout<<"answer: \n";
    string s,t;cin>>s>>t;
    cout<<s<<" , "<<t<<endl;
    if(s!=t)while(1);
    usleep(10000000);
}
