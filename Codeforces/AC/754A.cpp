#include<iostream>
using namespace std;

int a[105];

int main(){
    int n,sum=0,no0=-1;
    cin>>n;
    for(int i=1;i<=n;++i){cin>>a[i];sum+=a[i];if(a[i] && no0==-1)no0=i;}
    if(sum==0){
        if(no0==-1){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            cout<<2<<endl;
            cout<<1<<" "<<no0<<endl;
            cout<<no0+1<<" "<<n<<endl;
        }
    }
    else{
        cout<<"YES\n";
        cout<<1<<endl;
        cout<<1<<" "<<n<<endl;
    }
}
