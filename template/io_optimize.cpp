
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
// #define fread fread_unlocked
// #define fwrite fwrite_unlocked
inline char gtx() {
    const int N=4096;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    } return *p++;
}

template <typename T>
inline void rit(T &x) {
    char c; bool fg = 0;
    while (c = gtx(), (c < '0' && c != '-') || c > '9');
    c == '-' ? (fg = 1, x = 0) : (x = c & 15);
    while (c = gtx(), c >= '0' && c <= '9') x = x * 10 + (c & 15);
    if (fg) x = -x;
}
template <typename T, typename ...Args>
inline void rit(T& x, Args& ...args) { rit(x), rit(args...); }

template <typename T>
inline void ruit(T &x) {
    char c;
    while (c = gtx(), c < '0' || c > '9');
    x = c & 15;
    while (c = gtx(), c >= '0' && c <= '9') x = x * 10 + (c & 15);
}
template <typename T, typename ...Args>
inline void ruit(T& x, Args& ...args) { ruit(x), ruit(args...); }

template <typename T>
inline bool rit_save(T &x) {
    char c; bool fg = 0;
    while (c = gtx(), (c < '0' && c != '-') || c > '9') if (c == EOF) return false;
    c == '-' ? (fg = 1, x = 0) : (x = c & 15);
    while (c = gtx(), c >= '0' && c <= '9') x = x * 10 + (c & 15);
    if (fg) x = -x; return true;
}
template <typename T, typename ...Args>
inline bool rit_save(T& x, Args& ...args) { return rit_save(x) && rit_save(args...); }

template <typename T>
inline bool ruit_save(T &x) {
    char c;
    while (c = gtx(), c < '0' || c > '9') if (c == EOF) return false;
    x = c & 15;
    while (c = gtx(), c >= '0' && c <= '9') x = x * 10 + (c & 15);
    return true;
}
template <typename T, typename ...Args>
inline bool ruit_save(T& x, Args& ...args) { return ruit_save(x) && ruit_save(args...); }

struct outputter {
    char buffer[4112], *ptr = buffer, *end = buffer + 4096;
    inline void writebyte(char c) {
        *ptr = c; ++ptr;
        if (ptr > end) fwrite(buffer, sizeof(char), ptr-buffer, stdout), ptr = buffer;
    }
    template <typename T> inline void writeint(T x, char endc = '\n') {
        if (x < 0) *ptr = '-', ++ptr, x = -x; if (!x) *ptr = '0', ++ptr;
        char *s = ptr, c; T t;
        while (x) { t = x / 10; c = x - 10 * t + '0'; *ptr = c, ++ptr, x = t; }
        char *f = ptr - 1; while (s < f) swap(*s, *f), ++s, --f;
        *ptr = endc, ++ptr;
        if (ptr > end) fwrite(buffer, sizeof(char), ptr - buffer, stdout), ptr = buffer;
    }

    template <typename T>
    inline void output(T x) { writeint(x, '\n'); }
    template <typename T,typename ...Args>
    inline void output(T x,Args ...args) { writeint(x, ' '); output(args...); }

    template <typename ...Args> inline void operator()(Args ...args) { output(args...); }
    outputter() {}
    ~outputter() { fwrite(buffer, sizeof(char), ptr - buffer, stdout); }
} pit;
#pragma GCC diagnostic pop
