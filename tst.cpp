#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX=505;
const ll MOD=1e9+7;

inline int rdi() { return ((rand() << 15) ^ rand()) % MOD;	}

int mm(const int mat[MAX][MAX], int n) {
	ll tutte[n][n];
    memset(tutte, 0, sizeof(tutte));
    for (int i=0;i<n;++i) 
        for (int j=i+1;j<n;++j)
            if (mat[i][j]) tutte[j][i] = -(tutte[i][j] = rdi());
    int cnt=0;
    for (int i=0;i<n;++i) {
        for (int j=i+1;j<n;++j)
            while (tutte[j][i]) {
            	ll t=tutte[i][i] / tutte[j][i];
                for (int k=0;k<n;++k) {
                    tutte[i][k] = (tutte[i][k] - tutte[j][k] * t) % MOD;
                    swap(tutte[i][k], tutte[j][k]);
                }
            }
		if(tutte[i][i])	cnt++;
    }
    return cnt>>1;
}
int mat[MAX][MAX];
int n,m;
int main(){
	srand(time(0));
	cin>>n>>m;
	while(m--){
		int a,b;	cin>>a>>b;	a--;b--;
		mat[a][b]=mat[b][a]=1;
	}
	cout<<mm(mat,n)<< '\n';
}
