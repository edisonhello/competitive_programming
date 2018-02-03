#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;

int pre[1234];
int meow(int i){
    return bitset<12>(i).count();
}

struct nums{
    set<int> inr;
    ll ttr;
    nums():ttr(0){}
};

ll C[1234][1234];
void init(){
    C[0][0]=1;
    for(int i=1;i<=1233;++i){
        for(int j=0;j<=i;++j){
            C[i][j]=C[i-1][j];
            if(j)C[i][j]=(C[i][j]+C[i-1][j-1])%mod;
        }
    }
}

int de(string &s){
    int rt=0;
    for(char c:s){
        rt*=2;
        rt+=c-'0';
    }
    return rt;
}

ll proc(string &s,int c1){
    // cout<<"proc c1: "<<c1<<endl;
    ll rt=0;
    for(int len=c1;;++len){
        // cout<<"len: "<<len<<endl;
        if(len>s.length())break;
        if(len==s.length()){
            rt=(rt+C[len-1][c1-1])%mod;
            int fix=0,cost1=0;
            for(int i=0;i<len;++i){
                ++fix;
                if(s[i]=='1'){
                    ++cost1;
                }
                else{
                    rt-=C[len-fix][c1-cost1-1];
                }
                if(cost1>=c1)break;
            }
            rt%=mod;
            rt+=mod;
            rt%=mod;
        }
        else{
            rt=(rt+C[len-1][c1-1])%mod;
        }
        // cout<<"rt: "<<rt<<endl;
    }
    // cout<<"rt: "<<rt<<endl;
    return rt;
}

int main(){
    init();
    for(int i=2;i<=1000;++i)pre[i]=meow(i);
    string s; int k; cin>>s>>k;
    int mx=8877755;
    if(s.length()<12)mx=de(s);
    nums *prv=new nums,*now=new nums;
    prv->inr.insert(1);
    prv->ttr=1;
    for(int i=1;i<=k;++i){
        // cout<<"now i: "<<i<<endl;
        // int debcnt[10]={0};
        for(int ii=2;ii<=min(1000,mx);++ii){
            if(prv->inr.find(pre[ii])!=prv->inr.end()){
                now->inr.insert(ii);
                // cout<<"inr add "<<ii<<"with pre: "<<pre[ii]<<endl;
                // ++debcnt[pre[ii]];
            }
        }
        // for(int i=1;i<=9;++i)cout<<"debcnt["<<i<<"]="<<debcnt[i]<<endl;;
        // cout<<"finish step 1"<<endl;
        for(int ii:prv->inr){
            now->ttr=(now->ttr+proc(s,ii))%mod;
        }
        delete prv;
        prv=now;
        now=new nums;
    }
    // cout<<"inr sz: "<<prv->inr.size()<<endl;
    cout<<prv->ttr-(k==1)<<endl;
}
