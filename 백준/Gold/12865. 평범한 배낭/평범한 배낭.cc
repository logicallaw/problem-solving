#include <iostream>
#include <vector>
using namespace std;

int N, K;

int d[101][100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    vector<int> w(N + 1, 0);
    vector<int> v(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        int inputW, inputV;
        cin >> inputW >> inputV;

        w[i] = inputW;
        v[i] = inputV;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j - w[i] >= 0) {
                d[i][j] = max(d[i-1][j], d[i-1][j-w[i]] + v[i]);
            } else {
                d[i][j] = d[i-1][j];
            }
        }
    }

    cout << d[N][K];

}