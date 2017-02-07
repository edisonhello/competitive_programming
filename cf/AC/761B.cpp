#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,l;cin>>n>>l;
    vector<int> ao(n),bo(n),a(n),b(n);
    for(int i=0;i<n;++i)cin>>ao[i];
    for(int i=0;i<n;++i)cin>>bo[i];
    for(int i=1;i<n;++i)a[i]=ao[i]-ao[i-1];a[0]=ao[0]+l-ao[n-1];
    for(int i=1;i<n;++i)b[i]=bo[i]-bo[i-1];b[0]=bo[0]+l-bo[n-1];
    for(int i=0;i<n;++i){
        if(a==b){cout<<"YES"<<endl;return 0;}
        int t=b[0];
        for(int j=1;j<n;++j)b[j-1]=b[j];
        b[n-1]=t;
    }
    cout<<"NO"<<endl;
}
