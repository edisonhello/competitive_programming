#include<bits/stdc++.h>
using namespace std;

void solve(int n,int as,int a,int bs,int b){
    int ptr=1;
    while(ptr<=n){
        vector<int> ele;
        if(as>0){
            --as;
            for(int i=0;i<a;++i){
                ele.push_back(ptr);
                ++ptr;
            }
        }
        else{
            --bs;
            for(int i=0;i<b;++i){
                ele.push_back(ptr);
                ++ptr;
            }
        }
        for(int i=1;i<ele.size();++i)cout<<ele[i]<<" "; cout<<ele[0]<<" ";
    }
    cout<<endl;
    exit(0);
}

int main(){
    int n,a,b; cin>>n>>a>>b;
    for(int i=0;i*a<=n;++i){
        if((n-a*i)%b==0){
            solve(n,i,a,(n-a*i)/b,b);
        }
    }
    cout<<-1<<endl;
}
