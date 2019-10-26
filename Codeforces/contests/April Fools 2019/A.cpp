#include <bits/stdc++.h>
using namespace std;

int a[22];

int main() {
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=n;i;i>>=1){
        for(int j=0;j<n;j+=i){
            bool ok=1;
            for(int k=j+1;k<j+i;++k){
                if(a[k]<a[k-1])ok=0;
            }
            if(ok){
                cout<<i<<endl;
                exit(0);
            }
        }
    }
}
