#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
typedef long double ld;

const ld eps = 1e-9;

#define F first
#define S second

pii operator-(const pii &p1,const pii &p2)
{
    return make_pair(p1.F - p2.F,p1.S - p2.S);
}

LL cross(pii a,pii b)
{
    return a.F*b.S - a.S*b.F;
}

ld get_dis(pii a,pii b)
{
    return sqrt((a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S));
}

vector<pii> v[18];

LL area[18];

#define SZ(x) ((int)(x).size())

void gao(vector<pii> &sagiri)
{
    //cout << "SZ(sagiri) = " << SZ(sagiri) << endl;
    sort(sagiri.begin(),sagiri.end());
    vector<pii> up,down;
    //use down first
    for (pii p:sagiri)
    {
        if (SZ(down) && p == down.back()) continue;
        //cout << "hihi" << endl;
        if (SZ(down) < 2) down.push_back(p);
        else
        {
            while (SZ(down) >= 2 && cross(down[ SZ(down)-1 ] - down[ SZ(down)-2 ] , p - down[ SZ(down)-2 ]) <= 0) down.pop_back();
            down.push_back(p);
        }
    }
    reverse(sagiri.begin(),sagiri.end());
    for (pii p:sagiri)
    {
        if (SZ(up) && p == up.back()) continue;
        if (SZ(up) < 2) up.push_back(p);
        else
        {
            while (SZ(up) >= 2 && cross(up[ SZ(up)-1 ] - up[ SZ(up)-2 ] , p - up[ SZ(up)-2 ]) <= 0) up.pop_back();
            up.push_back(p);
        }
    }
}

