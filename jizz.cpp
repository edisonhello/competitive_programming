#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
int main(){
    ++m[2];
    ++m[3];
    ++m[3];
    cout<<m.begin()->first<<" "<<m.begin()->second<<endl;
}
