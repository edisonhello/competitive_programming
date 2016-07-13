#include<bits/stdc++.h>
using namespace std;

map<string,int> h;
map<int,string> uh;
vector<int> pts;
vector<pair<string,int> > moves;
// stack<pair<string,int> > hist;

int getn(string n){
    if(h.find(n)==h.end()){
        h[n] = h.size();
        uh[h[n]] = n;
    }
    return h[n];
}

int main(){
    int n;
    cin>>n;
    pts.resize(n);

    for(int i=0;i<n;i++){
        string name;int pt;
        cin>>name>>pt;
        int namen = getn(name);
        pts[namen] += pt;
        moves.push_back(make_pair(name,pt));
    }

    for(auto i:h){
        ;
    }
}
