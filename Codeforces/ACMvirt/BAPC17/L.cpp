#include<bits/stdc++.h>
using namespace std;
#define ld long double

unordered_map<string,ld> mp;

/* string gnxt(string s){
    ++s.back();
    int ptr=s.size()-1;
    while(ptr>0){
        if(s[ptr]>'z'){
            ++s[ptr-1];
            s[ptr]='a';
        }
        --ptr;
    }
    while(s[0]>'z'){
        s[0]='a';
        s="a"+s;
    }
    return s;
} */

int main(){
    int n; cin>>n;
    // int n=100000;
    mp["pink"]=0.0;
    mp["blue"]=-1e30;
    // int addcnt=45500,deccnt=45500;
    // string prv="pink";
    while(n--){
        string nw,od; cin>>nw>>od;
        ld rate; cin>>rate;
        // string nw=(n==0?"blue":"pink"),od("pink");
        // ld rate=2.0;
        /* string nw,od;
        ld rate;
        if(addcnt>0){
            --addcnt;
            nw="pink";
            od="pink";
            rate=2.0;
        }
        else if(deccnt>1){
            --deccnt;
            string nxt=gnxt(prv);
            nw=nxt,od=prv;
            rate=0.5;
            prv=nxt;
        }
        else if(deccnt==1){
            deccnt=0;
            nw="blue";
            od=prv;
            rate=0.5;
        }
        else{
            nw=od="blue";
            rate=1.0;
        } */

        auto it=mp.find(od);
        if(it!=mp.end()){
            if(mp.find(nw)==mp.end())mp[nw]=-1e30;
            ld &xx=mp[nw];
            xx=max(xx,log2(rate)+it->second);
        }
    }

    // cout<<fixed<<setprecision(12)<<mp["blue"]<<endl;

    cout<<fixed<<setprecision(12)<<min((ld)10.0,pow(2,mp["blue"]))<<endl;
}
