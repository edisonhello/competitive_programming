#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<stdio.h>
#include<set>
#include<map>
#include<sstream>
#include<cassert>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
ll G(ll a,ll b){if(b==0)return a;return G(b,a%b);}
const ll mod=1000000007ll;
bool mark[2222222];
int a[2222],b[2222];
int main(){
    ios_base::sync_with_stdio(false);
    int n,res=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mark[a[i]]=1;
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        mark[b[i]]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mark[a[i]^b[j]])res++;
        }
    }
    if(res%2)cout<<"Koyomi";
    else cout<<"Karen";
}
