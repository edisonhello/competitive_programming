#include<bits/stdc++.h>
using namespace std;

int rand(int l,int r){
    int val=rand()*rand()*rand(); val=abs(val);
    val%=r-l+1;
    return val+l;
}

set<pair<int,int>> pos;

int main(){
    srand(clock());
    int n=rand(2900,3000),l=rand(1,1000000),w=rand(1,1000000);
    cout<<n<<" "<<l<<" "<<w<<endl;
    for(int i=1;i<=n;++i){
        int x,y;
        do{
            x=rand(0,1000000), y=rand(0,1000000);
        }while(pos.find({x,y})!=pos.end());
        pos.insert({x,y});
        cout<<x<<" "<<y<<endl;
    }
}
