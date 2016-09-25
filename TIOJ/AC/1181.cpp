#include<string>
#include<iostream>
#include<cstring>
using namespace std;
int n,c,i,t;
string s;
bool app[5];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    while(n--){
        memset(app,0,sizeof(app));
        t=0;
        for(i=0;i<12;i++){
            cin>>s;
            for(c=0;c<6;c++){
                if(s[c]=='G'){
                    app[1]=1;
                }
                else if(s[c]=='R'){
                    app[0]=1;
                }
                else if(s[c]=='B'){
                    app[2]=1;
                }
                else if(s[c]=='Y'){
                    app[3]=1;
                }
                else if(s[c]=='P'){
                    app[4]=1;
                }
            }
        }
        for(i=0;i<6;i++){
            if(app[i]) t++;
        }
        cout<<t<<'\n';
    }
}
