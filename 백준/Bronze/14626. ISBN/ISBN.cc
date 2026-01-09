#include <iostream>

using namespace std;

int W(int I) {
	if (I % 2 == 0) {
		//cout << I << "|" << 1 << "\n";
		return 1;
	}
	else {
		//cout << I << "|" << 3 << "\n";
		return 3;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int sum = 0;
	int M_W = -1;
	for (int i = 0; i < 12; i++) {
		if (s[i] == '*') {
			M_W = W(i);
		}
		else {
			sum += (s[i] - '0') * W(i);
		}
	}
	 
	int M = (s[12] - '0');
	int R = 10 - M;
	if (R == 10) R = 0;

	for (int ans = 0; ans < 10; ans++) {
		int TMP = (sum + M_W * ans) % 10;

		if (TMP == R) {
			cout << ans;
			return 0;
		}
	}
}