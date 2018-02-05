#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t; while(t--){
        int n,m,x,k; cin>>n>>m>>x>>k;
        int nowodd=1,oddwork=0,noweven=2,evenwork=0;
        string s; cin>>s; for(char c:s){
            if(c=='E'){
                if(noweven>m)continue;
                ++evenwork, --n;
                if(evenwork>=x)evenwork=0,noweven+=2;
            }
            else if(c=='O'){
                if(nowodd>m)continue;
                ++oddwork, --n;
                if(oddwork>=x)oddwork=0,nowodd+=2;
            }
        }
        if(x==0)n=1234567;
        if(n<=0)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}
