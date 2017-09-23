#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int a[222];
#include<vector>
vector<int> lis;
#include<algorithm>

int main(){
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    reverse(a,a+n);
    lis.push_back(a[0]);
    for(int i=1;i<n;++i){
        if(a[i]>lis.back())lis.push_back(a[i]);
        else *lower_bound(lis.begin(),lis.end(),a[i])=a[i];
    }
    cout<<lis.size()<<endl;
}
