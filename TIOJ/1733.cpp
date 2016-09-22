#include<bits/stdc++.h>
using namespace std;

int rn,cn;
int m[55][55];
int add[55][55];

int main(){
    while(cin>>rn>>cn){
        memset(m,0,sizeof(m));
        memset(add,0,sizeof(add));
        for(int i=1;i<=rn;i++){
            for(int j=1;j<=cn;j++){
                cin>>m[i][j];
                for(int k=1;k<=i;k++){
                    add[k][j]+=m[i][j];
                }
            }
        }
        int mx=-(1<<28);
        for(int i=1;i<=rn;i++){
            for(int j=i;j<=rn;j++){
                int cur=0,prv=0;;
                for(int k=1;k<=cn;k++){
                    cur+=(add[j][k]-add[i-1][k]);
                    mx=max(mx,cur);
                    if(cur<add[j][k]-add[i-1][k])cur=add[j][k]-add[i-1][k];
                    mx=max(mx,cur);
                }
            }
        }
        cout<<mx<<endl;
    }
}
