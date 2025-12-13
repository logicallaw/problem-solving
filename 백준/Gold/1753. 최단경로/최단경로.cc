#include <iostream>
#include <queue>

using namespace std;

int V, E, leader;

vector<pair<int, int>> v[20001];
int d[20001];
const int UNSEEN = 1e9+10;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> V >> E >> leader;

    for (int i = 1; i <= V; i++) {
        d[i] = UNSEEN;
    }

    while (E--) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({c, b});
    }

    d[leader] = 0;
    pq.push({d[leader], leader});
    while (!pq.empty()) {
        pair<int, int> tree_vertex = pq.top();
        pq.pop();

        if (d[tree_vertex.second] != tree_vertex.first) {
            continue;
        }

        for (pair<int, int> fringe: v[tree_vertex.second]) {
            // if (d[fringe.second] == UNSEEN) {
            //     d[fringe.second] = d[tree_vertex.second] + fringe.first;
            //     pq.push({d[fringe.second], fringe.second});
            //     continue;
            // }
            // if (d[fringe.second] > (d[tree_vertex.second] + fringe.first)) {
            //     d[fringe.second] = d[tree_vertex.second] + fringe.first;
            //     pq.push({d[fringe.second], fringe.second});
            // }
            if (d[fringe.second] <= d[tree_vertex.second] + fringe.first) {
                continue;
            }
            d[fringe.second] = d[tree_vertex.second] + fringe.first;
            pq.push({d[fringe.second], fringe.second});
        }
    }

    for (int i = 1; i <= V; i++) {
        if (d[i] == UNSEEN) {
            cout << "INF\n";
        } else {
            cout << d[i] << "\n";
        }
    }
}