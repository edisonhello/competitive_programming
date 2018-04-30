#include<bits/stdc++.h>
using namespace std;

string stringset="QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";

int rand(int l,int r){
    int val=rand()*rand()*rand(); val=abs(val);
    val%=r-l+1;
    return val+l;
}

namespace unique{
    bitset<60> used;
    void gen(int n){
        used.reset();
        cout<<rand(2,9999)<<" ";
        for(int i=0;i<n;++i){
            int idx; do{ idx=rand(1,stringset.size())-1; }while(used[idx]);
            cout<<stringset[idx];
            used[idx]=1;
        }
        cout<<endl;
    }
}
namespace repeat{
    void gen(int n){
        cout<<rand(2,9999)<<" ";
        for(int i=0;i<n;++i){
            cout<<stringset[rand(1,stringset.size())-1];
        }
        cout<<endl;
    }
}

int main(){
    srand(clock());
    repeat::gen(1024-rand(0,2));
}
