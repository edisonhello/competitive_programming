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




int n;

struct node{
    vector<int> connect;
    int clr;
};

node ene[500005];
int head[500005];

int go_1(int i, int* gone, int type){
    ene[i].clr = type;
    for(int j=0;j<(int)ene[i].connect.size();j++){
        if(gone[ene[i].connect[j]]){
            if(ene[ene[i].connect[j]].clr == ene[i].clr){
                return 1;
            }
        }
        gone[ene[i].connect[j]] = 1;
        go_1(ene[i].connect[j], gone, type==1?2:1);
    }
    return 0;
}

int chk(){
    int gone[500005];
    memset(gone,0,sizeof(gone));
    for(int i=1;i<=n;i++){
        if(!gone[i]){
            gone[i] = 1;
            int ret = go_1(i,gone,1);
            if(ret){
                return 1;
            }
        }
    }
    return 0;
}

int go_2(int i,int* gone,int y){
    for(int j=0;i<(int)ene[i].connect.size();j++){
        if(!gone[ene[i].connect[j]]){
            if(ene[i].connect[j] == y){
                return 1;
            }
            gone[ene[i].connect[j]] = 1;
            if(go_2(ene[i].connect[j],gone,y)){
                return 1;
            }
        }
    }
    return 0;
}

int isConnect(int x,int y){
    int gone[500005];
    memset(gone,0,sizeof(gone));
    gone[x] = 1;
    return go_2(x,gone,y);
}

int go_3(int i,int* gone,int y,int type){
    ene[i].clr = type;
    if(i == y){
        return 1;
    }
    for(int j=0;j<(int)ene[i].connect.size();j++){
        if(gone[ene[i].connect[j]]){
            if(ene[ene[i].connect[j]].clr == ene[i].clr){
                return -1;
            }
        }
        gone[ene[i].connect[j]] = 1;
        if(go_3(ene[i].connect[j], gone, y, type==1?2:1)){
            return 1;
        }
    }
    return 0;
}

void onColor(int x,int y){
    int gone[500005];
    memset(gone,0,sizeof(gone));
    gone[x] = 1;
    if(go_3(x,gone,y,1) == -1){
        cout<<"logic jizzed\n";
        return;
    }
}

int isEnemy(int x,int y){
    if(isConnect(x,y)){
        onColor(x,y);
        if(ene[x].clr==ene[y].clr){
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}

int findHead(int who){
    while(head[who]!=who){
        who = head[who];
    }
    return who;
}

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        head[i]=i;
    }

    string s,ss,sss;
    int x,y;
    while(cin>>s>>ss>>sss>>x>>y){
        int xhead = findHead(x);
        int yhead = findHead(y);
        if(s[0]=='y'){
            if(sss[0]=='e'){
                // you are enemies x y;
                cout<<"b";
                if(xhead == yhead){
                    cout<<"angry\n";
                }
                else{
                    // x and y are enemy;
                    ene[x].connect.PB(y);
                    ene[y].connect.PB(x);

                    if(chk()){
                        cout<<"angry\n";
                        ene[x].connect.pop_back();
                        ene[y].connect.pop_back();
                    }
                }
            }
            else{
                // you are friends x y;
                if(!isEnemy(xhead,yhead)){
                    xhead = yhead;
                }
                else{
                    cout<<"angry\n";
                }
            }
        }
        else{
            if(sss[0]=='e'){
                // are you enemies x y;
                if(isEnemy(xhead,yhead)){
                    cout<<"yeap\n";
                }
                else{
                    cout<<"nope\n";
                }

            }
            else{
                // are you friends x y;
                if(xhead == yhead){
                    cout<<"yeap\n";
                }
                else{
                    cout<<"nope\n";
                }
            }
        }
    }
}
