#include <iostream>

using namespace std;

const int UNSEEN = 0x3f3f3f3f;

int d[101][101];
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                d[i][j] = 0;
            } else {
                d[i][j] = UNSEEN;
            }
        }
    }

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <=n; i++) {
            if (i == j) continue;
            if (d[i][j] == UNSEEN) continue;
            for (int k = 1; k <= n; k++) {
                if (i == k) continue;
                if (d[j][k] == UNSEEN) continue;
                d[i][k] = min(d[i][k], d[i][j] + d[j][k]);
            }
        }
    }

    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <=n; j++) {
            if (d[i][j] == UNSEEN) {
                cout << 0 << " ";
                continue;
            }
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
}