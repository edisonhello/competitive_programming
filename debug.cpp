#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PB(x) push_back(x)
#define X first
#define Y second

int ouo(int base,int pow){
    int ans=1;
    while(pow){
        if(pow&1){
            ans*=base;
        }
        base*=base;
        pow>>=1;
    }
    return ans;
}

int main(){
    cout<<ouo(3,5)<<endl;
}
