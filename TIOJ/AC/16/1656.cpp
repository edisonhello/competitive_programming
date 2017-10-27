#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n; while(cin>>n){
        int ans=0;
        while(n%3==0 && ans<3){
            n/=3;
            ++ans;
        }
        cout<<(ans&1?"sad":"happy")<<endl;
    }
}
