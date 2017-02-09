#include<iostream>
using namespace std;
int main(){
    int ts;cin>>ts;while(ts--){
        int n;cin>>n;int tot=0,sgl=0;
        for(int i=0,t;i<n;++i){
            cin>>t;tot+=t;
            if(!t)++sgl;
        }
        if(n==sgl && !tot){
            cout<<n<<endl;
            continue;
        }
        if(tot&1)cout<<"tsan"<<endl;
        else{
            tot/=2;
            // cout<<tot<<endl;
            if(n-sgl-tot<=0)cout<<"tsan"<<endl;
            else{
                cout<<n-tot<<endl;
            }
        }
    }
}
