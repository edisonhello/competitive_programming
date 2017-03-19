#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;


int main(){
    int n;string s;
    char c[2005];
    cin>>n>>s;
    if(n&1){
        int r=n/2,l=n/2-1;
        for(int i=0;i<n;++i){
            if(i&1){
                c[l--]=s[i];
            }else{
                c[r++]=s[i];
            }
        }
        for(int i=0;i<n;++i)cout<<c[i];cout<<endl;
    }else{
        int r=n/2,l=n/2-1;
        for(int i=0;i<n;++i){
            if(!(i&1)){
                c[l--]=s[i];
            }else{
                c[r++]=s[i];
            }
        }
        for(int i=0;i<n;++i)cout<<c[i];cout<<endl;
    }
}
