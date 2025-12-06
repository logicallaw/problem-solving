#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int arr[500001];
vector<int> max_val;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    double sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + N);


    cout << static_cast<int>(round(sum / N)) << "\n";
    cout << arr[N/2] << "\n";

    int cnt = 1;
    int max_cnt = 0;
    for (int i = 0; i < N - 1; i++) {
       if (arr[i] == arr[i+1]) {
           cnt++;
       } else {
           if (cnt > max_cnt) {
               max_cnt = cnt;
               max_val.clear();
               max_val.push_back(arr[i]);
           } else if (cnt == max_cnt) {
               max_val.push_back(arr[i]);
           }
           cnt = 1;
       }
    }
    if (cnt > max_cnt) {
        max_val.clear();
        max_val.push_back(arr[N-1]);
    } else if (cnt == max_cnt) {
        max_val.push_back(arr[N-1]);
    }

    sort(max_val.begin(), max_val.end());

    if (max_val.size() >= 2) {
        cout << max_val[1] << "\n";
    } else {
        cout << max_val[0] << "\n";
    }

    cout << arr[N-1] - arr[0] << "\n";
}