#include<iostream>
#include<iomanip>
#define ld long double
using namespace std;
ld m[15][15],chAll,chRou;
void init();
bool key(int &st,int &ed,int &ke);
void dfs(int now,int ed,ld ch,bool rou,int &ke){
    // cout<<"dfs : now="<<(char)(now+'A')<<" rou chk:"<<rou<<" ch lft:"<<ch<<endl;
    if(now==ed){
        if(rou)chRou+=ch;
        chAll+=ch;
        return;
    }
    for(int i=0;i<15;++i){
        if(m[now][i]){
            if(key(now,i,ke)){
                dfs(i,ed,ch*m[now][i],1,ke);
            }
            else dfs(i,ed,ch*m[now][i],rou,ke);
        }
    }
}
int main(){
    init();
    char st,ed;int rt;
    while(cin>>st>>ed>>rt){
        if(st>'N'||ed>'N'||st=='M'||ed=='M'){
            cout<<"No solution\n";
            continue;
        }
        chAll=chRou=0.0;
        dfs(st-'A',ed-'A',1.0,0,rt);
        if(chRou==0.0){
            cout<<"No solution\n";
        }
        else{
            cout<<fixed<<setprecision(8)<<chRou/chAll<<'\n';
        }
    }
}
bool key(int &st,int &ed,int &ke){
    // cout<<"check key "<<(char)(st+'A')<<" "<<(char)(ed+'A')<<" "<<ke<<endl;
    if(ke==1&&st==0&&ed==1)return 1;
    if(ke==2&&st==0&&ed==2)return 1;
    if(ke==3&&st==0&&ed==3)return 1;
    if(ke==4&&st==1&&ed==5)return 1;
    if(ke==5&&st==2&&ed==3)return 1;
    if(ke==6&&st==2&&ed==6)return 1;
    if(ke==7&&st==3&&ed==5)return 1;
    if(ke==8&&st==3&&ed==9)return 1;
    if(ke==9&&st==4&&ed==7)return 1;
    if(ke==10&&st==5&&ed==4)return 1;
    if(ke==11&&st==5&&ed==8)return 1;
    if(ke==12&&st==6&&ed==8)return 1;
    if(ke==13&&st==6&&ed==9)return 1;
    if(ke==14&&st==7&&ed==11)return 1;
    if(ke==15&&st==8&&ed==11)return 1;
    if(ke==16&&st==9&&ed==11)return 1;
    if(ke==17&&st==9&&ed==13)return 1;
    if(ke==18&&st==11&&ed==13)return 1;
    return 0;
}
void init(){
    m[0][1]=0.3;
    m[0][2]=0.67;
    m[0][3]=0.5;
    m[1][5]=0.33;
    m[2][3]=0.42;
    m[2][6]=0.1;
    m[3][5]=0.54;
    m[3][9]=0.28;
    m[4][7]=0.5;
    m[5][4]=0.28;
    m[5][8]=0.2;
    m[6][8]=0.23;
    m[6][9]=0.36;
    m[7][11]=0.4;
    m[8][11]=0.41;
    m[9][11]=0.37;
    m[9][13]=0.47;
    m[11][13]=0.5;
}
