#include<iostream>
#include<vector>
#define ll long long
using namespace std;
ll d[789];
void init(){
    d[0]=1;
    for(int i=1;i<789;i+=2){
        for(int j=i;j<789;++j){
            d[j]+=d[j-i];
        }
    }
}
int main(){
    init();
    int ts;cin>>ts;while(ts--){
        int n;cin>>n;cout<<d[n]<<endl;
    }
}
