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

vector<int> tmplid, tmp[100005];
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
        vector<int> tt;
        for (int j = 0; j < send; ++ j) {
            Afile >> bookid;
            if (tmpday < d && use[bookid] == 0) {
                cost ++;
                tt.emplace_back(bookid);
                if (cost == libs[lid].limit)
                    cost = 0, tmpday ++;
                use[bookid] = 1;
            }
        }
        if (tt.size()) {
            tmplid.emplace_back(lid);
            for (auto to : tt) tmp[i].emplace_back(to);
        }
    }

    cout << tmplid.size() << endl;
    for (int i = 0; i < tmplid.size(); ++ i) {
        cout << tmplid[i] << " " << tmp[i].size() << endl;
        for (int j = 0; j < tmp[i].size(); ++ j)
            cout << tmp[i][j] << " \n"[j + 1 == tmp[i].size()];
    }
    for (int i = 0; i < b; ++ i) if (use[i] == 1) ans_value += value[i];
    cerr << ans_value << "\n";
    return 0;
}
