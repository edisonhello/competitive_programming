#include<bits/stdc++.h>
using namespace std;

int winlose(int a,int b){
    if(a==b)return 0;
    return a>b?1:-1;
}

int main(){ 
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; while(cin>>s){
        int t[2]={0};
        bool over=0;
        for(int i=0;i<10;++i){
            if(s[i]=='1')++t[i&1];
            if(!(i&1)){
                int wl=winlose(t[0]+(10-i)/2-1,t[1]);
                if(wl==winlose(t[0],t[1]+(10-i)/2)){
                    cout<<"TEAM-"<<(wl==1?"A":"B")<<" "<<i+1<<endl;
                    over=1;
                    break;
                }
            }
            else if(i<9){
                int wl=winlose(t[0]-(10-i)/2,t[1]);
                if(wl==winlose(t[0],t[1]-(10-i)/2)){
                    cout<<"TEAM-"<<(wl==1?"A":"B")<<" "<<i+1<<endl;
                    over=1;
                    break;
                }
            }
        }
        if(over)continue;
        if(winlose(t[0],t[1])){
            cout<<(winlose(t[0],t[1])==1?"TEAM-A ":"TEAM-B ")<<10<<endl;
            continue;
        }
        for(int i=10;i<20;i+=2){
            if(s[i]!=s[i+1]){
                if(s[i]=='1'){
                    cout<<"TEAM-A "<<i+2<<endl;
                    over=1;
                    break;
                }
                else{
                    cout<<"TEAM-B "<<i+2<<endl;
                    over=1;
                    break;
                }
            }
        }
        if(over)continue;
        cout<<"TIE"<<endl;
    }
}
// WA 120
// AC 200
