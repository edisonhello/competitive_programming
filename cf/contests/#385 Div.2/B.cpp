#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<map>
#include<utility>
using namespace std;

int n,m;
string G[505];

int main(){
    cin>>n>>m;
    int ilength=0,istoped=0,comjl=-1;
    for(int i=0;i<n;++i){
        cin>>G[i];
        int jlength=0,jstoped=0;
        for(int j=0;j<m;++j){
            if(G[i][j]=='X' && jstoped){
                cout<<"NO\n";
                return 0;
            }
            else if(G[i][j]=='X'){
                ++jlength;
            }
            else if(jlength){
                ++jstoped;
            }
        }
        if(jlength && comjl==-1)comjl=jlength;
        if(jlength && comjl!=-1 && comjl!=jlength){cout<<"NO\n";return 0;}
        if(jlength && istoped){cout<<"NO\n";return 0;}
        else if(jlength)++ilength;
        else if(ilength)++istoped;
    }
    cout<<"YES\n";
}
