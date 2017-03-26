#include<bits/stdc++.h>
using namespace std;
int n,a[1000006],l[1000006],len;
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<n;++i){
        auto pos=lower_bound(l,l+len,a[i]);
        if(pos==l+len){
            *pos=a[i];
            ++len;
        }
        else *pos=a[i];
    }
    cout<<len<<endl;
}
