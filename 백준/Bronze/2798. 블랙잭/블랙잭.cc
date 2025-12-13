#include <bits/stdc++.h>

using namespace std;

vector<int> v;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                int sum = v[i] + v[j] + v[k];
                if ((i != j && j != k && k != i) && sum <= M) {
                    result = (result < sum) ? sum : result;
                }
            }
        }
    }
    cout << result;
}