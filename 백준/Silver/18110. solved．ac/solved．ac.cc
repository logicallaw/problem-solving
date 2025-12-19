#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int copy_n = n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    vector<int> V;

    while (n--) {
        int p;
        cin >> p;

        V.push_back(p);
    }

    sort(V.begin(), V.end());

    // for (auto &ele : V) {
    //     cout << ele << " ";
    // }
    // cout << "\n";

    int except = round((copy_n * (15.0 / 100.0)));

    double avg = 0.0;
    for (int i = except; i <= (copy_n - 1 - except); i++) {
        avg += V[i];
        // cout << V[i] << " ";
    }
    // cout << " " << copy_n - 1 - except - except + 1 << "\n";

    cout << round(avg / (copy_n - 1 - except - except + 1));

}
