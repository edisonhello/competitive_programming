#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define db double
using namespace std;
int n;
int ary[1005];

bool chk(int k){
    
}

int main(){
    cin>>n;
    cout<<1<<endl;
    for(int i=0;i<n && !fast;i++){
        cin>>ary[i];
    }
    for(int i=0;i<n;i++){
        if(chk(ary[i]-1)){
            cout<<ary[i]-1<<endl;
        }
        cout<<ary[i]<<endl;
        
    }
}
