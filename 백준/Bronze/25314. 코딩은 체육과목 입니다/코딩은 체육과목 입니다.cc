#include <iostream>
using namespace std;
int main(void)
{
	unsigned int num;
	cin >> num;
	for (unsigned int cnt{ 4 }; cnt <= num; cnt += 4)
	{
		cout << "long ";
	}
	cout << "int";

	return 0;
}