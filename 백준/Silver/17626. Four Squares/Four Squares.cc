#include <iostream>
#include <cmath>

using namespace std;

int dp[50'001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= N; i++) {
        bool first = true;
        for (int j = sqrt(i); j >= 1; j--) {
            int cur_value = 1 + dp[i - j * j];

            // cout << "===\n";    
            // cout << "i: " << i << "\n";
            // cout << "왼쪽: " << j * j << "(" << j << "^2), 오른쪽: " << i - j * j << "\n";
            // cout << "왼쪽: " << 1 << ", 오른쪽: " << dp[i-j*j] << "\n";
            // cout << "결과: " << 1 + dp[i-j*j] << "\n";
            // cout << ((1 + dp[i-j*j]) > 4 ? "무시" : "진행") << "\n";
            // cout << "===\n";
            // int cur = 1 + dp[i - j * j];

            // if (cur > 4) {
            //     cout << "continue: " << cur << "\n";
            //     cout << N - j * j << ", " << dp[N-j *j] << "=-=\n";
            //     continue;
            // }

            // if (i == N) {
            //     cout << j * j << " " << N - j * j << ": " << dp[N - j * j] << "\n";
            // }
            // if (i == N || i == 103) {
            //     if (dp[i] > 1 + dp[N-j*j]) {
            //         cout << i << " " << "j: " << j << ", 왼쪽: " << j * j << ", 오른쪽: " << N-j*j << ":" << " " << 1 + dp[N-j*j] << "\n";
            //     }
            // }
            if (first) {
                first = false;
                dp[i] = cur_value;
                continue;
            }
            if (dp[i] > cur_value) {
                dp[i] = cur_value;
                // cout << i << " " << cur << "\n";
            }
            // if (i == 7) {
            //     cout << dp[i] << "/";
            //     cout << 1 + dp[N - j * j] << "\n";
            // }
        }
        // cout << dp[18] << "==\n";
    }
    cout << dp[N];
}