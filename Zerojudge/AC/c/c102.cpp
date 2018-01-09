// copy from UVa 128
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; while(getline(cin,s)){
        if(s=="#")break;
        long long n=0;
        
        for(char c:s){
            n=n*256+c;
            n%=34943;
        }
        n=n*256*256%34943;
        n=(34943-n)%34943;
        printf("%02X %02X\n",n/256,n%256);
    }
}
