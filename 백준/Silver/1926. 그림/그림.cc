#include <iostream>
#include <queue>

using namespace std;

bool visited[500][500];
int arr[500][500];

int n, m;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isRange(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

bool canGo(int x, int y) {
    if (isRange(x, y) && !visited[x][y] && arr[x][y] == 1) {
        return true;
    }
    return false;
}

int bfs(int x, int y) {
    queue<pair<int, int>> q;

    q.push({x, y});
    visited[x][y] = true;

    int cnt = 0;

    while (!q.empty()) {
        cnt++;
        pair<int, int> p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;


        for (int i = 0 ; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (canGo(nx, ny)) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int total = 0;
    int maxImg = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1 && !visited[i][j]) {
                int result = bfs(i, j);
                maxImg = (result > maxImg) ? result : maxImg;
                total++;
            }
        }
    }

    cout << total << "\n" << maxImg;

    return 0;
}