#include<bits/stdc++.h>
using namespace std;
int main(){
    int ts;
    cin>>ts;
    while(ts--){
        int n;
        cin>>n;
        long long ans=1;
        while(n--){
            long long t;
            cin>>t;
            ans*=(t-1);
        }
        cout<<ans<<endl;
    }
    /*jizzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz*/
}
