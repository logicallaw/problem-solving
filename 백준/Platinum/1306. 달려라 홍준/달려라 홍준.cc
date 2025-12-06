#include <iostream>
#include <queue>
using namespace std;

int arr[1000002];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
       cin >> arr[i];
    }

    priority_queue<pair<int, int>> Q;

    int W = 2 * M - 1;
    int L = M - 1;
    int P = W - 1;
    int LAST = N - M + 1;

    for (int i = (M - L); i <= (M + L - 1); i++) {
        Q.push({arr[i], i});
    }

    for (int i = (M - L); i <= (LAST - L); i++) {
        Q.push({arr[i + P], i + P});

        while (!Q.empty() && Q.top().second < i) {
            Q.pop();
        }

        cout << Q.top().first << " ";
    }
}
/*
5 2
1 1 1 3 2
*/