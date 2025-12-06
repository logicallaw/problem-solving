#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int S, P;
string str;
unordered_map<char, int> UM;
int A, C, G, T;

bool check() {
    if (UM['A'] >= A && UM['C'] >= C && UM['G'] >= G && UM['T'] >= T) {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> S >> P;

    cin >> str;

    UM.insert({'A', 0});
    UM.insert({'C', 0});
    UM.insert({'G', 0});
    UM.insert({'T', 0});

    cin >> A >> C >> G >> T;

    for (int i = 0; i < P; i++) {
        UM[str[i]]++;
    }

    int R = P - 1;
    int result = 0;

    if (check()) {
        result++;
    }

    for (int i = 1; i <= (S - P) ; i++) {
        UM[str[i - 1]]--;
        UM[str[i + R]]++;
        if (check()) {
            result++;
        }
    }
    cout << result;
}
