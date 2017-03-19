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

int n,m,a[1000005];
string s;

int main(){
    ios_base::sync_with_stdio(0);
    int n,m,z;cin>>n>>m>>z;
    int g=__gcd(n,m);
    int l=n*m/g;
    cout<<z/l<<endl;
}
