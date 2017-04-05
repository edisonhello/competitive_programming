#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define sf(x) scanf(x)
#define pf(x) printf(x)
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
inline int rit(){
    int t=0,k=1;
    char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
}
int main(){
    int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    int asked=0;
    for(int i=0;i<15;i++){
        asked++;
        cout<<prime[i]<<endl;
        string s;
        cin>>s;
        if(s=="no")continue;
        if(s=="yes"){
            int in=prime[i];
            for(int times=0;asked<20&&in*prime[times]<=100;asked++,times++){
                cout<<in*prime[times]<<endl;
                cin>>s;
                if(s=="no")continue;
                if(s=="yes"){
                    cout<<"composite"<<endl;
                    return 0;
                }
            }

            break;
        }
    }
    cout<<"prime"<<endl;
}
