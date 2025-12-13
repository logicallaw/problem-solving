#include <iostream>
#include <vector>
using namespace std;

int isPrime(const int& idx, vector<int>& primes);

int main(void) {
	int idx1, idx2;
	cin >> idx1 >> idx2;

	int sum = 0;
	vector<int> primes;
	for (; idx1 <= idx2; idx1++) {
		sum += isPrime(idx1, primes);
	}
	if (sum == 0) {
		cout << -1;
	}
	else {
		int min = primes[0];
		for (int i{ 1 }; i < primes.size(); i++)
			min = (min >= primes[i]) ? primes[i] : min;
		cout << sum << endl << min;
	}
	return 0;
}

int isPrime(const int& idx, vector<int>& primes) {
	for (int i{ 2 }; i <= idx / 2; i++) {
		if (idx % i == 0)
			return 0;
	}
	if (idx == 1) return 0;
	else {
		primes.push_back(idx);
		return idx;
	}
}