#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    srand(time(0)+clock());
    int t; cin>>t; while(t--){
        int n; cin>>n;
        string s; cin>>s;
        // int n=100000;
        // string s; for(int i=0;i<n;++i)if(rand()%3)s+=".";else s+="#";
        int x=0;
        while(s[x]=='#' && x<n)++x;
        if(x==n){
            cout<<0<<endl;
            continue;
        }
        int stone=x;
        bool imp=0;
        int ans=0;
        // cout<<"stone: "<<stone<<endl;
        // cout<<"x: "<<x<<endl;
        while(x<n){
            // cout<<"x: "<<x<<endl;
            if(s[x]=='.'){
                ++x;
                continue;
            }
            if(s[x]=='#'){
                // cout<<"got "<<x<<" is stone"<<endl;
                if(x==n-1){
                    cout<<-1<<endl;
                    imp=1;
                    break;
                }
                else if(s[x+1]=='.'){
                    s[x]='.';
                    ans+=x-stone;
                    s[stone]='#';
                    ++stone;
                    ++x;
                }
                else if(s[x+1]=='#'){
                    int lastmustto=x+2;
                    int countstone=0;
                    for(int y=x+2;y<=lastmustto;++y){
                        if(s[y]=='#'){
                            lastmustto+=2;
                            if(lastmustto>=n){
                                cout<<-1<<endl;
                                imp=1;
                                break;
                            }
                        }
                        else ;
                    }
                    if(!imp && lastmustto>=n){
                        cout<<-1<<endl;
                        imp=1;
                        break;
                    }
                    // cout<<"lastmustto: "<<lastmustto<<endl;
                    if(imp)break;
                    int ptr=lastmustto;
                    while(ptr>x){
                        if(s[ptr]=='#'){
                            ans+=lastmustto-ptr;
                            s[ptr]='.';
                            s[lastmustto]='#';
                            lastmustto-=2;
                        }
                        --ptr;
                    }
                }
            }
        }
        if(imp)continue;
        cout<<ans<<endl;
    }
}
