#include<string>
#include<iostream>
using namespace std;

string b,s,e;
int poss[2005],pose[2005];
int bl,sl,el,ans;

int main(){
    cin>>b>>s>>e;
    bl=(int)b.length(),sl=(int)s.length(),el=(int)e.length();
    for(int i=0;i+sl-1<bl;++i){
        for(int j=0;j<sl;++j){
            if(b[i+j]!=s[j])goto nothis;
        }
        poss[i]=1;
        nothis:;
    }
    for(int i=0;i+el-1<bl;++i){
        for(int j=0;j<el;++j){
            if(b[i+j]!=e[j])goto nothiss;
        }
        pose[i]=1;
        nothiss:;
    }
    for(int i=0;i<10;++i)cout<<poss[i]<<" ";cout<<endl;
    for(int i=0;i<10;++i)cout<<pose[i]<<" ";cout<<endl;

    for(int i=2003;i>=0;--i){
        pose[i]+=pose[i+1];
    }
    for(int i=0;i<2004;++i){
        if(poss[i])ans+=pose[i];
    }
    cout<<ans<<endl;
}
