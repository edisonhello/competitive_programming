#include<bits/stdc++.h>
using namespace std;

int mrand(int l,int r){
    return floor((double)rand()/RAND_MAX*(r-l+1)+l);
}

int ans[10003];
int now[10203];

void calc(int n,int k,int solution){
    if(!solution){
        int cas=mrand(0,3);
        if(!cas)for(int i=1;i<=n;++i)now[i]=mrand(1,9);
        else{
            for(int i=1;i<=n;++i)now[i]=ans[i];
            for(int i=1;i<=n;++i){
                int turns=mrand(0,9);
                while(turns--){
                    for(int j=0;j<k;++j){
                        ++now[i+j];
                        if(now[i+j]>9)now[i+j]-=9;
                    }
                }
            }
            
        }
    }
    else{
        for(int i=1;i<=n;++i)now[i]=ans[i];
        for(int i=1;i<=n-k+1;++i){
            int turns=mrand(0,9);
            while(turns--){
                for(int j=0;j<k;++j){
                    ++now[i+j];
                    if(now[i+j]>9)now[i+j]-=9;
                }
            }
        }
    }
}

bool isok(int n){
    for(int i=1;i<=n;++i)if(ans[i]!=now[i])return 1;
    return 0;
}

int main(){
    srand(time(0));
    int n=mrand(10000,10000),k=mrand(99,99); 
    cout<<n<<" "<<k<<endl;
    for(int i=1;i<=n;++i)cout<<(ans[i]=mrand(1,9))<<" "; cout<<endl;
    int solution=mrand(0,3);
    do{
        calc(n,k,solution);
    }while(!isok(n));
    for(int i=1;i<=n;++i)cout<<now[i]<<" "; cout<<endl;
}
