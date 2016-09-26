#include<bits/stdc++.h>
using namespace std;
int main(){
    int ts;
    cin>>ts;
    while(ts--){
        string a;
        cin>>a;
        int n;
        cin>>n;
        while(n--){
            string b;
            cin>>b;
            if(b.length()>a.length()) return 0;
            int f[10005]={0};
            int cnt=0;
            f[0]=-1;
            f[1]= 0;
            for(int i=1;i<(int)b.length();i++){
                int j=i;
                while(b[i]!=b[f[j]] && f[j]!=-1){
                    j=f[j];
                    // cout<<j<<endl;
                }
                f[i+1]=f[j]+1;
                // f[i+1]=(b[i]==b[f[i]]?f[i]+1:(b[i]==b[0]?1:0));
            }
            // cout<<"jizz";
            // cout<<"F:";for(int i=0;i<=b.length();i++)cout<<f[i]<<" ";cout<<endl;
            for(int st=0,cn=0;st+cn<(int)a.length();cn++){
                // cout<<st<<" "<<cn<<endl;
                if(a[st+cn]==b[cn]){
                    if(cn==(int)b.length()-1){
                        cnt++;
                        st+=b.length()-f[cn+1];
                        cn-=b.length()-f[cn+1];
                    }
                }
                else{
                    st+=cn-f[cn];
                    cn-=cn-f[cn]+1;
                    if(cn<-1)cn=-1;
                }
            }
            cout<<cnt<<endl;
        }
    }
}
