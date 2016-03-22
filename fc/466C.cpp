#include<bits/stdc++.h>
using namespace std;
int n,*ary;
int ans=0;
int l,r;
void go(){
    while(1){
        if(l>r){
            return ;
        }
        int lc=0,mc=0,rc=0;
        for(int i=0;i<l;i++){
            lc+=ary[i];
        }
        for(int i=l;i<r;i++){
            mc+=ary[i];
        }
        for(int i=r;i<n;i++){
            rc+=ary[i];
        }
        if(lc==mc && mc==rc){
            ans++;              printf("ans++ @ l%d r%d\n",l,r);
            int oril=l;
            int orir=r;
            r--;
            for(;ary[r]==0 && !(l>r+1);r--){
                for(;ary[l]==0 && !(l>r+1);l++){
                    ans++;      printf("ans++ @ l%d r%d\n",l,r);
                }
                l=oril;
            }
            for(;ary[l]==0&&!(l>r);l++){}
            continue;
        }
        if(lc>mc){
            r--;
        }
        else{
            l++;
        }
    }
}


int main(){
    cin>>n;
    ary=new int[n];
    for(int i=0;i<n;i++){
        cin>>ary[i];
    }
    l=1;
    r=n-1;
    go();
    printf("%d\n",ans);
}
