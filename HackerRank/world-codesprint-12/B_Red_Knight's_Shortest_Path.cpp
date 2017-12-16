#include <bits/stdc++.h>

using namespace std;


#define X first
#define Y second
int cf[222][222],v[222][222],n;
bool ok(int x,int y){
    return x>=0 && x<n && y>=0 && y<n;
}
void printShortestPath(int NN, int x1, int y1, int x2, int y2) {
    swap(x1,y1); swap(x2,y2);
    queue<pair<int,int>> q; q.emplace(x1,y1); v[x1][y1]=1; n=NN;
    while(q.size()){
        if(ok(q.front().X-1,q.front().Y-2) && !v[q.front().X-1][q.front().Y-2]){
            v[q.front().X-1][q.front().Y-2]=1;
            cf[q.front().X-1][q.front().Y-2]=1;
            q.emplace(q.front().X-1,q.front().Y-2);
        }
        if(ok(q.front().X+1,q.front().Y-2) && !v[q.front().X+1][q.front().Y-2]){
            v[q.front().X+1][q.front().Y-2]=1;
            cf[q.front().X+1][q.front().Y-2]=2;
            q.emplace(q.front().X+1,q.front().Y-2);
        }
        if(ok(q.front().X+2,q.front().Y) && !v[q.front().X+2][q.front().Y]){
            v[q.front().X+2][q.front().Y]=1;
            cf[q.front().X+2][q.front().Y]=4;
            q.emplace(q.front().X+2,q.front().Y);
        }
        if(ok(q.front().X+1,q.front().Y+2) && !v[q.front().X+1][q.front().Y+2]){
            v[q.front().X+1][q.front().Y+2]=1;
            cf[q.front().X+1][q.front().Y+2]=6;
            q.emplace(q.front().X+1,q.front().Y+2);
        }
        if(ok(q.front().X-1,q.front().Y+2) && !v[q.front().X-1][q.front().Y+2]){
            v[q.front().X-1][q.front().Y+2]=1;
            cf[q.front().X-1][q.front().Y+2]=5;
            q.emplace(q.front().X-1,q.front().Y+2);
        }
        if(ok(q.front().X-2,q.front().Y) && !v[q.front().X-2][q.front().Y]){
            v[q.front().X-2][q.front().Y]=1;
            cf[q.front().X-2][q.front().Y]=3;
            q.emplace(q.front().X-2,q.front().Y);
        }
        q.pop();
    }
    if(cf[x2][y2]){
        stack<int> ans;
        while(cf[x2][y2]){
            ans.push(cf[x2][y2]);
            if(cf[x2][y2]==1)x2+=1,y2+=2;
            else if(cf[x2][y2]==2)x2-=1,y2+=2;
            else if(cf[x2][y2]==3)x2+=2;
            else if(cf[x2][y2]==4)x2-=2;
            else if(cf[x2][y2]==5)x2+=1,y2-=2;
            else if(cf[x2][y2]==6)x2-=1,y2-=2;
        }
        cout<<ans.size()<<endl;
        while(ans.size()){
            if(ans.top()==1)cout<<"UL ";
            if(ans.top()==2)cout<<"UR ";
            if(ans.top()==3)cout<<"L ";
            if(ans.top()==4)cout<<"R ";
            if(ans.top()==5)cout<<"LL ";
            if(ans.top()==6)cout<<"LR ";
            ans.pop();
        }
    }
    else cout<<"Impossible"<<endl;
}

int main() {
    int n;
    cin >> n;
    int i_start;
    int j_start;
    int i_end;
    int j_end;
    cin >> i_start >> j_start >> i_end >> j_end;
    printShortestPath(n, i_start, j_start, i_end, j_end);
    return 0;
}

