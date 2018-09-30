#include <fstream>
#include <iostream>
#include <bitset>
using namespace std;

bitset<1000005> st1,st2;
int main(int argc,char** argv){
    fstream fs_user(argv[1],ios::in);
    fstream fs_input(argv[2],ios::in);
    fstream fs_output(argv[3],ios::in);
    int n,m; fs_input>>n>>m;
    int sz1,sz2; fs_user>>sz1>>sz2;
    if(sz1<0 || sz1>n || sz2<0 || sz2>n)return 0;
    while(sz1--){ int t; fs_user>>t; if(t<0 || t>n)return 0; st1[t]=1; }
    while(sz2--){ int t; fs_user>>t; if(t<0 || t>n)return 0; st2[t]=1; }
    for(int i=1;i<=n;++i)if(st1[i] && st2[i])return 0;
    while(m--){
        int u,v; fs_input>>u>>v;
        if(st1[u] && st2[v])continue;
        if(st2[u] && st1[v])continue;
        return 0;
    }
    cout<<0<<endl;
}
