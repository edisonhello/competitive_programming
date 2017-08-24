#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define pii pair<int,int>
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue

set<char> reap;
int cntq;
string s;
map<char,int> cntc;

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    cin>>s;
    if(s.length()<26){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<26;i++){
        if(s[i]=='?'){
            cntq++;
        }
        else{
            cntc[s[i]]++;
            if(cntc[s[i]]>1){
                reap.insert(s[i]);
            }
        }
    }
    if(reap.size()==0){
        bool _[30]={0};
        for(auto i=cntc.begin();i!=cntc.end();i++){
            _[i->X-'A']=1;
        }
        int i=0,j;
        for(j=0;j<26;j++){
            if(s[j]!='?')cout<<s[j];
            else{
                for(;i<26;i++){
                    if(!_[i]){
                        _[i]=1;
                        cout<<(char)(i+'A');
                        break;
                    }
                }
            }
        }
        for(;j<(int)s.length();j++){
            cout<<(s[j]=='?'?'A':s[j]);
        }
        cout<<endl;
        return 0;
    }
    for(int i=26;i<(int)s.length();i++){
        if(s[i]==s[i-26])continue;
        if(s[i]=='?'){
            cntq++;
        }
        else{
            cntc[s[i]]++;
            if(cntc[s[i]]>1){
                reap.insert(s[i]);
            }
        }
        if(s[i-26]=='?'){
            cntq--;
        }
        else{
            cntc[s[i-26]]--;
            if(cntc[s[i-26]]==1){
                reap.erase(s[i-26]);
            }
        }
        if(reap.size()==0){
            bool _[30]={0};
            for(auto i=cntc.begin();i!=cntc.end();i++){
                _[i->X-'A']=1;
            }
            int k=0,j;
            for(j=0;j<=i-26;j++){
                cout<<(s[j]=='?'?'A':s[j]);
            }
            for(;j<=i;j++){
                if(s[j]!='?'){
                    cout<<s[j];
                }
                else{
                    for(;k<26;k++){
                        if(!_[k]){
                            _[k]=1;
                            cout<<(char)(k+'A');
                            break;
                        }
                    }
                }
            }
            for(;j<(int)s.length();j++){
                cout<<(s[j]=='?'?'A':s[j]);
            }
            cout<<endl;
            return 0;
        }
        // cout<<reap.size()<<" "<<cntq<<endl;
    }
    cout<<-1<<endl;
}
