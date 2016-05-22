#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;


    cin>>n>>k;

    vector<int> a,b;
    int done=0;

    for(int i=0;i<n;i++){
        int t;cin>>t;
        a.push_back(t);
    }
    for(int i=0;i<n;i++){
        int t;cin>>t;
        b.push_back(t);
    }

    while(1){
        // cout<<"inloop";
        for(int i=0;i<n;i++){
            b[i]-=a[i];
            if(b[i]<0){
                k+=b[i];
                b[i]=0;
            }
        }
        if(k>=0){
            done++;
        }
        else{
            cout<<done<<endl;
            return 0;
        }
    }
}
