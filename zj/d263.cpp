#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define pii pair<int,int>
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue

int s[10][10];
int outed;
int st;

void put(int x,int y){
    if(outed) return;
    bool posi[10];
    bool bye=0;
    for(int i=x;i<=st*st;i++){
        for(int j=(i==x?y:1);j<=st*st;j++){
            if(s[i][j]==0){
                memset(posi,1,sizeof(posi));
                for(int ii=(i-1)/st*st+1,c=0;c<st;c++,ii++){
                    for(int jj=(j-1)/st*st+1,d=0;d<st;d++,jj++){
                        posi[s[ii][jj]]=0;
                    }
                }
                for(int k=1;k<=st*st;k++){
                    posi[s[i][k]]=0;
                    posi[s[k][j]]=0;
                }
                for(int k=1;k<=st*st;k++){
                    if(posi[k]){
                        s[i][j]=k;
                        put(i,j);
                    }
                }
                // s[i][j]=0;
                bye=1;
                break;
            }
            if(i>=st*st && j>=st*st && !outed){
                for(int ii=1;ii<=st*st;ii++){
                    for(int jj=1;jj<=st*st;jj++){
                        if(jj-1)cout<<" ";
                        cout<<s[ii][jj];
                    }
                    cout<<endl;
                }
                outed=1;
            }
        }
        if(bye)break;
    }
}

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    while(cin>>st){
        memset(s,0,sizeof(s));
        outed=0;
        for(int i=1;i<=st*st;i++){
            for(int j=1;j<=st*st;j++){
                cin>>s[i][j];
            }
        }
        put(1,1);
        if(!outed){
            cout<<"NO SOLUTION\n";
        }
    }
}
