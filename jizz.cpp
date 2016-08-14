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

vector<string> rec;
map<char,int> m;
map<char,char> t;
int main(){
    string s;
    while(cin>>s && s!="jizz"){
        for(int i=0;i<(int)s.length();i++){
            m[s[i]]++;
        }
        rec.PB(s);
    }

    /*for(auto i=m.begin();i!=m.end();i++){
        cout<<i->X<<" => "<<i->Y<<endl;
    }*/


    t['{'] = '{';
    t['}'] = '}';
    t['_'] = '_';
    t['w'] = 'i';
    t['W'] = 'I';
    t['v'] = 'c';
    t['V'] = 'C';
    t['y'] = 'e';
    t['Y'] = 'E';
    t['k'] = 't';
    t['K'] = 'T';
    t['t'] = 'f';
    t['T'] = 'F';
    t['z'] = 'l';
    t['Z'] = 'L';
    t['l'] = 'h';
    t['L'] = 'H';
    t['!'] = '!';
    t['G'] = 'W';
    t['g'] = 'w';
    t['e'] = 'o';
    t['E'] = 'O';
    t['c'] = 'm';
    t['C'] = 'M';
    t['.'] = '.';
    t['\''] = '\'';
    t['d'] = 's';
    t['D'] = 'S';
    t[','] = ',';
    t['o'] = 'r';
    t['O'] = 'R';
    t['j'] = 'a';
    t['J'] = 'A';
    t['x'] = 'v';
    t['X'] = 'V';
    t['s'] = 'u';
    t['S'] = 'U';
    t['m'] = 'n';
    t['M'] = 'N';
    

    for(int i=0;i<(int)rec.size();i++){
        for(int j=0;j<(int)rec[i].length();j++){
            if(t[rec[i][j]]==NULL) putchar('?');
            else putchar(t[rec[i][j]]);
        }
        putchar('\n');
        cout<<rec[i];
        cout<<endl<<endl;
    }
    putchar('\n');
}
