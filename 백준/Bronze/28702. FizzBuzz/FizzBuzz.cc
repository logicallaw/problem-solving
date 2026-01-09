#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

void f(int num) {
	if (num % 3 == 0 && num % 5 == 0) {
		cout << "FizzBuzz";
	}
	else if (num % 3 == 0 && num % 5 != 0) {
		cout <<  "Fizz";
	}
	else if (num % 5 == 0) {
		cout << "Buzz";
	}
	else {
		cout << num;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<string> V;

	for (int i = 0; i < 3; i++) {
		string s;
		cin >> s;
		
		V.push_back(s);
	}

	int stop = 2;
	for (int i = 0; i < 3; i++) {
		if (V[i] == "Fizz" || V[i] == "Buzz" || V[i] == "FizzBuzz") continue;
		stop = i;
		break;
	}

	switch (stop) {
	case 0:
		f(stoi(V[0]) + 3);
		break;
	case 1:
		f(stoi(V[1]) + 2);
		break;
	default:
		f(stoi(V[2]) + 1);
		break;
	}
}