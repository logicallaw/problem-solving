#include <iostream>
using namespace std;
int main(void) {
    string word;
    cin >> word;
    int lth = word.length();
    for(int i{ 0 }; i < lth/2; i++) {
        if(word[i] != word[lth - 1 - i]) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}