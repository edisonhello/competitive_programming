#include<string>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#define ld long double
#define ll long long
using namespace std;


ll dp4[22][405],pre4[22][405];
ll dp6[22][405],pre6[22][405];
ll dp8[22][405],pre8[22][405];
ll dp10[22][405],pre10[22][405];
ll dp12[22][405],pre12[22][405];
ll dp20[22][405],pre20[22][405];
void init(){
    int mxp=20*4,nmxp=4;
    dp4[0][0]=1;
    for(int i=1;i<=20;++i){
        for(int j=1;j<=4;++j){
            for(int k=j;k<=nmxp;++k)dp4[i][k]+=dp4[i-1][k-j];
            nmxp+=4;
        }
    }
    for(int i=1;i<=20;++i){
        for(int j=1;j<=mxp;++j)pre4[i][j]=pre4[i][j-1]+dp4[i][j];
    }

    mxp=20*6,nmxp=6;
    dp6[0][0]=1;
    for(int i=1;i<=20;++i){
        for(int j=1;j<=6;++j){
            for(int k=j;k<=nmxp;++k)dp6[i][k]+=dp6[i-1][k-j];
            nmxp+=6;
        }
    }
    for(int i=1;i<=20;++i){
        for(int j=1;j<=mxp;++j)pre6[i][j]=pre6[i][j-1]+dp6[i][j];
    }

    mxp=20*8,nmxp=8;
    dp6[0][0]=1;
    for(int i=1;i<=20;++i){
        for(int j=1;j<=8;++j){
            for(int k=j;k<=nmxp;++k)dp8[i][k]+=dp8[i-1][k-j];
            nmxp+=8;
        }
    }
    for(int i=1;i<=20;++i){
        for(int j=1;j<=mxp;++j)pre8[i][j]=pre8[i][j-1]+dp8[i][j];
    }

    mxp=20*10,nmxp=10;
    dp10[0][0]=1;
    for(int i=1;i<=20;++i){
        for(int j=1;j<=10;++j){
            for(int k=j;k<=nmxp;++k)dp10[i][k]+=dp10[i-1][k-j];
            nmxp+=10;
        }
    }
    for(int i=1;i<=20;++i){
        for(int j=1;j<=mxp;++j)pre10[i][j]=pre10[i][j-1]+dp10[i][j];
    }

    mxp=20*12,nmxp=12;
    dp12[0][0]=1;
    for(int i=1;i<=20;++i){
        for(int j=1;j<=12;++j){
            for(int k=j;k<=nmxp;++k)dp12[i][k]+=dp12[i-1][k-j];
            nmxp+=12;
        }
    }
    for(int i=1;i<=20;++i){
        for(int j=1;j<=mxp;++j)pre12[i][j]=pre12[i][j-1]+dp12[i][j];
    }

    mxp=20*20,nmxp=20;
    dp20[0][0]=1;
    for(int i=1;i<=20;++i){
        for(int j=1;j<=20;++j){
            for(int k=j;k<=nmxp;++k)dp20[i][k]+=dp20[i-1][k-j];
            nmxp+=20;
        }
    }
    for(int i=1;i<=20;++i){
        for(int j=1;j<=mxp;++j)pre20[i][j]=pre20[i][j-1]+dp20[i][j];
    }
}
ld getChance(int n,int dice,int lb){
    if(lb<=0)return 1;
    int mxp=n*dice;
    if(dice==4)return (ld)(pre4[n][mxp]-pre4[n][lb-1])/(ld)pre4[n][mxp];
    if(dice==6)return (ld)(pre6[n][mxp]-pre6[n][lb-1])/(ld)pre6[n][mxp];
    if(dice==8)return (ld)(pre8[n][mxp]-pre8[n][lb-1])/(ld)pre8[n][mxp];
    if(dice==10)return (ld)(pre10[n][mxp]-pre10[n][lb-1])/(ld)pre10[n][mxp];
    if(dice==12)return (ld)(pre12[n][mxp]-pre12[n][lb-1])/(ld)pre12[n][mxp];
    if(dice==20)return (ld)(pre20[n][mxp]-pre20[n][lb-1])/(ld)pre20[n][mxp];
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
    init();
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