int main ()
{
    //ios::sync_with_stdio(0); cin.tie(0);
    clock();
    LL k,l;
    scanf("%lld %lld",&k,&l);
    for (int i=0;k>i;i++)
    {
        int n;
        scanf("%d",&n);
        //cin >> n;
        while (n--)
        {
            LL x,y;
            scanf("%lld %lld",&x,&y);
            //cin >> x >> y;
            v[i].push_back(make_pair(x,y));
        }
        for (int _=0;SZ(v[i])>_;_++)
        {
            if (_ + 2 >= SZ(v[i])) break;
            //cout << "_ = " << _ <<" , cross = " << (cross(v[i][_+1] - v[i][0],v[i][_+2]-v[i][0])) << endl;
            area[i] += (cross(v[i][_+1] - v[i][0],v[i][_+2]-v[i][0]));
        }
        area[i] = abs(area[i]);
        gao(v[i]);
    }
    LL ans=0;
    if (k <= 10)
    {
        for (int mask=1;(1<<k)>mask;mask++)
        {
            vector<pii> sagiri;
            for (int i=0;k>i;i++)
            {
                if (((1<<i)&mask) != 0)
                {
                    for (pii p:v[i]) sagiri.push_back(p);
                }
            }
            //cout << "SZ(sagiri) = " << SZ(sagiri) << endl;
            sort(sagiri.begin(),sagiri.end());
            vector<pii> up,down;
            //use down first
            for (pii p:sagiri)
            {
                if (SZ(down) && p == down.back()) continue;
                //cout << "hihi" << endl;
                if (SZ(down) < 2) down.push_back(p);
                else
                {
                    while (SZ(down) >= 2 && cross(down[ SZ(down)-1 ] - down[ SZ(down)-2 ] , p - down[ SZ(down)-2 ]) <= 0) down.pop_back();
                    down.push_back(p);
                }
            }
            reverse(sagiri.begin(),sagiri.end());
            for (pii p:sagiri)
            {
                if (SZ(up) && p == up.back()) continue;
                if (SZ(up) < 2) up.push_back(p);
                else
                {
                    while (SZ(up) >= 2 && cross(up[ SZ(up)-1 ] - up[ SZ(up)-2 ] , p - up[ SZ(up)-2 ]) <= 0) up.pop_back();
                    up.push_back(p);
                }
            }
            //cout << "SZ up = " << SZ(up) << " , SZ down = " << SZ(down) <<endl;
            ld len = 0;
            assert(up[0] == down.back());
            assert(up.back() == down.front());
            for (int i=0;SZ(down)-1>i;i++) len += get_dis(down[i],down[i+1]);
            for (int i=0;SZ(up)-1>i;i++) len += get_dis(up[i],up[i+1]);
            if (len - eps <= l)
            {
                LL tmp=0;
                /*
                for (int i=0;SZ(down)>i;i++)
                {
                    if (i + 2 >= SZ(down)) break;
                    tmp += cross(down[i+1] - down[0] , down[i+2] - down[0]);
                }
                for (int i=0;SZ(up)>i;i++)
                {
                    if (i + 2 >= SZ(up)) break;
                    tmp += cross(up[i+1] - up[0] , up[i+2] - up[0]);
                }*/
                //cout << "l = " << len << endl;
                //cout << "tmp = " << tmp << " mask = " << mask << endl;
                //ans = max(ans,tmp);
                //cout << "tmp = " << tmp << endl;
                for (int i=0;k>i;i++)
                {
                    if (((1<<i)&mask) != 0) tmp += area[i];
                }
                ans = max(ans,tmp);
            }
            //cout <<"len = "<<len<<endl;
        }
        if (ans%2 == 0) printf("%lld.0\n",ans/2);
        else printf("%lld.5\n",ans/2);
    }
    else
    {
        srand(880301);
        while ((double)clock()/CLOCKS_PER_SEC < 0.99)
        {
            int mask = (rand()) & ((1<<k)-1);
            vector<pii> sagiri;
            for (int i=0;k>i;i++)
            {
                if (((1<<i)&mask) != 0)
                {
                    for (pii p:v[i]) sagiri.push_back(p);
                }
            }
            //cout << "SZ(sagiri) = " << SZ(sagiri) << endl;
            sort(sagiri.begin(),sagiri.end());
            vector<pii> up,down;
            //use down first
            for (pii p:sagiri)
            {
                if (SZ(down) && p == down.back()) continue;
                //cout << "hihi" << endl;
                if (SZ(down) < 2) down.push_back(p);
                else
                {
                    while (SZ(down) >= 2 && cross(down[ SZ(down)-1 ] - down[ SZ(down)-2 ] , p - down[ SZ(down)-2 ]) <= 0) down.pop_back();
                    down.push_back(p);
                }
            }
            reverse(sagiri.begin(),sagiri.end());
            for (pii p:sagiri)
            {
                if (SZ(up) && p == up.back()) continue;
                if (SZ(up) < 2) up.push_back(p);
                else
                {
                    while (SZ(up) >= 2 && cross(up[ SZ(up)-1 ] - up[ SZ(up)-2 ] , p - up[ SZ(up)-2 ]) <= 0) up.pop_back();
                    up.push_back(p);
                }
            }
            //cout << "SZ up = " << SZ(up) << " , SZ down = " << SZ(down) <<endl;
            ld len = 0;
            assert(up[0] == down.back());
            assert(up.back() == down.front());
            for (int i=0;SZ(down)-1>i;i++) len += get_dis(down[i],down[i+1]);
            for (int i=0;SZ(up)-1>i;i++) len += get_dis(up[i],up[i+1]);
            if (len - eps <= l)
            {
                LL tmp=0;
                /*
                for (int i=0;SZ(down)>i;i++)
                {
                    if (i + 2 >= SZ(down)) break;
                    tmp += cross(down[i+1] - down[0] , down[i+2] - down[0]);
                }
                for (int i=0;SZ(up)>i;i++)
                {
                    if (i + 2 >= SZ(up)) break;
                    tmp += cross(up[i+1] - up[0] , up[i+2] - up[0]);
                }*/
                //cout << "l = " << len << endl;
                //cout << "tmp = " << tmp << " mask = " << mask << endl;
                //ans = max(ans,tmp);
                //cout << "tmp = " << tmp << endl;
                for (int i=0;k>i;i++)
                {
                    if (((1<<i)&mask) != 0) tmp += area[i];
                }
                ans = max(ans,tmp);
            }
            //cout <<"len = "<<len<<endl;
        }
        if (ans%2 == 0) printf("%lld.0\n",ans/2);
        else printf("%lld.5\n",ans/2);
    }
}
