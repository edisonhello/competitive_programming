#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
string ar[200005];
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>ar[i];
    int q;cin>>q;while(q--){
        int a,b;cin>>a>>b;
        if(abs(b-a)>7){
            cout<<"I QUIT!\n";
            while(q--){cin>>a>>b;};
            break;
        }
        swap(ar[a],ar[b]);
        if(!q){
            cout<<"SORTED!\n";
        }
    }
    for(int i=1;i<=n;++i){
        if(i-1)cout<<" ";
        cout<<ar[i];
    }
    cout<<endl;
}
