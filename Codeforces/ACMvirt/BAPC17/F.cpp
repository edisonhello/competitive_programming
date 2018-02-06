#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int a=0,b=0,*pa=&a,*pb=&b;
    while(v.size()){
        *pa+=v.back();
        v.pop_back();
        swap(pa,pb);
    }
    cout<<a<<" "<<b<<endl;
}
