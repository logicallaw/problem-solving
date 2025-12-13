#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int arr[25][25] {};

bool isRange(int i, int j) {
    if(i >= 0 && i < n) {
        if(j >= 0 && j < n) {
            return true;
        }
    }
    return false;
}

int cnt = 0;

void dfs(int x, int y) {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    arr[x][y] = 0;
    cnt++;
    for(int i{ 0 }; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isRange(nx, ny) && arr[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
}

int main(void) {
    cin >> n;
    for(int i{ 0 }; i < n; i++) {
        string s;
        cin >> s;
        for(int j{ 0 }; j < n; j++) {
            arr[i][j] = s[j] - '0';
        }
    }
    vector<int> v;
    for(int i{ 0 }; i < n; i++) {
        for(int j{ 0 }; j < n; j++) {
            if(arr[i][j] == 1) {
                dfs(i, j);
                v.push_back(cnt);
                cnt = 0;
            }
        }
    }
    cout << v.size() << endl;
    sort(v.begin(), v.end());
    for(int& ele : v) {
        cout << ele << endl;
    }
    return 0;
}