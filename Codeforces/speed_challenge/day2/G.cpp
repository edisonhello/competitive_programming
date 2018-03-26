#include<bits/stdc++.h>
using namespace std;

int main(){
    long long l,r; cin>>l>>r;
    if(r-l<=1 || (r-l==2 && (l&1))){
        cout<<-1;
        exit(0);
    }
    if(l&1)++l;
    cout<<l<<" "<<l+1<<" "<<l+2;
}
