#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m; while(cin>>n>>m){
        int now=0;
        for(int i=1;i<=n;++i){
            stack<int> st;
            int ii=i;
            while(ii)st.push(ii%10),ii/=10;
            while(st.size()){
                now=now*10+st.top();
                now%=m;
                st.pop();
            }
        }
        cout<<now<<endl;
    }
}
