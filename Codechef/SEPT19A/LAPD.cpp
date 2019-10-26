#include <bits/stdc++.h>
                        using namespace std;

                        const int mod = 1000000007;

                        int main() {
                            int t; cin >> t; while (t--) {
                                long long a, b, c; cin >> a >> b >> c;
                                long long z = 0;
                                for (int bb = 1; bb <= b; ++bb) {
                                    long long aa = a - bb, cc = c - bb;
                                    if (aa <= 0 || cc <= 0) break;
                                    cerr << "bb = " << bb << ", aa = " << aa << " cc = " << cc << endl;
                                    z = (z + aa * cc - 1) % mod;
                                }
                                z = (z % mod + mod) % mod;
                                cout << z << '\n';
                            }
                        }
