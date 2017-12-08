#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int rec[2000006];
int meow(int n){
    if(~rec[n])return rec[n];
    int nn=n; rec[n]=0;
    while(n){
        rec[nn]+=(n&1?1:-1)*(n%10);
        n/=10; 
    }
    return rec[nn]=abs(rec[nn]);
}

long long ans[2000006];
void init(){
    deque<int> dq; dq.push_back(meow(2)); 
    long long sum=2; int ptr=2;
    ans[1]=sum;
    for(int i=2;i<=1000000;++i){
        dq.push_back(meow(++ptr));
        sum+=dq.back();
        dq.push_back(meow(++ptr));
        sum+=dq.back();
        sum-=dq.front();
        dq.pop_front();
        ans[i]=ans[i-1]+sum*2-dq.back();
    }
}
 
int main(){
    for(int i=0;i<2000006;++i)rec[i]=-1;
    init();
    int t; cin>>t; while(t--){
        int n; cin>>n;
        cout<<ans[n]<<endl;
    }
}
// WA 350
// TLE 380
// AC 535
