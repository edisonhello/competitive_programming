#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a;
    vector<int> b;
    vector<int> c;
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int tmp;cin>>tmp;
        a.push_back(tmp);
    }
    for(int i=0;i<n-1;i++){
        int tmp;cin>>tmp;
        b.push_back(tmp);
    }
    for(int i=0;i<n-2;i++){
        int tmp;cin>>tmp;
        c.push_back(tmp);
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());

    for(int i=0;i<n-1;i++){
        if(a[i] != b[i]){
            cout<<a[i]<<endl;
            break;
        }
        if(i==n-2){
            cout<<a[n-1]<<endl;
        }
    }
    for(int i=0;i<n-2;i++){
        if(b[i]!=c[i]){
            cout<<b[i]<<endl;
            break;
        }
        if(i==n-3){
            cout<<b[n-2]<<endl;
        }
    }

}
