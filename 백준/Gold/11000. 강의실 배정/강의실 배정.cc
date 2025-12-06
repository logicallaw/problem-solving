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
        int S, T;
        cin >> S >> T;

        Q.push({S, 1});
        Q.push({T, -1});
    }

    int cur = 0;
    int max = 0;

    while (!Q.empty()) {
        pair top_node = Q.top();
        Q.pop();
        int Second = top_node.second;

        if (Second < 0) {
            cur--;
        } else {
            if (cur + Second > max) {
                max = cur + Second;
            }
            cur++;
        }
    }

    cout << max;
}