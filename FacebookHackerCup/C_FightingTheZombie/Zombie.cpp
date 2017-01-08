#include<string>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#define ld long double
#define ll long long
using namespace std;


ld dp[22][405],pre[405];
ld getChance(int n,int dice,int lb){
    memset(dp,0,sizeof(dp));
    memset(pre,0,sizeof(pre));
    if(lb<=0)return 1;
    int mxp=n*dice,nmxp=dice;
    dp[0][0]=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=dice;++j){
            for(int k=j;k<=nmxp;++k){
                dp[i][k]+=dp[i-1][k-j];
            }
            nmxp+=dice;
        }
    }
    int tot=0;
    for(int i=1;i<=mxp;++i){
        pre[i]=pre[i-1]+dp[n][i];
        // cout<<dp[n][i]<<" ";
    }
    // cout<<endl;
    return (ld)(pre[mxp]-pre[lb-1])/(ld)pre[mxp];
}

int getT(string &sp){
    if(sp[1]=='d'){
        int rt=sp[0]-'0';
        sp=sp.substr(2,(int)sp.length()-2);
        return rt;
    }
    else{
        int rt=(sp[0]-'0')*10+sp[1]-'0';
        sp=sp.substr(3,(int)sp.length()-3);
        return rt;
    }
}
int getDic(string &sp){
    // cout<<"getDic sp:"<<sp<<endl;
    int rt=sp[0]-'0';
    if((int)sp.length()>1 && (sp[1]=='+' || sp[1]=='-')){
        sp=sp.substr(1,(int)sp.length()-1);
        return rt;
    }
    else if((int)sp.length()>1){
        rt=rt*10+sp[1]-'0';
        if((int)sp.length()>2){
            sp=sp.substr(2,(int)sp.length()-2);
        }
        else sp="";
        return rt;
    }
    else{
        sp="";
        return rt;
    }
}
int getZ(string &sp){
    if(sp=="")return 0;
    bool fl=0;
    if(sp[0]=='-'){
        fl=1;
    }
    sp=sp.substr(1,(int)sp.length()-1);
    int rt=0,p=0;
    while(p<(int)sp.length()){
        rt=rt*10+sp[p++]-'0';
    }
    if(fl)return -rt;
    else return rt;
}

int main(){
    // freopen("fighting_the_zombie.txt","r",stdin);
    // freopen("fighting_the_zombie.out","w",stdout);
    int ts;cin>>ts;for(int c=1;c<=ts;++c){
        // cout<<"Case #"<<c<<": ";
        int mxdm,sps;cin>>mxdm>>sps;
        ld chs=0;
        while(sps--){
            string sp;cin>>sp;
            int t=getT(sp);
            int d=getDic(sp);
            int z=getZ(sp);
            int l=1*t+z,r=d*t+z;
            ld ch;
            if(l>=mxdm)ch=1;
            else if(r<mxdm)ch=0;
            else ch=getChance(t,d,mxdm-z);
            cout<<"[INFO] "<<t<<" "<<d<<" "<<z<<" "<<l<<" "<<r<<" "<<ch<<endl;
            chs=max({chs,ch});
        }
        cout<<fixed<<setprecision(6)<<chs<<endl;
    }
}
