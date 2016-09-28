#include<bits/stdc++.h>
using namespace std;

int a[100];
bool app[100];
string s;
int n;

int dfs(int st,int dg,int pos){
    if(pos==n||st>=(int)s.length())return 1;
    if(s[st]=='0') return -1;
    if(dg==2){
        stringstream ss;
        ss<<s.substr(st,dg);
        int t;ss>>t;
        // cout<<"in st:"<<st<<" ,tring "<<t<<endl;
        if(t<=n && !app[t]){
            app[t]=1;
            a[pos]=t;
            if(dfs(st+2,1,pos+1)==-1){
                if(dfs(st+2,2,pos+1)==-1){
                    app[t]=0;
                    return -1;
                }
            }
            return 1;
        }
        else{
            return -1;
        }
    }
    else{
        int t=s[st]-'0';
        // cout<<"in st:"<<st<<" ,tring "<<t<<endl;
        if(t<=n && !app[t]){
            app[t]=1;
            a[pos]=t;
            if(dfs(st+1,1,pos+1)==-1){
                if(dfs(st+1,2,pos+1)==-1){
                    app[t]=0;
                    return -1;
                }
            }
            return 1;
        }
        else{
            return -1;
        }
    }
}

int main(){
    cin>>s;
    cout<<s<<endl;;
    if(s.length()<10)n=s.length();
    else n=(s.length()+9)/2;
    // cout<<"counting maxn="<<n<<endl;

    if(dfs(0,2,0)==-1){
        dfs(0,1,0);
    }

    for(int i=0;i<n;i++){
        if(i)cout<<' ';
        cout<<a[i];
    }
    cout<<'\n';
}
