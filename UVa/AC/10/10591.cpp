#include<bits/stdc++.h>
using namespace std;

int meow(int x){
    int rt=0;
    while(x){
        rt+=(x%10)*(x%10);
        x/=10;
    }
    return rt;
}

int main(){
    int ts,ks=0; cin>>ts; while(ts--){
        int n; cin>>n; 
        cout<<"Case #"<<(++ks)<<": "<<n<<" is ";
        n=meow(n);
        while(n>9)n=meow(n);
        int start=n;
        while(n!=1 && n!=start)n=meow(n);
        if(n==1)cout<<"a Happy number."<<endl;
        else cout<<"an Unhappy number."<<endl;
    }
}
