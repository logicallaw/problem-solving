#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> V;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        V.push_back(x);
    }

    sort(V.begin(), V.end());

    int total = 0;
    int prefixSum = 0;
    for (int i = 0; i < N; i++) {
        prefixSum += V[i];
        total += prefixSum;
    }

    cout << total;
}