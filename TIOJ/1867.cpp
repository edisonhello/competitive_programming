#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define DE cout<<"de"<<endl;
struct P{ld x,y;};
ostream &operator<<(ostream &ostm,P p){
    ostm<<p.x<<" "<<p.y;
    return ostm;
}

ld cross(P a,P b,P m){
    P va=(P){a.x-m.x,a.y-m.y};
    P vb=(P){b.x-m.x,b.y-m.y};
    return va.x*vb.y-va.y*vb.x;
}

int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);

    string ss;
    while(getline(cin,ss)){
        stringstream sss;
        sss<<ss;
        ld x,y;
        vector<P> S;
        while(sss>>x>>y){
            S.push_back((P){x,y});
        }
        cin>>x>>y;

        if(cross(S[S.size()-1],S[0],(P){x,y})<0){
            for(int i=1;i<(int)S.size();++i){
                if(cross(S[i-1],S[i],(P){x,y})>0){
                    cout<<"Stop\n";
                    goto end;
                }
            }
        }
        else{
            for(int i=1;i<(int)S.size();++i){
                if(cross(S[i-1],S[i],(P){x,y})<0){
                    cout<<"Stop\n";
                    goto end;
                }
            }
        }

        cout<<"Hit him\n";

        end:
        getline(cin,ss);
    }
}
