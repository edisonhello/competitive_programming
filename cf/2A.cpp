#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<utility>
#include<queue>
#include<cstring>
using namespace std;

map<string,int> PtoI;
map<int,string> ItoP;

int pt[1005],kk[1005];
vector<pair<int,int>> rc;
queue<int> fst;

int getID(string &s){
    auto it=PtoI.find(s);
    if(it==PtoI.end()){
        PtoI[s]=PtoI.size();
        ItoP[PtoI.size()]=s;
        // cout<<"insert "<<s<<" for "<<PtoI.size()-1<<endl;
        // return PtoI.size()-1;
    }
    // cout<<"get id of "<<s<<" : "<<" "<<PtoI[s]<<endl;
    return PtoI[s];
}

int main(){
    string s;int inp,sc,sid;cin>>inp;while(inp--){
        cin>>s>>sc;
        sid=getID(s);
        rc.push_back({sid,sc});
        pt[sid]+=sc;
    }
    int mxpnt=-99999999;
    for(int i=0;i<(int)PtoI.size();++i){
        mxpnt=max({mxpnt,pt[i]});
    }
    // cout<<mxpnt<<endl;
    memset(pt,0,sizeof(pt));
    for(auto &p:rc){
        if(pt[p.first]>=mxpnt && pt[p.first]+p.second<mxpnt){
            ++kk[p.first];
        }
        if(pt[p.first]<mxpnt && pt[p.first]+p.second>=mxpnt){
            fst.push(p.first);
        }
        pt[p.first]+=p.second;
    }
    while(fst.size() && kk[fst.front()]){
        --kk[fst.front()];
        fst.pop();
    }
    cout<<ItoP[fst.front()]<<endl;
}
