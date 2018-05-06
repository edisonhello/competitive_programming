#include<bits/stdc++.h>
using namespace std;



int main(){
    int n; while(cin>>n,n){
        cout<<n<<" ";
        int tot=0;
        int state=1;
        int left=1;
        while(n--){
            tot+=state;
            --left;
            if(left==0){
                ++state;
                left=state;
            }
        }
        cout<<tot<<endl;
    }
}
