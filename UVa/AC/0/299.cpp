#include<bits/stdc++.h>
using namespace std;

int main(){
    int ts; cin>>ts; while(ts--){
        int ans=0;
        int n; cin>>n;
        int a[55];
        for(int i=0;i<n;++i)cin>>a[i];
        for(int i=0;i<n;++i){
            for(int j=1;j<n;++j){
                if(a[j-1]>a[j]){
                    swap(a[j-1],a[j]);
                    ++ans;
                }
            }
        }
        cout<<"Optimal train swapping takes "<<ans<<" swaps."<<endl;
    }
}
