#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x+5)
#define X first
#define Y second
#define M (l+r)/2

/*inline ll rit(){
    ll t=0,k=1;
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
}*/

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin>>n;
    string bbbbbbb;
    getline(cin,bbbbbbb);
    for(int i=0;i<n;i++){
        string line;
        getline(cin,line);
        stringstream ss;
        ss<<line;
        string s;
        ss>>s;
        // cout<<"af"<<endl;
        // cout<<s<<endl;
        string P;
        int _not=0;
        while(ss>>s&&s!="THEN"){
            // cout<<s<<endl;
            if(s=="and"){
                P+=" or";
            }
            else if(s=="or"){
                P+=" and";
            }
            else if(s=="not"){
                _not=1;
            }
            else if(s.length()==1){
                if(_not){
                    P+=" "+s;
                    _not=0;
                }
                else{
                    P+=" not "+s;
                }
            }
            else{
                cout<<"jizz"<<endl;
                return 0;
            }
        }
        string Q;
        while(ss>>s){
            if(s=="and"){
                Q+=" or";
            }
            else if(s=="or"){
                Q+=" and";
            }
            else if(s=="not"){
                _not=1;
            }
            else if(s.length()==1){
                if(_not){
                    Q+=" "+s;
                }
                else{
                    Q+=" not "+s;
                }
            }
            else{
                cout<<"jizz"<<endl;
                return 0;
            }
        }
        cout<<"IF"<<Q<<" THEN"<<P<<""<<endl;
    }
}
