#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define sf(x) scanf(x)
#define pf(x) printf(x)
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
inline int rit(){
    int t=0,k=1;
    char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    while(cin>>s){
        int pnt[2]={0};
        int team=0;

        int nowout=0;
        int base[4]={0};
        for(int i=0;i<(int)s.length();i++){
            if(s[i]=='K'||s[i]=='O'){
                nowout++;
                if(nowout==3){
                    team=!team;
                    nowout=0;
                    base[1]=base[2]=base[3]=0;
                }
            }
            if(s[i]=='W'){
                if(base[1]){
                    if(base[2]){
                        if(base[3]){
                            pnt[team]++;
                            // base[3]=0;
                        }
                        else{
                            base[3]=1;
                        }
                    }
                    else{
                        base[2]=1;
                    }
                }
                else{
                    base[1]=1;
                }
            }
            if(s[i]=='S'){
                if(base[3]){
                    base[3]=0;
                    pnt[team]++;
                }
                if(base[2]){
                    base[2]=0;
                    base[3]=1;
                }
                if(base[1]){
                    base[1]=0;
                    base[2]=1;
                }
                base[1]=1;
            }
            if(s[i]=='D'){
                if(base[3]){
                    base[3]=0;
                    pnt[team]++;
                }
                if(base[2]){
                    base[2]=0;
                    pnt[team]++;
                }
                if(base[1]){
                    base[1]=0;
                    base[3]=1;
                }
                base[2]=1;
            }
            if(s[i]=='T'){
                if(base[3]){
                    base[3]=0;
                    pnt[team]++;
                }
                if(base[2]){
                    base[2]=0;
                    pnt[team]++;
                }
                if(base[1]){
                    base[1]=0;
                    pnt[team]++;
                }
                base[3]=1;
            }
            if(s[i]=='H'){
                if(base[3]){
                    base[3]=0;
                    pnt[team]++;
                }
                if(base[2]){
                    base[2]=0;
                    pnt[team]++;
                }
                if(base[1]){
                    base[1]=0;
                    pnt[team]++;
                }
                pnt[team]++;
            }
        }
        cout<<pnt[0]<<" "<<pnt[1]<<endl;
    }
}
