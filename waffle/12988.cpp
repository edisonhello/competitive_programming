#include <bits/stdc++.h>
using namespace std;
struct point{
    int x, y;
} a[20];
char M[20][20], T[20][20];
bool ans;
int cnt;
bool check(){
    bool f[5][150];
    memset(f, 0, sizeof f);
    for ( int i=0; i<4; ++i )
        for ( int j=0; j<4; ++j ){
            char c = (M[i][j]=='*'?T[i][j]:M[i][j]);
            if ( f[i][c] ) return false;
            f[i][c] = true;
        }
    memset(f, 0, sizeof f);
    for ( int i=0; i<4; ++i )
        for ( int j=0; j<4; ++j ){
            char c = (M[j][i]=='*'?T[j][i]:M[j][i]);
            if ( f[i][c] ) return false;
            f[i][c] = true;
        }
    return true;
}
void dfs ( int d ){
    if ( ans ) return;
    if ( d == cnt ){
        if ( check() ){
            for ( int i=0; i<4; ++i ){
               for ( int j=0; j<4; ++j )
                   cout << (M[i][j]=='*'?T[i][j]:M[i][j]);
                cout << '\n';
            }
            ans = true;
        }
        return;
    }
    for ( int i=1; i<=4; ++i ){
        T[a[d].x][a[d].y] = (char)(i+'0');
        dfs(d+1);
    }
}
int main(){
    ios::sync_with_stdio( false );
    cin.tie(0);
    int t;
    cin >> t;
    for ( int k=1; k<=t; ++k ){
        cout << "Case #" << k << ":\n";
        ans = cnt = 0;
        for ( int i=0; i<4; ++i )
            for ( int j=0; j<4; ++j ){
                cin >> M[i][j];
                if ( M[i][j] == '*' ) a[cnt].x = i, a[cnt++].y = j;
            }
        dfs(0);
    }
}
