#include <iostream>
using namespace std;
int arr[15][14] {};
int sol(const int row, const int col) {
    int sum = 0;
    for(int i{ 0 }; i <= col; i++) {
        sum += arr[row-1][i];
    }
    return sum;
}
int main(void) {
    for(int i{ 0 }; i < 14; i++) {
        arr[0][i] = i + 1;
    }
    for(int i{ 1 }; i <= 14; i++) {
        for(int j{ 0 }; j <= 13; j++) {
            arr[i][j] = sol(i, j);
        }
    }
//    for(int i{ 0 }; i < 15; i++) {
//        for(int j{ 0 }; j < 14; j++) {
//            cout << arr[i][j] << " ";
//        }
//        cout << endl;
//    }
    int t;
    cin >> t;
    while(t--) {
        int k, n;
        cin >> k >> n;
        cout << arr[k][n-1] << endl;
    }
    return 0;
}