/*THIS IS MY CODE*//*#include<bits/stdc++.h>
using namespace std;
string mp[10];
bool gone[10][10];
int n,gotshort,totshort,thistype,tottype=1;
struct _6{
    int a,b,c,d,f;
    char e;
};
queue<_6>goq;
void go(int nx,int ny,int px,int py,char dis,int len){ // cout<<"jizz"<<endl;
    gone[nx][ny] = 1;
    if(nx==px && ny==py){
        if(gotshort){
            if(len>gotshort){
                return;
            }
            else if(len==gotshort){
                thistype++;
            }
            else{
                thistype=0;
                gotshort=len;
            }
        }
        else{
            gotshort = len;
            thistype =   1;
        }
        goq.pop();
        return;
    }

    //cout<<mp[nx][ny]<<mp[nx+1][ny]<<endl<<mp[nx][ny+1]<<mp[nx+1][ny+1]<<endl;

    _6 t;
    if(nx!=0 && (mp[nx-1][ny]=='.' || mp[nx-1][ny]==dis) && !(gone[nx-1][ny])){
        t.a=nx-1;
        t.b=ny;
        t.c=px;
        t.d=py;
        t.e=dis;
        t.f=len+1;
        goq.push(t);
    }
    if(ny!=0 && (mp[nx][ny-1]=='.' || mp[nx][ny-1]==dis) && !(gone[nx][ny-1])){
        t.a=nx;
        t.b=ny-1;
        t.c=px;
        t.d=py;
        t.e=dis;
        t.f=len+1;
        goq.push(t);
    }
    if(nx<n-1 && (mp[nx+1][ny]=='.' || mp[nx+1][ny]==dis) && !(gone[nx+1][ny])){
        t.a=nx+1;
        t.b=ny;
        t.c=px;
        t.d=py;
        t.e=dis;
        t.f=len+1;
        goq.push(t);
    }//cout<<(ny<n-1 && (mp[nx][ny+1]=='.' || mp[nx][ny+1]==dis))<<endl;
    if(ny<n-1 && (mp[nx][ny+1]=='.' || mp[nx][ny+1]==dis) && !(gone[nx][ny+1])){
        t.a=nx;
        t.b=ny+1;
        t.c=px;     //cout<<"jizz"<<endl;
        t.d=py;
        t.e=dis;
        t.f=len+1;
        goq.push(t);        //cout<<goq.size()<<endl;
    }
    goq.pop();
}


int main(){

    int t=0;
    while(cin>>n && n && ++t){
        cout<<"Case "<<t<<": ";
        for(int i=0;i<n;i++){
            cin>>mp[i];
        }

        int posx[26],posy[26];
        memset(posx,0,sizeof(posx));
        memset(posy,0,sizeof(posy));
        for(int i=0;i<n;i++){
            posy[0] = mp[i].find('A');
            if(posy[0]!=string::npos){
                posx[0]=i;
                break;
            }
        }
        totshort=0;
        tottype =1;
        bool jizz = 0;
        for(int i=1;!(jizz);i++){
            //finding
            gotshort=0;
            thistype=0;

            bool fd=false;     // cout<<"jizz"<<endl;
            for(int a=0;a<n;a++){   //cout<<n<<endl;
                posy[i] = mp[a].find(i+65);
                if( posy[i] !=string::npos){
                    fd=true;
                    posx[i] = a;
                    break;
                }
            }   //    cout<<"asd"<<endl;
            if(!fd){    //cout<<"jizz";
                break;
            }
            else if(fd){
                _6 _;
                _.a=posx[i-1];
                _.b=posy[i-1];
                _.c=posx[i];
                _.d=posy[i];
                _.e=i+65;
                _.f=0;
                goq.push(_);
                memset(gone,0,sizeof(gone));
                while(goq.size()>0){
                    go(goq.front().a,goq.front().b,goq.front().c,goq.front().d,goq.front().e,goq.front().f);
                }
                mp[posx[0]][posy[0]]='.';
            }
            tottype*=thistype;
            if(tottype==0){
                cout<<"Impossible"<<endl;
                jizz = 1;
                break;
            }
            totshort+=gotshort;
            mp[posx[i]][posy[i]]='.';
            gotshort=0;
        }
        if(!jizz){
            cout<<totshort%20437<<" "<<tottype<<endl;
        }
    }
}
*//*THIS IS NOT MY CODE*/
#include <stdio.h>
#include <queue>
#include <algorithm>
#define mod 20437
using namespace std;
int n;
char g[20][20];
void sol() {
    int i, j, k, m = 0;
    int px[26], py[26];
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(g[i][j] >= 'A' && g[i][j] <= 'Z') {
                px[g[i][j]-'A'] = i;
                py[g[i][j]-'A'] = j;
                m = max(m, g[i][j]-'A');
            }
        }
    }
    int len = 0, path = 1;
    int x, y, tx, ty;
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    g[px[0]][py[0]] = '.';
    for(i = 0; i < m; i++) {
        queue<int> X, Y;
        int dist[20][20] = {}, dp[20][20] = {}, nt = i+1+'A';
        X.push(px[i]), Y.push(py[i]);
        dist[px[i]][py[i]] = 1;
        dp[px[i]][py[i]] = 1;
        while(!X.empty()) {
            x = X.front(), X.pop();
            y = Y.front(), Y.pop();
            for(int i = 0; i < 4; i++) {
                tx = x+dx[i], ty = y+dy[i];
                if(tx < 0 || ty < 0 || tx >= n || ty >= n)
                    continue;
                if(g[tx][ty] != '.' && g[tx][ty] != nt)
                    continue;
                if(dist[tx][ty] == 0) {
                    dist[tx][ty] = dist[x][y]+1;
                    X.push(tx), Y.push(ty);
                }
                if(dist[tx][ty] == dist[x][y]+1) {
                    dp[tx][ty] += dp[x][y];
                    dp[tx][ty] %= mod;
                }
            }
        }
        if(dist[px[i+1]][py[i+1]] == 0) {
            puts("Impossible");
            return;
        }
        len += dist[px[i+1]][py[i+1]]-1;
        len %= mod;
        path *= dp[px[i+1]][py[i+1]];
        path %= mod;
        g[px[i+1]][py[i+1]] = '.';
    }
    printf("%d %d\n", len, path);
}
int main() {
    int cases = 0, i;
    while(scanf("%d", &n) == 1 && n) {
        for(i = 0; i < n; i++)
            scanf("%s", g[i]);
        printf("Case %d: ", ++cases);
        sol();
    }
    return 0;
}
