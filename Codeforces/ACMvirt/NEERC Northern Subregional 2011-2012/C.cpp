#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
string s[6];

bool conn[6][6];
int id[6];
vector<string> dice;

string spin(string s,vector<pair<int,int>> &dir){
    string rt=s;
    for(auto &p:dir)rt[p.first]=s[p.second];
    return rt;
}

void buildspin(vector<pair<int,int>> &v,int d1,int d2,int d3,int d4){
    v.emplace_back(d1-1,d2-1);
    v.emplace_back(d2-1,d3-1);
    v.emplace_back(d3-1,d4-1);
    v.emplace_back(d4-1,d1-1);
}

bool equiv(string s, string t) {
    vector<pair<int,int>> spx,spy,spz;
    buildspin(spx,1,3,6,5);
    buildspin(spy,2,3,4,5);
    buildspin(spz,1,4,6,2);
    auto checkspin=[&](string s,string t)->bool{
        if(s==t || spin(s,spy)==t || spin(spin(s,spy),spy)==t || spin(spin(spin(s,spy),spy),spy)==t)return 1;
        return 0;
    };
    if( checkspin(s,t) || checkspin(spin(s,spx),t) || checkspin(spin(s,spz),t) ||
        checkspin(spin(spin(s,spx),spx),t) || checkspin(spin(spin(spin(s,spx),spx),spx),t) || checkspin(spin(spin(spin(s,spz),spz),spz),t) )return 1;
    return 0;

    /* vector<int> o(6);
    iota(o.begin(), o.end(), 0);
    for (int i = 0; i < 6; ++i) for (int j = 0; j < 6; ++j) conn[i][j] = true;
    for (int i = 0; i < 6; ++i) conn[i][i] = false;
    conn[0][5] = conn[5][0] = conn[1][3] = conn[3][1] = conn[2][4] = conn[4][2] = false;
    do {
        bool z = true;
        for (int i = 0; i < 6; ++i) z &= (s[i] == t[o[i]]);
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) z &= (conn[i][j] == conn[o[i]][o[j]]);
        }
        if (z) return true;
    } while (next_permutation(o.begin(), o.end()));
    return false; */
}

void add(string s) {
    // cout << "jizz " << s << endl;
    bool eq = false;
    for (string t : dice) if (equiv(t, s)) eq = true;
    if (!eq && dice.size() < 2u) dice.push_back(s);
}

int main(){
    freopen("cube.in", "r", stdin);
    freopen("cube.out", "w", stdout);
    for(int i=0;i<6;++i)cin>>s[i];
    for(int i=0;i<6;++i)id[i]=i;
    do{
        multiset<char> topside,side,botside;
        for(int i=1;i<5;++i)topside.insert(s[id[0]][i]);
        for(int i=1;i<5;++i)side.insert(s[id[i]][0]);
        if(topside!=side)continue;
        for(int i=1;i<5;++i)botside.insert(s[id[5]][i]);
        if(botside!=side)continue;
        auto jizz=[&](int z,int a,int b)->bool{
            multiset<char> look,fact;
            fact.insert(s[id[0]][0]);
            fact.insert(s[id[5]][0]);
            fact.insert(s[id[a]][0]);
            fact.insert(s[id[b]][0]);
            for(int i=1;i<5;++i)look.insert(s[id[z]][i]);
            if(look!=fact)return 1;
            return 0;
        };
        if(jizz(1,2,4) || jizz(2,1,3) || jizz(3,2,4) || jizz(4,1,3))continue;
        add(string(1,s[id[0]][0])+s[id[1]][0]+s[id[2]][0]+s[id[3]][0]+s[id[4]][0]+s[id[5]][0]);
    }while(next_permutation(id,id+6));
    if (dice.size() == 0) {
        cout << "Impossible" << endl;
    } else {
        for (auto s : dice) cout << s << endl;
    }
    return 0;
}
