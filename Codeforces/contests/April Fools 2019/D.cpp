#include <bits/stdc++.h>
using namespace std;

int a[87];

int main() {
    int n; cin >> n;
    int mn = 55;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    cout << (2 + (a[3] ^ mn)) << endl;
}

#ifdef MEOW
WR->COR WORD
t -> r ftying
w -> t saniwation
o -> a 
p -> b
l -> r spleading
u -> a
s -> c spases
x -> c selextive
o -> a
r -> n deliverirg
t -> g
h -> z recognihes
i -> e ripresent
r -> f userul
d -> b urdan
a -> o
n -> h
d -> p
m -> n desigm
i -> o
n -> s
e -> i berds(?)
l -> f modilied
m -> s releamed
e -> o
n -> m environnent
t -> c defetate

two plus xor third and min elment
#endif
