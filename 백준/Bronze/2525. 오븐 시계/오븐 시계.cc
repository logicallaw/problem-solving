#include <iostream>
using namespace std;
int main(void)
{
	unsigned int hour, min, minAll;
	cin >> hour >> min;
	cin >> minAll;

	hour += minAll / 60;
	min += (minAll - (minAll / 60) * 60);
	if (min >= 60)
	{
		hour += min / 60;
		min -= (min / 60) * 60;
	}
	hour = (hour > 23) ? (hour-24) : hour;
	cout << hour << " " << min;

	return 0;
}