#include <iostream>
using namespace std;
int main(void)
{
	unsigned int n;
	unsigned int result = 0;
	cin >> n;
	for (unsigned int counter{ 1 }; counter <= n; counter++)
	{
		result += counter;
	}
	cout << result << endl;

	return 0;
}