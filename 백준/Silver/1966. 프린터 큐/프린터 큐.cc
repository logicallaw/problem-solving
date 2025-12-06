#include <iostream>
#include <queue>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> Q;
        priority_queue<pair<int, int>> PQ;

        for (int i = 0; i < N; i++) {
            int pt;
            cin >> pt;
            Q.push({pt, i});
            PQ.push({pt, i});
        }

        int cnt = 0;
        while (!Q.empty()) {
            pair q = Q.front();
            Q.pop();
            pair pq = PQ.top();
            if (pq.first > q.first) {
                Q.push(q);
            } else if (pq.first == q.first) {
                PQ.pop();
                cnt++;

                if (q.second == M) {
                    cout << cnt << "\n";
                    break;
                }
            }
        }
    }
}