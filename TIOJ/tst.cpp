#include<bits/stdc++.h>
using namespace std;
int a[20][20];

int main(){
    int n, a, b, c, d, t;
    a = b = 1, c = 2, d = 0;
    scanf("%d", &n);
    while(n){
        if(n & 1){
            t = c;
            c = a * c + 5 * b * d >> 1;
            d = a * d + b * t >> 1;
        }
        t = a;
        a = a * a + 5 * b * b >> 1;
        b = t * b;
        n >>= 1;
    }
    printf("%d", d);
}
