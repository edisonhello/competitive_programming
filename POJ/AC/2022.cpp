#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cstdlib>
#include <cassert>
using namespace std;

int URL(char s[], int len) {
    int i = 0;
    if (len < 11) return false;
    if (s[0] != 'h' || s[1] != 't' || s[2] != 't' || s[3] != 'p' || s[4] != ':' || s[5] != '/' || s[6] != '/') return -1;
    while (i < len && s[i] != '<' && s[i] != '>') ++i;
    if (i == len) return -1;
    if (s[i] == '<') return -1;
    if (s[i - 4] != '.' || s[i - 3] != 'c' || s[i - 2] != 'o' || s[i - 1] != 'm') return -1;
    return i;
}

bool TEXT(char s[], int len) {
    if (len == 0) return true;
    for (int i = 0; i < len; ) {
        while (i < len && s[i] != '<' && s[i] != '>') ++i;
        if (i == len) return true;
        if (s[i] == '>') return false;
        assert(s[i] == '<');
        if (i + 6 >= len) return false;
        if (s[i + 1] != 'A' && s[i + 1] != 'B' && s[i + 1] != 'I') return false;
        int ASTART = i;
        if (s[i + 1] == 'I' || s[i + 1] == 'B') {
            if (s[i + 2] != '>') return false;
        } else {
            if (i + 7 >= len) return false;
            if (s[i + 2] != ' ' || s[i + 3] != 'H' || s[i + 4] != 'R' || s[i + 5] != 'E' || s[i + 6] != 'F' || s[i + 7] != '=') return false;
            ASTART = URL(s + i + 8, len - i - 8);
            if (ASTART < 0) return false;
        }
        stack<char> st; st.push(s[i + 1]);
        int j = i + 2;
        while (st.size()) {
            while (j < len && s[j] != '<') ++j;
            if (j + 2 >= len) return false;
            if (s[j + 1] == '/' && j + 3 >= len) return false;
            ++j;
            if (s[j] == '/') {
                ++j;
                if (s[j] != 'A' && s[j] != 'B' && s[j] != 'I') return false;
                if (s[j] != st.top()) return false;
                st.pop();
            } else {
                if (s[j] != 'A' && s[j] != 'B' && s[j] != 'I') return false;
                st.push(s[j]);
            }
        }
        j += 2;
        if (s[i + 1] != 'A') {
            if (!TEXT(s + i + 3, j - 4 - i - 3)) return false;
        } else {
            if (!TEXT(s + i + 8 + ASTART + 1, j - 4 - i - 8 - ASTART - 1)) return false;
        }
        i = j;
    }
    return true;
}

bool BODY(char s[], int len) {
    if (len < 13) return false;
    if (s[0] == '<' && s[1] == 'B' && s[2] == 'O' && s[3] == 'D' && s[4] == 'Y' && s[5] == '>' &&
        s[len - 7] == '<' && s[len - 6] == '/' && s[len - 5] == 'B' && s[len - 4] == 'O' && s[len - 3] == 'D' && s[len - 2] == 'Y' && s[len - 1] == '>') {
        return TEXT(s + 6, len - 13);
    }
    return false;
}

bool HTML(char s[], int len) {
    if (len < 13) return false;
    if (s[0] == '<' && s[1] == 'H' && s[2] == 'T' && s[3] == 'M' && s[4] == 'L' && s[5] == '>' &&
        s[len - 7] == '<' && s[len - 6] == '/' && s[len - 5] == 'H' && s[len - 4] == 'T' && s[len - 3] == 'M' && s[len - 2] == 'L' && s[len - 1] == '>') {
        return BODY(s + 6, len - 13);
    }
    return false;
}

bool check(char s[]) {
    return HTML(s, strlen(s));
}

char s[1055];

int main() {
    int n; scanf("%d\n", &n); while (n--) {
        scanf("%1005[^\n]\n", s);
        cout << (check(s) ? "Syntax Included" : "No Syntax Included") << '\n';
    }
}
