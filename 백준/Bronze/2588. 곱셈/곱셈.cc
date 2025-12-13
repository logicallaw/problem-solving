#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
	unsigned int num1, num2;
	int a;
	int temp, numSum = 0;
	cin >> num1 >> num2;
	for (unsigned int cnt{ 0 }; cnt < 3; cnt++)
	{
		temp = num2 % 10;
		numSum += num1 * temp * pow(10,cnt);
		cout << num1 * temp << endl;
		num2 /= 10;
	}
	cout << numSum;
	return 0;
}