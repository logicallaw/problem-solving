#include <iostream>
#include <unordered_map>
#include <cmath>
#define int long long

using namespace std;

const int M = 1234567891;
const int R = 31;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    string str;
    cin >> str;

    int total = 0;
    for (int i = 0; i < N; i++) {
        int s = str[i] - 'a' + 1;
        int tmp = (s * pow(R, i));
        int t = (tmp % M);
        total = (total + t) % M;
    }
    cout << total;

}