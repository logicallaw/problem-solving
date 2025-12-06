#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        Q.push({x, 1});
        Q.push({y, -1});
    }

    int tmp_s = 0;
    int accum = 0;
    int cur = 0;

    while (!Q.empty()) {
        pair top_node = Q.top();
        Q.pop();

        int First = top_node.first;
        int Second = top_node.second;

        if (cur == 0) {
            tmp_s = First;
        }

        if (Second < 0) {
            cur--;
        } else {
            cur++;
        }

        if (cur == 0) {
            accum += First - tmp_s;
        }
    }

    cout << accum;
}