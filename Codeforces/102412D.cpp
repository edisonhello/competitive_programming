#pragma GCC optimize("O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;

const int kN = 120005;
const int kY = 300;
const int kZ = 600;

struct Block {
    Block *prev, *next;
    vector<int> vec, pre_min, suf_max;
    vector<int> sorted;
    int lowest_u;
    int highest_d;
    int has_answer;

    Block() {
        prev = next = 0;
        lowest_u = 200000;
        highest_d = -1;
        has_answer = 0;
    }

    bool exist(int l, int r) {
        if (l >= r) return false;
        auto it = upper_bound(sorted.begin(), sorted.end(), l);
        if (it != sorted.end() && *it < r) return true;
        return false;
    }

    void maintain() {
        sorted = vec;
        sort(sorted.begin(), sorted.end());

        pre_min = vec;
        suf_max = vec;
        for (int i = 1; i < (int)pre_min.size(); ++i) pre_min[i] = min(pre_min[i - 1], pre_min[i]);
        for (int i = (int)suf_max.size() - 2; i >= 0; --i) suf_max[i] = max(suf_max[i + 1], suf_max[i]);

        lowest_u = 200000;
        for (int i = 1; i < (int)pre_min.size(); ++i) {
            if (vec[i] > pre_min[i - 1]) lowest_u = min(lowest_u, vec[i]);
        }
        highest_d = -1;
        for (int i = 0; i < (int)suf_max.size() - 1; ++i) {
            if (vec[i] < suf_max[i + 1]) highest_d = max(highest_d, vec[i]);
        }

        has_answer = 0;
        for (int i = 1; i < (int)vec.size() - 1; ++i) {
            has_answer |= (pre_min[i - 1] < vec[i]) && (vec[i] < suf_max[i + 1]);
        }
    }

    void append(Block *&b) {
        for (int i : b->vec) vec.push_back(i);
        maintain();
    }

    Block *split(Block *&to, int lsz) {
        to = new Block();
        for (int i = lsz; i < (int)vec.size(); ++i) to->vec.push_back(vec[i]);
        vec.resize(lsz);
        maintain();
        to->maintain();
		if (next) next->prev = to;
		to->next = next;
		next = to;
		to->prev = this;
        return this;
    }

    int get_min() { return sorted[0]; }
    int get_max() { return sorted.back(); }
} *head, *tail;


int n;
int h[kN], hnext[kN], hprev[kN];

int block_pre_min[kN], block_suf_max[kN];

void cut_block(int x) {
	// cerr << "cut_block " << x << endl;
	Block *now = head;
	while (now) {
		int sz = now->vec.size();
		if (x == 0) return;
		if (x < sz) {
			Block *b;
			now->split(b, x);
			if (tail == now) tail = b;
			return;
		}
		x -= sz;
		now = now->next;
	}
}

Block *get_block(int x) {
	// cerr << "get_block " << x << endl;
	Block *now = head;
	while (now) {
		int sz = now->vec.size();
		// cerr << "sz = " << sz << endl;
		if (x < sz) {
			assert(x == 0);
			return now;
		}
		x -= sz;
		now = now->next;
	}
	assert(false);
}

void print_status() {
	cout << "|";
	Block *b = head;
	int nn = 0;
	while (b) {
		for (int i : b->vec) cout << i << ' ';
		cout << "|";
		b = b->next;
		++nn;
	}
	cout << endl;
	cout << "pre: "; for (int i = 1; i <= nn; ++i) cout << block_pre_min[i] << ' '; cout << endl;
	cout << "suf: "; for (int i = 1; i <= nn; ++i) cout << block_suf_max[i] << ' '; cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    for (int i = 0; i <= n + 1; ++i) hnext[i] = i + 1, hprev[i] = i - 1;
	h[0] = n + 1;
	h[n + 1] = 0;

    for (int i = 0; i <= n + 1; ) {
        int j = min(n + 1, i + kZ);
        Block *b = new Block();
        for (int k = i; k <= j; ++k) b->vec.push_back(h[k]);
        b->maintain();
        if (!head) head = tail = b;
        else tail->next = b, b->prev = tail, tail = b;
        // cout << "l r = " << i << ' ' << j << endl;
        i = j + 1;
    }

    int rebuild_count = kY;
    int q; cin >> q; while (q--) {
        int l, r, k; cin >> l >> r >> k;
		// cerr << "Query " << l << ' ' << r << ' ' << k << endl;
		k = r - l + 1 - k;
        // move_real(l, r, k);

        int mi = l + k - 1;

		if (k && mi != r) {
			cut_block(l);
			cut_block(mi + 1);
			cut_block(r + 1);

			Block *lb = get_block(l);
			Block *mb = get_block(mi + 1);
			Block *rb = get_block(r + 1);

			// lb->prev = rb->prev;
			// mb->prev = lb->prev;
			// rb->prev = mb->prev;
			// lb->prev->next = mb;
			// mb->prev->next = rb;
			// rb->prev->next = lb;

			tie(lb->prev, mb->prev, rb->prev, lb->prev->next, mb->prev->next, rb->prev->next) = 
				make_tuple(rb->prev, lb->prev, mb->prev, mb, rb, lb);

			--rebuild_count;
		}

        if (rebuild_count == 0) {
            rebuild_count = kY;
			// cerr << "rebuild start" << endl;
            
            Block *now = head, *new_head = 0, *new_tail;
            vector<int> hhh;

            vector<Block *> old_blocks;
            for (; now; now = now->next) {
                for (int i : now->vec) hhh.push_back(i);
                old_blocks.push_back(now);
            }

            for (Block *b : old_blocks) delete b;

            for (int i = 0; i <= n + 1; ) {
                int j = min((int)hhh.size() - 1, i + kZ);
                Block *b = new Block();
                for (int k = i; k <= j; ++k) b->vec.push_back(hhh[k]);
                b->maintain();
                if (!new_head) new_head = new_tail = b;
                else new_tail->next = b, b->prev = new_tail, new_tail = b;
                i = j + 1;
            }
            head = new_head, tail = new_tail;

			// cerr << "rebuild end" << endl;
        }

        int i = 1;
        Block *now = head;
        bool yes = false;

        int pre_min = 200000;

        block_pre_min[0] = 200000;
        for (; now; ++i, now = now->next) {
			// cerr << "do pre " << i << " prev " << now->prev << " now " << now << " next " << now->next << endl;
            if (now->has_answer) yes = true;

            if (now->get_max() > pre_min) yes = true;
            pre_min = min(pre_min, now->lowest_u);

            block_pre_min[i] = min(block_pre_min[i - 1], now->get_min());
        }

        int suf_max = -1;
        block_suf_max[i] = -1;
        for (--i, now = tail; now; now = now->prev, --i) {
			// cerr << "do suf " << i << " prev " << now->prev << " now " << now << " next " << now->next << endl;
            if (now->get_min() < suf_max) yes = true;
            suf_max = max(suf_max, now->highest_d);

            block_suf_max[i] = max(block_suf_max[i + 1], now->get_max());
        }

        for (++i, now = head; now; now = now->next, ++i) {
            if (now->exist(block_pre_min[i - 1], block_suf_max[i + 1])) 
				yes = true;
        }

   		cout << (yes ? "YES" : "NO") << '\n';
        
		// print_status();
    }
}
