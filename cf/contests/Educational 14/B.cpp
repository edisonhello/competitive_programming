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
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string n;
    cin>>n;

    map<char,char> c;
    c['A']='A';
    c['b']='d';
    c['d']='b';
    c['H']='H';
    c['I']='I';
    c['M']='M';
    c['O']='O';
    c['o']='o';
    c['p']='q';
    c['q']='p';
    c['T']='T';
    c['U']='U';
    c['V']='V';
    c['v']='v';
    c['W']='W';
    c['w']='w';
    c['X']='X';
    c['x']='x';
    c['Y']='Y';

    for(int i=0;i<n.length();i++){
        if(c.find(n[i])==c.end()){
            cout<<"NIE\n";
            return 0;
        }
    }
    for(int i=0;i<n.length()/2+1;i++){
        if(c[n[i]]!=n[n.length()-1-i]){
            cout<<"NIE\n";
            return 0;
        }
    }
    cout<<"TAK\n";
    return 0;
}
