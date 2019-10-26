// = Codeforces 100431H
#include <bits/stdc++.h>
#define int long long
using namespace std;
 
struct ship {
    int arr, id, ctype, size;
};
 
struct crane {
    vector<int> available;
    int speed;
};
 
int crane_work_until[100005];
int ship_processed[100005];
set<pair<int, int>> crane_queue[15];
deque<int> ship_dock[15];
 
int mapmap[100005];
 
int32_t main() {
#ifdef ONLINE_JUDGE
    freopen("seaport.in", "r", stdin);
    freopen("seaport.out", "w", stdout);
#endif
 
    memset(ship_processed, -1, sizeof(ship_processed));
    int n, m, c; cin >> n >> m >> c;
    vector<ship> ships;
    for (int i = 0; i < n; ++i) {
        int d, c, s; cin >> d >> c >> s;
        ships.push_back(ship{d, i, c, s});
    }
    sort(ships.begin(), ships.end(), [&] (const ship &a, const ship &b) {
        if (a.arr != b.arr) return a.arr < b.arr;
        return a.id < b.id;
    });
    // for (int i = 0; i < n; ++i) {
    //     mapmap[ships[i].id] = i;
    //     ships[i].id = i;
    // }
    vector<crane> cranes;
    for (int i = 0; i < m; ++i) {
        int v; cin >> v;
        int t; cin >> t;
        vector<int> tt(t);
        for (int i = 0; i < t; ++i) cin >> tt[i];
        cranes.push_back(crane{tt, v});
    }
    for (int i = 0; i < m; ++i) {
        for (int t : cranes[i].available) {
            crane_queue[t].insert(make_pair(crane_work_until[i], i));
        }
    }
 
    priority_queue<int, vector<int>, greater<int>> critical_t;
    for (int i = 0; i < n; ++i) critical_t.push(ships[i].arr);
    // for (int i = 0; i < n; ++i) // cout << "ship " << i << " arr = " << ships[i].arr << endl;
 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> crane_finish_record;
 
    int prev_t = -1;
    int ship_index = 0;
    while (critical_t.size()) {
        int nowt = critical_t.top(); critical_t.pop();
        if (nowt == prev_t) continue;
        prev_t = nowt;
        // cout << "nowt = " << nowt << endl;
        // cout << "  doing popping crane" << endl;
        while (crane_finish_record.size() && crane_work_until[crane_finish_record.top().second] <= nowt) {
            int crane_id = crane_finish_record.top().second;
            crane_finish_record.pop();
            // cout << "    crane_id = " << crane_id << endl;
            vector<int> &available = cranes[crane_id].available;
            int process_ship_index = -1;
            for (int ctype : available) {
                // cout << "      checking ctype = " << ctype << endl;
                if (ship_dock[ctype].size()) {
                    while (ship_dock[ctype].size() && ship_processed[ships[ship_dock[ctype].front()].id] != -1) ship_dock[ctype].pop_front();
                    if (ship_dock[ctype].empty()) continue;
                    // cout << "        ship id = " << ship_dock[ctype].front() << " be candidate" << endl;
                    if (process_ship_index == -1 || (ships[ship_dock[ctype].front()].arr < ships[process_ship_index].arr) || (ships[process_ship_index].arr == ships[ship_dock[ctype].front()].arr && ships[ship_dock[ctype].front()].id < ships[process_ship_index].id)) {
                        process_ship_index = ship_dock[ctype].front();
                    }
                }
            }
            // cout << "    process_ship_index: " << process_ship_index << endl;
            if (process_ship_index != -1) {
                ship now_come = ships[process_ship_index];
 
                int need_time = now_come.size / cranes[crane_id].speed + !!(now_come.size % cranes[crane_id].speed);
                int finish_time = nowt + need_time;
                ship_processed[now_come.id] = crane_id;
                critical_t.push(finish_time);
                crane_work_until[crane_id] = finish_time;
                crane_finish_record.emplace(finish_time, crane_id);
                // cout << "    assign ship " << process_ship_index << " to crane " << crane_id << ", work until " << finish_time << endl;
            } else {
                for (int i : available) crane_queue[i].insert(make_pair(nowt, crane_id));
            }
        }
 
        // cout << "  doing coming ship" << endl;
        while (ship_index < n && ships[ship_index].arr <= nowt) {
            ship now_come = ships[ship_index];
            // cout << "    ship " << now_come.id << " comes" << endl;
            while (crane_queue[now_come.ctype].size()) { // available crane
                int crane_id = crane_queue[now_come.ctype].begin()->second;
                crane_queue[now_come.ctype].erase(make_pair(crane_work_until[crane_id], crane_id));
                if (crane_work_until[crane_id] > now_come.arr) continue;
                for (int i : cranes[crane_id].available) crane_queue[i].erase(make_pair(crane_work_until[crane_id], crane_id));
 
                int need_time = now_come.size / cranes[crane_id].speed + !!(now_come.size % cranes[crane_id].speed);
                int finish_time = now_come.arr + need_time;
                ship_processed[now_come.id] = crane_id;
                critical_t.push(finish_time);
                crane_work_until[crane_id] = finish_time;
                crane_finish_record.emplace(finish_time, crane_id);
                // cout << "    assign ship " << now_come.id << " to crane " << crane_id << ", work until " << finish_time << endl;
                break;
            } 
            if (ship_processed[now_come.id] == -1) { // ship into dock
                ship_dock[now_come.ctype].push_back(ship_index);
                // cout << "      no available crane" << endl;
            }
            ++ship_index;
        }
    }
 
    for (int i = 0; i < n; ++i) cout << ship_processed[i] + 1 << '\n';
}
