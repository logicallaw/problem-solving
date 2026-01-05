#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

// 0~3 중 하나 반환
int getL(int N, int x, int y) {
    int MID = (N - 1) / 2;
    if (x <= MID && y <= MID) {
        return 0;
    }
    if (x <= MID && y > MID) {
        return 1;
    }
    if (y <= MID) {
        return 2;
    }
    return 3;
}

int getV(int x, int y) {
    if (x == 0 && y == 0) {
        return 0;
    }
    if (x == 0 && y == 1) {
        return 1;
    }
    if (x == 1 && y == 0) {
        return 2;
    }
    return 3;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, R, C;
    cin >> N >> R >> C;

    int SIZE = (1 << N);

    int total = 0;
    while (N != 1) {
        int L = getL(SIZE, R, C);
        total += pow(4, N - 1) * L;

        SIZE /= 2;
        R %= SIZE;
        C %= SIZE;
        N--;
    }

    total += getV(R, C);

    cout << total;
}
