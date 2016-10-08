#include<iostream>
using namespace std;

int alp[30];

int main(){
    int n;
    cin>>n;
    while(n--){
        memset(alp,0,sizeof(alp));
        int k;
        cin>>k;
        string s;
        cin>>s;
        int mx=0;
        for(int i=0;i<k;i++){
            alp[s[i]-'a']++;
            mx=max(mx,alp[s[i]-'a']);
        }
        for(int i=0;i<26;i++){
            if(alp[i]==mx){
                cout<<(char)(i+'a');
            }
        }
        cout<<'\n';
    }
}
