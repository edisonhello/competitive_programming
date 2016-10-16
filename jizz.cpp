#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m, cnt, F[100];
string s, f;
stringstream ss;
vector<string> v;
vector<string> ret_query_both(const string&, const vector<string>&);
vector<string> ret_query_tail(const string&, const vector<string>&);
vector<string> ret_query_head(const string&, const vector<string>&);
bool kmp(const string&, const string&);
string trim(const string&);

int main() {
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) getline(cin, s), v.push_back(s);
  scanf("%d\n", &m);
  cnt = 1;
  for (int i = 0; i < m; ++i) {
    getline(cin, f);
    ss.clear();
    string ff = f;
    ss << f;
    vector<string> vv;
    for (int i = 0; i < v.size(); ++i) vv.push_back(v[i]);
    while (ss >> f) {
      if (f[0] == '*' && f[f.length() - 1] == '*') vv = ret_query_both(f, vv);
      else if (f[0] == '*') vv = ret_query_tail(f, vv);
      else if (f[f.length() - 1] == '*') vv = ret_query_head(f, vv);
    }
    printf("Query %d: ", cnt++);
    cout << ff;
    printf(", %lu item(s) is found.\n", vv.size());
    for (int i = 0; i < vv.size(); ++i) cout << vv[i] << endl;
    cout << endl;
  }
  return 0;
}

vector<string> ret_query_both(const string& s, const vector<string>& vv) {
  vector<string> ret;
  for (int i = 0; i < vv.size(); ++i) {
    if (kmp(vv[i], s.substr(1, s.length() - 2))) ret.push_back(vv[i]);
  }
  return ret;
}

vector<string> ret_query_tail(const string& s, const vector<string>& vv) {
  vector<string> ret;
  string query = s.substr(1, s.length() - 1);
  for (int i = 0; i < vv.size(); ++i) {
    if (vv[i].length() >= query.length() && vv[i].substr(vv[i].length() - query.length(), query.length()) == query) ret.push_back(vv[i]);
  }
  return ret;
}

vector<string> ret_query_head(const string& s, const vector<string>& vv) {
  vector<string> ret;
  string query = s.substr(0, s.length() - 1);
  for (int i = 0; i < vv.size(); ++i) {
    if (vv[i].length() >= query.length() && vv[i].substr(0, query.length()) == query) ret.push_back(vv[i]);
  }
  return ret;
}

bool kmp(const string& A, const string& B) {
  memset(F, 0, sizeof(F));
  F[0] = -1; F[1] = 0;
  int cnt = 0;
  for (int i = 1, j = 0; i < B.size() - 1; F[++i] = ++j) {
    while (j != -1 && B[i] != B[j]) j = F[j];
  }
  for (int i = 0, j = 0; i - j + B.size() <= A.size(); i++, j++) {
    while (j != -1 && A[i] != B[j]) j = F[j];
    if (j == B.size() - 1) return true;
  }
  return false;
}
