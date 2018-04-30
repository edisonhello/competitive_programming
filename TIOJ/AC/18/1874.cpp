#include<bits/stdc++.h>
using namespace std;

vector<int> p;
int to[10000007];
void init(){
    for(int i=2;i<3500;++i){
        if(to[i])continue;
        p.push_back(i);
        for(int j=i*i;j<10000001;j+=i){
            if(!to[j])to[j]=i;
        }
    }
}

// int z[10000007];

int main(){
    init();
    // for(int i=1;i<=10;++i)cout<<i<<" "<<to[i]<<endl;
    int n; scanf("%d",&n); while(n--){
        int x; scanf("%d",&x);
        int c=1,xx=x;
        // if(!z[x]){
            int p=0,cc=1;
            while(x>1){
                if(!to[x]){
                    if(x!=p)c*=cc,cc=2;
                    else ++cc;
                    c*=cc;
                    break;
                }
                if(to[x]!=p){
                    c*=cc;
                    p=to[x];
                    cc=1;
                }
                else{
                    x/=to[x];
                    ++cc;
                }
            }
//             z[xx]=c;
//         }
        // else c=z[x];
        printf("%d\n",c);
    }
}
