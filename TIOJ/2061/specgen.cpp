#include<bits/stdc++.h>
using namespace std;

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
            result += buffer.data();
    }
    return result;
}

string s;
int dp[5005][5005],cf[5005][5005];
bitset<5005> com[5005];

int go1(int l,int r){
    if(l==r)return 1;
    if(l>r)return 0;
    if(com[l][r])return dp[l][r];
    com[l][r]=1;
    int _l=go1(l+1,r);
    int _r=go1(l,r-1);
    int _lr=(s[l]==s[r]?go1(l+1,r-1)+2:-7122);
    int mx=max(max(_l,_r),_lr);
    if(_lr==mx)cf[l][r]=3;
    else if(_l==mx)cf[l][r]=1;
    else cf[l][r]=2;
    return dp[l][r]=mx;
}

string go2(int l,int r){
    if(l==r)return string(1,s[l]);
    if(l>r)return "";
    if(cf[l][r]==1)return go2(l+1,r);
    if(cf[l][r]==2)return go2(l,r-1);
    return s[l]+go2(l+1,r-1)+s[r];
}

void solve(ifstream &i,ofstream &o){
    memset(dp,0,sizeof(dp));
    memset(cf,0,sizeof(cf));
    for(int i=0;i<5005;++i)com[i].reset();
    i>>s;
    int n=int(s.size());
    int mx=go1(0,n-1);
    o<<go2(0,n-1)<<endl;
}

string gen(ofstream &o,int n){
    string s;
    char now='a';
    while(int(s.size())<(n/2)){
        s+=now;
        ++now;
        if(now>'z')now='a';
    }
    string t=s;
    reverse(t.begin(),t.end());
    s+=t;
    o<<s<<endl;
    return s;
}

void gen(int from,int to,int len){
    for(int i=from;i<=to;++i){
        stringstream ss; ss<<i;
        string s; ss>>s;
        string inname=s+".in";
        string outname=s+".out";
        ofstream os;
        os.open(inname);
        string str=gen(os,len);
        os.close();
        ifstream is;
        is.open(inname);
        os.open(outname);
        solve(is,os);
    }
}

int main(){
    gen(17,17,5000);
}
