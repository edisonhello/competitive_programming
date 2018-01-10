// copy from UVa 10300
#include<bits/stdc++.h>
using namespace std;

int main(){
    int ts; cin>>ts; while(ts--){
        int n; cin>>n;
        long long x,y,a=0;
        while(n--){
            cin>>x>>y>>y;
            a+=x*y;
        }
        cout<<a<<endl;
    }
}
