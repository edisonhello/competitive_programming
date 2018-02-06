#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
#define ll long long

vector<int> p;
bitset<65540> _p;
void init(){
    for(ll i=2;i<=65536;++i){
        if(_p[i])continue;
        p.push_back(i);
        for(ll j=i*i;j<=65536;j+=i){
            _p[j]=1;
        }
    }
}

int main(){
    init();
    int x; while(cin>>x){
        --x;
        for(int _=0;_<p.size();++_){
            int i=p[_];
            if(x%i==0){
                x=x/i*(i-1);
            }
        }
        cout<<x<<endl;
    }
}
