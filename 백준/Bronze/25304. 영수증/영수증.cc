#include <iostream>
using namespace std;
int main(void)
{
	unsigned int receiptNum, size, num1, num2;
	unsigned int numSum = 0;

	cin >> receiptNum;
	cin >> size;

	for (unsigned int cnt{ 0 }; cnt < size; cnt++)
	{
		cin >> num1 >> num2;
		numSum += num1 * num2;
	}
	if (receiptNum == numSum)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}