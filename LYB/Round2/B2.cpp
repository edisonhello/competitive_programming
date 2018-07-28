/*input
3 5 2
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

double ppow(double a , int k){
    if(k == 0) return 1;
    if(k % 2 == 0) return ppow(a * a , k >> 1);
    if(k % 2 == 1) return ppow(a * a , k >> 1) * a;
}
double n , m;
int k;
int32_t main(){
    // IOS;
    cin >> n >> m >> k;
    double ans = n * m * (1.0 - ppow((n + m - 2) / (n + m) , k));
    // printf("%.11f\n" , ppow((n + m - 2) / (n + m) , k));
    printf("%.11f\n" , ans);
    return 0;
}