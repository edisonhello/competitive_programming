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

int x,y;

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);

    cin>>x>>y;
    bool nbw = false;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            char c;
            cin>>c;
            if(c!='W'&&c!='B'&&c!='G'){
                nbw = true;
                break;
            }
        }
        if(nbw){
            break;
        }
    }
    if(nbw){
        cout<<"#Color"<<endl;
    }
    else{
        cout<<"#Black&White"<<endl;
    }
}
