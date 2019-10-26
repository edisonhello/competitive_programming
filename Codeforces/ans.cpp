    #include<bits/stdc++.h>
    using namespace std;
     
    typedef pair<int, int> ii;
    typedef long long ll;
     
    const int lim = 1e6+5, ms = 4e5+5, inf = 0x3f3f3f3f, mod = 1e9+7;
     
    int adj[ms], ant[ms], to[ms], z, deg[ms];
    int maior[ms], segunda[ms];
     
    void update(int v, int h) {
    	if(h > maior[v]) {
    		segunda[v] = maior[v];
    		maior[v] = h;
    	} else if(h > segunda[v]) {
    		segunda[v] = h;
    	}
    }
     
    ll fExp(ll a, ll b) {
    	ll ans = 1;
    	while(b) {
    		if(b & 1) ans = ans * a % mod;
    		a = a * a % mod;
    		b >>= 1;
    	}
    	return ans;
    }
     
    ll calculate(int h, int n) {
    	ll ans = (fExp(2, h + 1) - 1 - n + mod) % mod;
    	return ans;
    }
     
    void dfs1(int v, int par = -1) {
    	for(int e = adj[v]; e > -1; e = ant[e]) {
    		if(to[e] != par) {
    			dfs1(to[e], v);
    			update(v, maior[to[e]] + 1);
    		}
    	}
    }
     
    void dfs2(int v, int par = -1) {
    	if(par != -1) {
    		if(maior[par] == maior[v] + 1) update(v, segunda[par] + 1);
    		else update(v, maior[par] + 1);
    	}
    	for(int e = adj[v]; e > -1; e = ant[e]) {
    		if(to[e] != par) dfs2(to[e], v);
    	}
    }
     
     
    int main(){
    	cin.tie(0);
    	cin.sync_with_stdio(false);
    	int t;
    	cin >> t;
    	while(t--) {
    		int n;
    		cin >> n;
    		for(int i = 1; i <= n; i++) adj[i] = -1, deg[i] = 0, maior[i] = 0, segunda[i] = 0;
    		z = 0;
    		for(int i = 0; i < n - 1; i++) {
    			int a, b;
    			cin >> a >> b;
    			deg[a]++; deg[b]++;
    			to[z] = b;
    			ant[z] = adj[a];
    			adj[a] = z++;
    			swap(a, b);
    			to[z] = b;
    			ant[z] = adj[a];
    			adj[a] = z++;
    		}
    		int deuRuim = 0;
    		for(int i = 1; i <= n; i++) if(deg[i] > 3) deuRuim++;
    		if(deuRuim) {
    			cout << -1 << '\n';
    			continue;
    		}
    		dfs1(1);
    		dfs2(1);
    		int menorH = inf, menorAns = 0;
    		for(int i = 1; i <= n; i++) {
    			if(deg[i] < 3 && maior[i] < menorH) {
    				menorH = maior[i];
    				menorAns = i;
    			}
    		}
    		cout << menorAns << ' ' << calculate(menorH, n) << '\n';
    	}
    	return 0;
    }
