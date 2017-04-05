#include<bits/stdc++.h>
using namespace std;


inline int rit(){
    int t=0,k=1;char c;
    do{
        c = getchar();
        if(c=='-'){
            k=-1;
        }
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c = getchar();
    }while(c<='9'&&c>='0');
    return t*k;
}

int n,t;
float tow[11][11];

void sitm(){
    // cout<<"d"<<endl;
    tow[0][0]+=1;
    // cout<<"e"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            // cout<<i<<j<<endl;
            if(tow[i][j]>1){
                float m=tow[i][j]-1;
                tow[i][j]=1;
                if(i!=n-1){
                    tow[i+1][j]+=m/2;
                    tow[i+1][j+1]+=m/2;
                }
            }
        }
    }
}


int main(){
    n=rit();
    t=rit();
    // tow = new float*[n];
    // for(int i=0;i<n;i++){
    //     tow[i] = new float[i+1];
    // }
    // cout<<"a"<<endl;
    memset(tow,0,sizeof(tow));
    // cout<<"b"<<endl;

    for(int i=0;i<t;i++){
        // cout<<"c"<<endl;
        sitm();
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            if(tow[i][j]>=1){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}
