#include <iostream>
#define int long long
using namespace std;

int arr[100002];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    int R = M - 1;

    for (int i = 1; i <= N; i++) {
       cin >> arr[i];
    }

    int sum = 0;
    for (int i = 1; i <= M; i++) {
        sum += arr[i];
    }

    int result = sum;

    for (int i = 2; i <= (N - M + 1); i++) {
        sum = sum - arr[i - 1] + arr[i + R];
        result = max(result, sum);
    }

    cout << result;
}
