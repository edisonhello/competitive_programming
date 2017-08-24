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
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2

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
};

int n;
ll a[505][505];
ll rowadd[505];
int rowhave0[505];
ll crs[5];
int crshave0[5];

int main(){
    cin>>n;
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    ull magic=0;
    int maybehaveans=1;
    int x,y;
    for(int i=0;i<n;i++){
        ull thisnum=0;
        int therehave0=0;
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(a[i][j]==0){
                therehave0=1;
                rowhave0[j]=1;
                x=i;y=j;
            }
            else if(!therehave0){
                thisnum+=(ll)a[i][j];
            }
            rowadd[j]+=(ll)a[i][j];
            if(i==j){
                if(a[i][j]==0){
                    crshave0[0]=1;
                }
                else{
                    crs[0]+=(ll)a[i][j];
                }
            }
            if(i+j==n-1){
                if(a[i][j]==0){
                    crshave0[1]=1;
                }
                else{
                    crs[1]+=(ll)a[i][j];
                }
            }
        }
        if(!therehave0){
            if(!magic){
                magic=thisnum;
            }
            else{
                if(thisnum!=magic){
                    maybehaveans=0;
                }
            }
        }
    }
    if(!crshave0[0]){
        if(crs[0]!=magic){
            maybehaveans=0;
        }
    }
    if(!crshave0[1]){
        if(crs[1]!=magic){
            maybehaveans=0;
        }
    }
    for(int i=0;i<n;i++){
        if(!rowhave0[i]){
            // cout<<i<<endl;
            if(rowadd[i]!=magic){
                maybehaveans=0;
                break;
            }
        }
    }
    if(!maybehaveans){
        cout<<"-1"<<endl;
        return 0;
    }
    else{
        // cout<<magic-rowadd[y]<<endl;
        a[x][y]=magic-rowadd[y];

        if(a[x][y]<=0){
            cout<<-1<<endl;
            return 0;
        }

        // ll rowadd[505];
        memset(rowadd,0,sizeof(rowadd));
        // int rowhave0[505];
        memset(rowhave0,0,sizeof(rowhave0));
        // ll crs[5];
        memset(crs,0,sizeof(crs));
        // int crshave0[5];
        memset(crshave0,0,sizeof(crshave0));

        magic=0;
        maybehaveans=1;
        for(int i=0;i<n;i++){
            ull thisnum=0;
            int therehave0=0;
            for(int j=0;j<n;j++){
                if(a[i][j]==0){
                    therehave0=1;
                    rowhave0[j]=1;
                    x=i;y=j;
                }
                else if(!therehave0){
                    thisnum+=(ll)a[i][j];
                }
                rowadd[j]+=(ll)a[i][j];
                if(i==j){
                    if(a[i][j]==0){
                        crshave0[0]=1;
                    }
                    else{
                        crs[0]+=(ll)a[i][j];
                    }
                }
                if(i+j==n-1){
                    if(a[i][j]==0){
                        crshave0[1]=1;
                    }
                    else{
                        crs[1]+=(ll)a[i][j];
                    }
                }
            }
            if(!therehave0){
                if(!magic){
                    magic=thisnum;
                }
                else{
                    if(thisnum!=magic){
                        maybehaveans=0;
                    }
                }
            }
        }
        if(!crshave0[0]){
            if(crs[0]!=magic){
                maybehaveans=0;
            }
        }
        if(!crshave0[1]){
            if(crs[1]!=magic){
                maybehaveans=0;
            }
        }
        for(int i=0;i<n;i++){
            if(!rowhave0[i]){
                // cout<<i<<endl;
                if(rowadd[i]!=magic){
                    maybehaveans=0;
                    break;
                }
            }
        }
        if(!maybehaveans){
            cout<<"-1"<<endl;
            return 0;
        }
        else{
            cout<<a[x][y]<<endl;
        }
    }
}
