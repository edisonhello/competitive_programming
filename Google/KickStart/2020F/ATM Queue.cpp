


#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >>t;
    for(int T=1;T<=t;T++){
        cout<<"Case #"<<T<<": ";
        int n,x; cin>>n>>x;
        vector<pair<int,int>> a;
        for(int i=0; i<n;i++){
            int z; cin>>z;
            a.emplace_back((z-1)/x,i);
        }
        sort(a.begin(), a.end());
        vector<int>b(n);
        for(int i=0;i<n;i++){
            b[i]=a[i].second;
        }
        for(int i=0;i<n;i++){
            cout << b[i]+1 << ' ';
        }
        cout << endl;
    }
}
