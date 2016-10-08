#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(cin>>s && s[0]!='E'){
        bool nt=0;
        for(int i=0;i<(int)s.length();i++){
            if(s[i]=='!'){
                nt=!nt;
                s[i]=' ';
            }
            if(s[i]=='0' && nt){
                s[i]='1';
                nt=0;
            }
            if(s[i]=='1' && nt){
                s[i]='0';
                nt=0;
            }
        }

        // cout<<"not processed:"<<s<<"--\n";

        for(int i=0;i<(int)s.length();i++){
            if(s[i]=='*'){
                int j,k;
                for(j=i;j>=0 && s[j]!='1' && s[j]!='0';j--){}
                for(k=i;k<(int)s.length() && s[k]!='1' && s[k]!='0';k++){}
                int jj=s[j]-'0';
                int kk=s[k]-'0';
                int res=jj&kk;
                // cout<<"process and with jj="<<jj<<" and kk="<<kk<<". res="<<res<<endl;
                s[i]=res+'0';
                s[j]=' ';
                s[k]=' ';
            }
        }

        // cout<<"and processed:"<<s<<"--\n";

        for(int i=0;i<(int)s.length();i++){
            if(s[i]=='+'){
                int j,k;
                for(j=i;j>=0 && s[j]!='1' && s[j]!='0';j--){}
                for(k=i;k<(int)s.length() && s[k]!='1' && s[k]!='0';k++){}
                int jj=s[j]-'0';
                int kk=s[k]-'0';
                int res=jj|kk;
                s[i]=res+'0';
                s[j]=' ';
                s[k]=' ';
            }
        }

        // cout<<"all processed:"<<s<<"--\n";

        for(int i=0;i<(int)s.length();i++){
            if(s[i]=='1' || s[i]=='0'){
                cout<<s[i]<<'\n';
            }
        }
    }
}
