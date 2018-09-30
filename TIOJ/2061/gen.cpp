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
int dp[10005][10005],cf[10005][10005];
bitset<10005> com[10005];

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
    for(int i=0;i<10005;++i)com[i].reset();
    i>>s;
    int n=int(s.size());
    int mx=go1(0,n-1);
    o<<go2(0,n-1)<<endl;
}

int cnt[255];
void count(ifstream &i,ofstream &o){
    memset(cnt,0,sizeof(cnt));
    string s; i>>s;
    for(char i:s)++cnt[i];
    char mx=max_element(cnt,cnt+255)-cnt;
    for(int i=0;i<1000;++i)o<<mx;
}

string gen(ofstream &o,int n,int testset){
    srand(clock());
    string s;
    if(testset!=5){
        int full=rand()%4;
        if(full)for(int z=0;z<n;++z)s+=rand()%10+'0';
        else{
            int nn=rand()%n+1;
            for(int z=0;z<nn;++z)s+=rand()%10+'0';
        }
    }
    else{
        int count=rand()%2;
        if(count){
            int full=rand()%3;
            if(full)for(int z=0;z<n;++z)s+=rand()%10+'0';
            else{
                int nn=rand()%n+1;
                for(int z=0;z<nn;++z)s+=rand()%10+'0';
            }
        }
        else{
            int full=rand()%4;
            if(full)for(int z=0;z<10000;++z)s+=rand()%10+'0';
            else{
                int nn=rand()%10000+1;
                for(int z=0;z<nn;++z)s+=rand()%10+'0';
            }
        }
    }
    o<<s<<endl;
    return s;
}

void gen(int from,int to,int len,int testset){
    for(int i=from;i<=to;++i){
        stringstream ss; ss<<i;
        string s; ss>>s;
        string inname=s+".in";
        string outname=s+".out";
        ofstream os;
        os.open(inname);
        string str=gen(os,len,testset);
        os.close();
        ifstream is;
        is.open(inname);
        os.open(outname);
        if(str.size()<=10000u)solve(is,os);
        else count(is,os);
        os.close();
    }
}

int main(){
    cout<<"testset: "; fflush(stdout);
    int ts; cin>>ts; 
    switch(ts){
        case 1: gen(0,9,20,1); break;
        case 2: gen(10,19,87,2); break;
        case 3: gen(20,29,300,3); break;
        case 4: gen(30,49,1000,4); break;
        case 5: gen(50,64,200000,5); break;
    }
}
