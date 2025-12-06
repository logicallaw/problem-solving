#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        int copy_i = i;
        int sum = i;
        while ((copy_i / 10) != 0) {
            sum += copy_i % 10;
            copy_i /= 10;
        }
        sum += copy_i;
        if (sum == N) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}