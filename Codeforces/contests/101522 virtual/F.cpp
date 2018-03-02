#include<bits/stdc++.h>
using namespace std;

int nxt[100005],prv[100005],front,back;
stack<vector<int>> ans;

int main(){
    int n,b,r; cin>>n>>r>>b;
    string s; cin>>s;
    for(char &c:s)if(c=='B')c=1; else c=2;
    if(n%(b+r))return cout<<"NO"<<endl,0;
    back=n-1;
    for(int i=0;i<n;++i)prv[i]=i-1;
    for(int i=0;i<n-1;++i)nxt[i]=i+1; nxt[n-1]=-1;
    int painted=0;
    // int debug=50;
    while(1){
        int newpaint=0;
        int nowfront=front,nowback=front;
        if(nowfront==-1 || nowback==-1)break;
        // cout<<"start new loop front back "<<nowfront<<" "<<nowback<<endl;
        int nowb=0,nowr=0;
        ++(s[nowfront]==1?nowb:nowr);
        // cout<<nowfront<<" "<<nowback<<endl;
        while(1){
            // --debug;
            // if(debug==0)exit(0);
            nowback=nxt[nowback];
            // cout<<nowback<<endl;
            if(nowback==-1)break;
            ++(s[nowback]==1?nowb:nowr);
            if(nowb>b || nowr>r){
                --(s[nowfront]==1?nowb:nowr);
                nowfront=nxt[nowfront];
            }
            // cout<<"nowbb nowrr "<<nowb<<" "<<b<<" "<<nowr<<" "<<r<<endl;
            if(nowb==b && nowr==r){
                // cout<<"match! "<<nowfront<<" "<<nowback<<endl;
                int ptr=nowfront;
                vector<int> inans; inans.push_back(ptr);
                do{
                    ptr=nxt[ptr];
                    inans.push_back(ptr);
                }while(ptr!=nowback);
                ans.push(inans);
                newpaint+=b+r;
                int newfront=prv[nowfront],newback=nxt[nowback];
                // cout<<"new front back "<<newfront<<" "<<newback<<endl;
                if(newfront!=-1)nxt[newfront]=newback;
                if(newback!=-1)prv[newback]=newfront;
                if(newfront==-1)front=newback;
                if(newback==-1)back=newfront;
                nowb=0; nowr=0;
                nowback=newfront;
                nowfront=newfront;
                if(nowfront==-1 || nowback==-1)break;
                ++(s[nowfront]==1?nowb:nowr);
                while(nowb<=b && nowr<=r && nowfront!=front){
                    nowfront=prv[nowfront];
                    ++(s[nowfront]==1?nowb:nowr);
                }
                if(nowb>b || nowr>r){
                    --(s[nowfront]==1?nowb:nowr);
                    nowfront=nxt[nowfront];
                }
            }
        }
        // cout<<"newpaint: "<<newpaint<<endl;
        painted+=newpaint;
        if(!newpaint)break;
    }
    if(painted==n){
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        while(ans.size()){
            auto v=ans.top();
            ans.pop();
            for(int i:v){
                cout<<i+1<<" ";
            }
            cout<<endl;
        }
    }
    else cout<<"NO"<<endl;
}
