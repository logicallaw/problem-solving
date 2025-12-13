#include <bits/stdc++.h>

using namespace std;

int N, S;
int arr[100000];

signed main() {
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int s = 0;
    int result = 1e9+10;
    int j = -1;
    for (int i = 0; i < N; i++) {
        while ((j+1 < N) && (s + arr[j+1] < S)) {
            s += arr[j+1];
            j++;
        }
        if (j + 1 >= N) {
            break;
        }
        result = min(result, j - i + 2);
        s -= arr[i];
    }
    if (result == 1e9+10) {
        result = 0;
    }
    cout << result;
}