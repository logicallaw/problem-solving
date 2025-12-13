#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E;
const int UNSEEN = 0x7ffffff;

vector<pair<int, int>> v[10001];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E;

    int d[V+1];
    bool visited[V+1];

    for (int i = 1; i <= V; i++) {
        d[i] = UNSEEN;
        visited[i] = false;
    }

    while (E--) {
        int A, B, C;
        cin >> A >> B >> C;
        v[A].push_back({C, B});
        v[B].push_back({C, A});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    d[1] = 0;
    visited[1] = true;
    for (pair fringe : v[1]) {
        if (d[fringe.second] > fringe.first) {
            d[fringe.second] = fringe.first;
            pq.push({d[fringe.second], fringe.second});
        }
    }

    int total = 0;

    while (!pq.empty()) {
        pair<int, int> tree_vertex = pq.top();
        pq.pop();

        if (d[tree_vertex.second] != tree_vertex.first) {
            continue;
        }
        if (visited[tree_vertex.second]) {
            continue;
        }
        visited[tree_vertex.second] = true;
        total += tree_vertex.first;

        for (pair fringe: v[tree_vertex.second]) {
            if (d[fringe.second] <= fringe.first) {
                continue;
            }
            d[fringe.second] = fringe.first;
            pq.push({d[fringe.second], fringe.second});
        }
    }

    cout << total;
}