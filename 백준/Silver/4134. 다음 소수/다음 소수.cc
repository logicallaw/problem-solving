#include <iostream>
#include <cmath>
using namespace std;
void getPrime(long long& number);
bool isPrime(const long long& number);

int main(void) {
	unsigned int size;
	cin >> size;
	while (size--) {
		long long number;
		cin >> number;
		getPrime(number);
	}
	return 0;
}

bool isPrime(const long long& number) {
	if (number == 0 || number == 1)
		return false;
	else if (number == 2)
		return true;

	for (int i{ 2 }; i <= sqrt(number) + 1; i++) {
		if (number % i == 0)
			return false;
	}
	
	return true;
}
void getPrime(long long& number) {
	while (!isPrime(number++)) {
		continue;
	}
	cout << number - 1 << endl;
}