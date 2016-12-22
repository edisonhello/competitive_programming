#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    a/=1;
    b/=2;
    c/=4;
    int mn=min({a,b,c});
    cout<<mn*7<<endl;
}
