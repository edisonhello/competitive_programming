#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define X first
#define Y second
#define S(x) (int)(x).size()
#define rz(x) reserve(x)
#define PB(x) push_back(x)
#define pii pair<int,int>
#define vint vector<int>
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define SS stringstream
#define PQ priority_queue
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
// #define getchar getchar_unlocked
// #define putchar putchar_unlocked
#define PVC(x) for(auto ___:(x))cout<<___<<" ";cout<<endl;
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;

int n,p[3];
string s[505];
bool v[505][505][4];

int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(cin>>n&&n){
        // MS0(s);
        MS0(p);
        MS0(v);
        for(int i=0;i<n;++i){
            cin>>s[i];
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(s[i][j]!='.'){
                    int reci=i,recj=j;
                    if(!v[i][j][0]){
                        v[i][j][0]=1;
                        while(j+1<n&&(s[i][j+1]==s[i][j])){
                            ++j;
                            v[i][j][0]=1;
                        }
                        if(j-recj==4){
                            p[s[reci][recj]-'A']++;
                            // cout<<reci<<" "<<recj<<" ,"<<s[reci][recj]<<"++ (0)\n";
                        }
                    }
                    i=reci,j=recj;
                    if(!v[i][j][1]){
                        v[i][j][1]=1;
                        while(i+1<n&&(s[i+1][j]==s[i][j])){
                            ++i;
                            v[i][j][1]=1;
                        }
                        if(i-reci==4){
                            p[s[reci][recj]-'A']++;
                            // cout<<reci<<" "<<recj<<" ,"<<s[reci][recj]<<"++ (1)\n";

                        }
                    }
                    i=reci,j=recj;
                    if(!v[i][j][2]){
                        v[i][j][2]=1;
                        while(i+1<n&&j+1<n&&(s[i+1][j+1]==s[i][j])){
                            ++i;++j;
                            v[i][j][2]=1;
                        }
                        if(j-recj==4){
                            p[s[reci][recj]-'A']++;
                            // cout<<reci<<" "<<recj<<" ,"<<s[reci][recj]<<"++ (2)\n";
                        }
                    }
                    i=reci,j=recj;
                    if(!v[i][j][3]){
                        v[i][j][3]=1;
                        // cout<<"->"<<reci<<" "<<recj<<endl;
                        while(j-1>=0&&i+1<n&&(s[i+1][j-1]==s[i][j])){
                            --j;++i;
                            // cout<<"  "<<i<<" "<<j<<endl;
                            v[i][j][3]=1;
                        }
                        if(i-reci==4){
                            p[s[reci][recj]-'A']++;
                            // cout<<reci<<" "<<recj<<" ,"<<s[reci][recj]<<"++ (3)\n";
                        }
                    }
                    i=reci,j=recj;
                }
            }
        }
        cout<<"A "<<p[0]<<"\nB "<<p[1]<<"\nC "<<p[2]<<"\n\n";
    }
}
