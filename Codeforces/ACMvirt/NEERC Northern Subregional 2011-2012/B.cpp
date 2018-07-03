#include<bits/stdc++.h>
using namespace std;

void OK(){ cout<<"Unique"<<endl; exit(0); }
void NO(){ cout<<"Ambiguous"<<endl; exit(0); }
void JIZZ(){ cout<<"Impossible"<<endl; exit(0); }

int pre[5555];

int main(){
    freopen("black.in", "r", stdin);
    freopen("black.out", "w", stdout);
    int n,m,s,k; cin>>n>>m>>s>>k;
    string mp; cin>>mp;
    for(int i=1;i<=m;++i){
        pre[i]=pre[i-1]+(mp[i-1]=='*');
    }
    int okpos=0;
    for(int i=1;i<=n-s+1;++i){
        for(int j=1;j<=m-s+1;++j){
            int il=i,ir=i+s-1;
            if(il<=k && k<=ir){
                int jl=j,jr=j+s-1;
                // cout<<il<<" "<<ir<<" "<<jl<<" "<<jr<<endl;
                if(pre[jr]-pre[jl-1]==s && pre[m]==s)++okpos;
            }
            else{
                if(pre[m]==0)++okpos;
            }
        }
    }
    if(okpos==0)JIZZ();
    if(okpos==1)OK();
    NO();
}
