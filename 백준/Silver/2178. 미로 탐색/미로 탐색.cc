#include <iostream>
#include <queue>

using namespace std;

int dist[100][100];
string board[100];

int n, m;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    queue<pair<int, int>> Q;

    Q.push({0,0});
    dist[0][0] = 0;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int i = 0 ; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] >= 1) continue;
            if (board[nx][ny] == '0') continue;

            Q.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }
    cout << dist[n-1][m-1] + 1;
}