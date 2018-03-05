#include<bits/stdc++.h>
using namespace std;

int pw(int b,int n,int a=1){
    for(int i=0;i<n;++i)a*=b;
    return a;
}

int main(){
    int ts; cin>>ts; while(ts--){
        string s; if(!(cin>>s)){
            cout<<"Not Armstrong"<<endl;
            continue;
        }
        int rt=0;
        for(char c:s){
            rt+=pw(c-'0',s.size());
        }
        stringstream ss(s);
        int val; ss>>val;
        if(rt==val){
            cout<<"Armstrong"<<endl;
        }
        else cout<<"Not Armstrong"<<endl;
    }
}
