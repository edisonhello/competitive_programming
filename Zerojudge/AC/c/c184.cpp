#include<bits/stdc++.h>
using namespace std;

int get(int n){
    int rt=1,copyn=n;
    for(int i=2;i*i<=n;++i){
        if(n%i==0){
            int p=1,sum=1;
            while(n%i==0){
                n/=i;
                p*=i;
                sum+=p;
            }
            rt*=sum;
        }
    }
    if(n!=1)rt*=(n+1);
    return rt-copyn;
}

int main(){
    int n; while(cin>>n,n){
        int sum=get(n);
        // cout<<n<<" -> "<<sum<<endl;
        if(sum==n)cout<<"="<<n<<endl;
        else if(get(sum)==n)cout<<sum<<endl;
        else cout<<0<<endl;
    }
}
