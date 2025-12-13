#include <iostream>

using namespace std;

int arr[50][50];
bool visited[50][50];

int M, N, K;

bool isRange(const int& v, const int& L) {
    return (0 <= v) && (v < L);
}

bool canGo(int i, int j) {
    if (isRange(i, M) && isRange(j, N)) {
        if (!visited[i][j] && arr[i][j] == 1) {
            return true;
        }
    }
    return false;
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(const int& i, const int& j) {
    visited[i][j] = true;

    if (canGo(i + 1, j)) {
        dfs(i+1, j);
    }
    if (canGo(i, j + 1)) {
        dfs(i, j+1);
    }
    if (canGo(i-1, j)) {
        dfs(i-1, j);
    }
    if (canGo(i, j-1)) {
        dfs(i, j-1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                visited[i][j] = false;
                arr[i][j] = 0;
            }
        }

        cin >> M >> N >> K;

        while (K--) {
            int X, Y;
            cin >> X >> Y;
            arr[X][Y] = 1;
        }

        int cnt = 0;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (canGo(i, j)) {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << "\n";
    }
}