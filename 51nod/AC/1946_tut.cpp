#include<bits/stdc++.h>
using namespace std;

int c[1000006];
int d[1000006];

void p(int *a){
    int e;
    for(int i=1000004;i>=0;--i){
        if(a[i]){
            e=i;
            break;
        }
    }
    cout<<++e<<endl;
    for(int i=0;i<e;++i)cout<<a[i]<<" ";
    cout<<endl;
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>c[i];
    int m; cin>>m;
    for(int i=0;i<m;++i){
        int t; cin>>t;
        c[i]+=t;
    }
    for(int i=1000004;i>1;--i){
        if(c[i]>=2){
            ++c[i+1];
            ++c[i-2];
            c[i]-=2;
        }
        if(c[i-1] && c[i-2]){
            --c[i-2]; --c[i-1];
            ++c[i];
        }
    }
    if(c[0]>=2 && !c[1])c[0]-=2,++c[1];
    else if(c[1]>=3)--c[1],++c[0],++c[2];
    bool ok=1;
    // p(c);
    while(ok){
        ok=0;
        for(int i=0;i<1000004;++i){
            if(c[i] && c[i+1] && !c[i+2]){
                ++c[i+2];
                --c[i+1];
                --c[i];
                ok=1;
            }
        }
    }

    p(c);
}
