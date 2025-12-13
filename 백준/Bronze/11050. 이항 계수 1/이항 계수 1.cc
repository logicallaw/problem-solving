#include <iostream>
using namespace std;
int main(void){
    int n, k;
    cin >> n >> k;
    int kk = k;
    long result = 1;
    for(int i{ 0 }; i < kk; i++){
        result *= (n--);
    }
    for(int i{ 0 }; i < kk; i++){
        result /= (k--);
    }
    cout << result;
    return 0;
}