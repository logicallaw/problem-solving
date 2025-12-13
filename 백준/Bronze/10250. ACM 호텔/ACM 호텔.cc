#include <iostream>
using namespace std;
int main(void) {
	int t;
	int h, w, n;
	cin >> t;
	while (t--) {
		cin >> h >> w >> n;
		int y, x;
		if (n % h == 0) {
			y = h;
			x = n / h;
		}
		else {
			y = n % h;
			x = n / h + 1;
		}
		if (x < 10)
			cout << y << "0" << x << "\n";
		else
			cout << y << x << "\n";
	}
	return 0;
}