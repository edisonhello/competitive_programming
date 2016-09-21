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
bool posi[10];
int ans;

void put(int x,int y){
    bool bye=0;
    for(int i=x;i<=9;i++){
        for(int j=y;j<=9;j++){
            if(s[i][j]==0){
                memset(posi,1,sizeof(posi));
                for(int ii=(i-1)/3*3+1,c=0;c<3;c++,ii++){
                    for(int jj=(j-1)/3*3+1,d=0;d<3;d++,jj++){
                        posi[s[ii][jj]]=0;
                    }
                }
                for(int k=1;k<=9;k++){
                    posi[s[i][k]]=0;
                    posi[s[k][j]]=0;
                }
                for(int k=1;k<=9;k++){
                    if(posi[k]){
                        s[i][j]=k;
                        put(i,j);
                    }
                }
                s[i][j]=0;
                bye=1;break;
            }
            if(x==9 && y==9){
                ans++;
                for(int ii=1;ii<=9;ii++){
                    for(int jj=1;jj<=9;jj++){
                        if(jj-1)cout<<" ";
                        cout<<s[ii][jj];
                    }
                    cout<<endl;
                }
                cout<<endl;
            }
        }
        if(bye)break;
    }
}

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            cin>>s[i][j];
        }
    }
    put(1,1);
    cout<<"there are a total of "<<ans<<" solution(s).";
}
