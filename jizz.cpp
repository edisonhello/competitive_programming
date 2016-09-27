#include<bits/stdc++.h>
using namespace std;

inline int _(string &a,string &s){
    if(s.length()>a.length()) return 0;
    int cnt=0;
    int f[10005]={0};
    f[0]=-1;f[1]=0;
    for(int i=1,j=1;i<(int)s.length();i++,j=i){
        while(s[i]!=s[f[j]] && j) j=f[j];
        f[i+1]=f[j]+1;
    }
    for(int i=0,j=0;i+j<(int)a.length();j++){
        // cout<<"i="<<i<<",j="<<j<<endl;
        if(a[i+j]==s[j]){
            if(j==(int)s.length()-1){
                cnt++;
                i+=s.length()-f[j+1];
                j-=s.length()-f[j+1];
            }
        }
        else{
            i+=j-f[j];
            j-=j-f[j]+1;
            if(j<-1)j=-1;
        }
    }
    return cnt;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;cin>>t;while(t--){
        string a;cin>>a;
        int n;cin>>n;while(n--){
            string b;cin>>b;
            cout<<_(a,b)<<endl;
        }
    }
}
