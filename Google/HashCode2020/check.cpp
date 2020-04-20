#include <bits/stdc++.h>
using namespace std;

int value[100005];

struct Library {
	vector<int> books;
	int signup_cost;
	int limit;
	int lib_id;
    long long sum;
};

int use[100005];
int main(int argc, char **argv) {
    assert(argc == 3);
    
    ifstream Dfile, Afile;
    Dfile.open(argv[1]);
    Afile.open(argv[2]);
	int b, l, d;
    Dfile >> b >> l >> d;
    vector<Library> libs(b);
	for (int i = 0; i < b; ++i)
		Dfile >> value[i];

	for (int i = 0; i < l; ++i) {
		int book_count;
		Dfile >> book_count >> libs[i].signup_cost >> libs[i].limit;
		libs[i].lib_id = i;
        libs[i].sum = 0;
		for (int j = 0; j < book_count; ++j) {
			int t; Dfile >> t;
			libs[i].books.push_back(t);
            libs[i].sum += value[t];
		}
	}
    
    int ansl, nowday = 0;
    long long ans_value = 0;
    Afile >> ansl;
    for (int i = 0; i < ansl; ++ i) {
        int lid, send, bookid;
        Afile >> lid >> send;
        nowday += libs[lid].signup_cost;
        int tmpday = nowday, cost = 0;
        for (int j = 0; j < send; ++ j) {
            Afile >> bookid;
						if (use[bookid]) continue;
            if (tmpday < d) {
                cost ++;
                if (cost == libs[i].limit)
                    cost = 0, tmpday ++;
                use[bookid] = 1;
            }
        }
    }
    for (int i = 0; i < b; ++ i) if (use[i] == 1) ans_value += value[i];
    cout << ans_value << "\n";
    return 0;
}
