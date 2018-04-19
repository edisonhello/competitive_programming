#include <cstdio>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

typedef double type_ans;
typedef double data;

type_ans ans = 1e30;
pair<int,int> ansid;
int repeat;

inline type_ans sq(data a) { return a * a; }

struct point {
    int id;
    data x, y, z;
    type_ans dis(const point& i) const { return sq(x - i.x) + sq(y - i.y) + sq(z - i.z); }
} pt[500003];

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%lf%lf%lf", &pt[i].x, &pt[i].y, &pt[i].z), pt[i].id = i + 1;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            type_ans tmp = pt[i].dis(pt[j]);
            if (tmp < ans) {
                ans = tmp;
                repeat = 0;
                ansid = {pt[i].id, pt[j].id};
            }
            else if (tmp == ans) {
                repeat = 1;
            }
        }
        if((i & 1023) == 0)printf("now run %lf%%\n", (double)i / N * 100.);
    }
    
    printf("WARNING: galaxy%d and galaxy%d in %.3lf Uu\n", ansid.first, ansid.second, sqrt(ans));
    printf("Check: repeat: %d\n", repeat);
}
