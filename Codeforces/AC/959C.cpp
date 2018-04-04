#include<bits/stdc++.h>
using namespace std;


void wr(int n){
    if(n<=5){
        cout<<-1<<endl;
        return;
    }
    cout<<"1 2\n1 3\n1 4\n4 5\n4 6\n";
    for(int i=7;i<=n;++i)cout<<"1 "<<i<<'\n';
}
void cor(int n){
    for(int i=2;i<=n;++i)cout<<i-1<<" "<<i<<'\n';
}

int main(){
    int n; cin>>n;
    wr(n);
    cor(n);
}
