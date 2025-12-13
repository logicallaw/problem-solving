#include <iostream>
using namespace std;
bool isEndNumber(int num) {
    int cnt = 0;
    int pre = (num % 10);
    num /= 10;
    if(pre == 6) cnt++;
    while(num != 0) {
        int temp = (num % 10);
        if(temp == 6) {
            if(pre == 6) {
                cnt++;
                if(cnt == 3) return true;
            } else {
                cnt = 1;
            }
        } else {
            cnt = 0;
        }
        pre = temp;
        num /= 10;
    }
    return false;
}
int main(void) {
    int n;
    cin >> n;
    int cnt = 1;
    int num = 666;
    while(cnt != n) {
        num++;
        if(isEndNumber(num)) {
            cnt++;
        }
    }
    cout << num;
    return 0;
}