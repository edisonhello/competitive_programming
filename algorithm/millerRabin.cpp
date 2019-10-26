// for int
namespace millerRabin {
	uint32_t ts[] = {2, 7, 61};
	uint32_t pow(uint32_t b, uint32_t n, uint32_t m, uint32_t a = 1){
	    b %= m; while (n) {
	        if (n & 1) a = 1ll * a * b % m;
	        b = 1ll * b * b % m; n >>= 1;
	    } return a;
	}
	
	bool isPrime(uint32_t n){
	    if (n == 2) return 1;
	    if (!(n & 1) || n == 1) return 0;
	    uint32_t nn = n - 1;
        int t = 0;
	    while (!(nn & 1)) nn >>= 1, ++t;
	    for (uint32_t ptr = 0u; ptr < 3u; ++ptr) {
	        uint32_t a=ts[ptr] % n;
	        if (a == 0 || a == 1 || a == n - 1) continue;
	        a = pow(a, nn, n);
	        if (a == 1 || a == n - 1) continue;
	        for (int i = 0; i < t - 1; ++i) {
	            a = 1ll * a * a % n;
	            if (a == 1) return 0;
	            if (a == n - 1) break;
	        }
	        if (a == n - 1) continue;
	        return 0;
	    } return 1;
	}
}

// for long long 
namespace millerRabin {
	uint64_t ts[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	uint64_t mul(uint64_t b, uint64_t n, uint64_t m, uint64_t a = 0){
 	    b %= m; while (n) {
	        if (n & 1) a = (a + b) % m;
	        b = (b + b) % m; n >>= 1;
	    } return a;
	}
	uint64_t pow(uint64_t b, uint64_t n, uint64_t m, uint64_t a = 1){
	    b %= m; while (n) {
	        if (n & 1) a = mul(a, b, m);
	        b = mul(b, b, m); n >>= 1;
	    } return a;
	}
	
	bool isPrime(uint64_t n){
	    if (n == 2) return 1;
	    if (!(n & 1) || n == 1) return 0;
	    uint64_t nn = n - 1;
        int t = 0;
	    while (!(nn & 1)) nn >>= 1, ++t;
	    for (uint32_t ptr = 0u; ptr < 12u; ++ptr) {
	        uint64_t a=ts[ptr] % n;
	        if (a == 0 || a == 1 || a == n - 1) continue;
	        a = pow(a, nn, n);
	        if (a == 1 || a == n - 1) continue;
	        for (int i = 0; i < t - 1; ++i) {
	            a = mul(a, a, n);
	            if (a == 1) return 0;
	            if (a == n - 1) break;
	        }
	        if (a == n - 1) continue;
	        return 0;
	    } return 1;
	}
}

