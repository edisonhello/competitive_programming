#include<bits/stdc++.h>
using namespace std;



int main(){
    int ts; cin>>ts; while(ts--){
        int n; cin>>n;
        if(n==1){cout<<1<<endl; continue;}
        bool ok=1;
        stack<char> ans;
        while(n>1){
            bool find=0;
            for(int i=9;i>=2;--i){
                if(n%i)continue;
                ans.push(i+'0');
                n/=i;
                find=1;
                break;
            }
            if(!find){
                ok=0;
                break;
            }
        }
        if(!ok)cout<<-1<<endl;
        else{
            while(ans.size()){
                cout<<ans.top();
                ans.pop();
            }
            cout<<endl;
        }
    }
}
