#include<bits/stdc++.h>
using namespace std;

int M(string &s, string &c){
    int f[10005]={0};
    f[0]=-1;
    for(int i=1;i<(int)c.length();i++){
        int j=i;
        while(c[i]!=c[f[j]] && j){
            // cout<<"i="<<i<<", j="<<j<<"\n";
            j=f[j];
        }
        f[i+1]=f[j]+1;
        // f[i+1]=(c[i]==c[f[i]])?(f[i]+1):((c[i]==c[0])?1:0);
    }
    // cout<<"f: ";
    // for(int i=0;i<(int)c.length();i++)cout<<f[i]<<" ";
    // cout<<f[c.length()]<<endl;
    int cnt=0;
    for(int st=0,cn=0;st+cn<(int)s.length();cn++){
        // cout<<"st="<<st<<",cn="<<cn<<", comparing "<<s[st+cn]<<" and "<<c[cn]<<":";
        if(s[st+cn]==c[cn]){
            // cout<<"found same:";
            if(cn==(int)c.length()-1){
                // cout<<"cnt++\n";
                cnt++;
                st+=c.length()-f[cn+1];
                cn-=c.length()-f[cn+1];
            }
            // else cout<<"continue cmping\n";
        }
        else{
            // cout<<"jizzed.\n";
            st+=cn-f[cn];
            cn-=cn-f[cn]+1;
            /*AC : if(cn<-1)cn=-1; */
        }
    }
    return cnt;
}

int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);

    int ts;cin>>ts;
    while(ts--){
        string s;
        cin>>s;
        int n;
        cin>>n;
        while(n--){
            string c;
            cin>>c;
            cout<<M(s,c)<<'\n';
        }
    }
}
