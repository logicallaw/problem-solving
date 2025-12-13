#include <iostream>
using namespace std;
/*
1~6 주사위 3개를 던져서 나오는 눈의 수에 따라 상금을 받는다.
a,b,c
reward

(a==b)
	(a==c)
		1번째 a
		cout << (10000+a*1000);
	(else)
		2번째 a
		out << (1000+a*100);
(a==c)
	2번째 a
	cout << (1000+a*100);
(else)
	(b==c)
		2번째 b
		cout << (1000+b*100);
	(else)
		maxN = (a>b) ? a : b;
		maxN = (maxN>c) ? maxN : c;
		3번째 가장 큰수
		cout << (maxN * 100);

*/
int main(void)
{
	unsigned int a, b, c;
	unsigned int maxN;
	cin >> a >> b >> c;
	if (a == b)
	{
		if (a == c)
		{
			cout << (10000 + a * 1000);
		}
		else
		{
			cout << (1000 + a * 100);
		}
	}
	else if (a == c)
	{
		cout << (1000 + a * 100);
	}
	else
	{
		if (b == c)
		{
			cout << (1000 + b * 100);
		}
		else
		{
			maxN = (a > b) ? a : b;
			maxN = (maxN > c) ? maxN : c;
			cout << (maxN * 100);
		}
	}
	return 0;
}