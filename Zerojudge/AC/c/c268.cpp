#include<bits/stdc++.h>
using namespace std;

int rec[80];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,n; cin>>t; while(t--){
        cin>>n; 
        if(n>=80){
            cin.ignore();
            cin.ignore(1000000000,'\n');
            puts("YES");
        }
        else{
            for(int i=0;i<n;++i)cin>>rec[i];
            sort(rec,rec+n);
            bool ok=0;
            for(int i=0;i+2<n;++i){
                if(rec[i]+rec[i+1]>rec[i+2]){ok=1; break;}
            }
            if(ok)puts("YES");
            else puts("NO");
        }
    }
}
