#include<iostream>
#include<stack>
using namespace std;
int a[1000005];
stack<int> s,ans;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=n-1;i>=0;--i){
        while(s.size() && a[i]>=s.top())s.pop();
        ans.push((int)s.size());
        s.push(a[i]);
    }
    while(ans.size()){
        cout<<ans.top()<<endl;ans.pop();
    }
}
