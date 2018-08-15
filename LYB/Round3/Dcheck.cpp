#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 100006;
int x[N],y[N];
vector<int> v[N];
int rnd()
{
return (rand()&32767);
}
int myRnd(int L,int R)
{
return (((rnd()<<15)|rnd())) % (R-L+1) + L;
}
double ans = 1e100;
long long count_update = 0;
void update(int i,int j)
{
if (i==j) return;
count_update++;
ans = min(ans,sqrt(pow(x[i]-x[j],2) + pow(y[i]-y[j],2)));
}
int main ()
{
ios::sync_with_stdio(0); cin.tie(0);
srand(time(NULL));
int n;
cin >> n;
for (int i=1;n>=i;i++)
{
cin >> x[i] >>y[i];
}
int cnt = 100000; //random pair 的次數
cout<<ans<<endl;
while (cnt--)
{
int x,y;
do {
x = myRnd(1,n);
y = myRnd(1,n);
} while (x == y);
update(x,y);
}
int L = ceil(ans/2);
cout<<ans<<endl;
map<pii,int> mp; //這裡存著對於矩形 (i,j) 所使⽤的 vector 的編號
int id=0;
for (int i=1;n>=i;i++)
{
pii p = make_pair(x[i]/L,y[i]/L);
if (mp.find(p) == mp.end())
{
mp[p] = (++id);
}
v[ mp[p] ].push_back(i);
}
int dx[25] = {-2,-2,-2,-2,-2,-1,-1,-1,-1,-1,0,0
,0,0,0,1,1,1,1,1,2,2,2,2,2};
int dy[25] = {-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1
,2,-2,-1,0,1,2,-2,-1,0,1,2};
for (int i=1;n>=i;i++)
{
pii p = make_pair(x[i]/L,y[i]/L);
for (int k=0;25>k;k++)
{
pii pp = make_pair(p.first + dx[k],p.second + dy[k]);
if (mp.find(pp) == mp.end()) continue;
int ret = mp[pp];
for (int j:v[ret])
{
update(i,j);
}
}
}
cout <<"get dis: "<< fixed <<setprecision(6) << ans << endl;
cout << "count_update: "<<count_update<<endl;
}
