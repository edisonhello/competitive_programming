#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;

int n,m,a[2000005];
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=(n/2);++i){
        if(i&1){
            swap(a[i],a[n-i+1]);
        }
    }
    for(int i=1;i<=n;++i)cout<<a[i]<<" ";;cout<<endl;
}
