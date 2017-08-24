#include<string>
#include<iostream>

using namespace std;

string s,t;
int n;
int sw[234];
bool um[234];
char a[234],b[234];

int main(){
    cin>>s>>t;
    for(int i=0;i<(int)s.length();++i){
        if(s[i]==t[i]){
            um[s[i]]=1;
            if(sw[s[i]]){
                cout<<-1<<endl;
                return 0;
            }
        }
        else{
            if(um[s[i]] || um[t[i]]){
                cout<<-1<<endl;
                return 0;
            }
            else if(sw[s[i]] && sw[s[i]]!=t[i]){
                cout<<-1<<endl;
                return 0;
            }
            else if(sw[t[i]] && sw[t[i]]!=s[i]){
                cout<<-1<<endl;
                return 0;
            }
            else if(!sw[s[i]]){
                sw[s[i]]=t[i];
                sw[t[i]]=s[i];
                a[n]=s[i];
                b[n]=t[i];
                ++n;
            }
        }
    }
    cout<<n<<endl;
    for(int i=0;i<n;++i){
        cout<<a[i]<<" "<<b[i]<<endl;
    }
}
