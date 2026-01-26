#include <iostream>
#include <string>
using namespace std;

int N, M;
string S;
int goal;
int ans;

pair<int, int> update(int a, int b) {
  // cout << a << " " << b << "\n";
  if (a == 0) {
    return {1, 1};
  }
  if (a == 1) {
    return {2, 2};
  }

  a += 1;
  if (a % 2 != 0) {
    b += (a / 2) + 1;
  } else {
    b += a / 2;
  }
  return {a, b};
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> S;
  goal = 2 * N + 1;
  int a, b;

  if (S[0] == 'O') {
    a = b = 0;
  } else {
    a = b = 1;
  }

  for (int i = 1; i < S.length(); i++) {
    if (S[i] == S[i-1]) {
      // OO
      if (S[i] == 'O') {
        a = b = 0;
      }
      // II
      else {
        a = b = 1;
      }
    } else {
      pair<int, int> rst = update(a, b);
      a = rst.first;
      b = rst.second;
      if (a == goal) {
        ans++;
        b -= a;
        a -= 2;
      }
    }
  }

  cout << ans;
}