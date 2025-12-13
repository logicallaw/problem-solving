#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, L;
    cin >> N >> L;

    vector<int> v;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

    for (int i = 0; i < N; i++) {
        Q.push({v[i], i});

        while (!Q.empty() && Q.top().second <= (i - L)) {
            Q.pop();
        }

    cout << Q.top().first << " ";
    }
}