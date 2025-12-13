#include <iostream>
#include <vector>
#include <algorithm> // sort, binary_search 사용
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 배열을 정렬
    sort(arr.begin(), arr.end());

    int m;
    cin >> m;
    while(m--) {
        int x;
        cin >> x;

        // 이진 탐색을 통해 x가 배열에 존재하는지 확인
        if(binary_search(arr.begin(), arr.end(), x)) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
    return 0;
}