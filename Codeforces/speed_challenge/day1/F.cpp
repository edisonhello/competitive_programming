#include<bits/stdc++.h>
using namespace std;

int main(){
    int k; cin>>k;
    int a[12];
    for(int i=0;i<12;++i)cin>>a[i];
    sort(a,a+12); reverse(a,a+12);
    int cnt=0;
    for(int i=0;i<12;++i){
        if(k<=0)continue;
        ++cnt; k-=a[i];
    }
    if(k<=0)cout<<cnt<<endl;
    else cout<<-1<<endl;
}
