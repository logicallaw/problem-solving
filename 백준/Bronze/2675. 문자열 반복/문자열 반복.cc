#include <iostream>
using namespace std;
int main(void)
{
	int size;
	int num;
	string str; //string형은 자동으로 문자열 길이를 할당한다.
	cin >> size;
	for (int i{ 0 }; i < size; i++)
	{
		cin >> num >> str;
		//length()멤버함수는 배열의 길이를 리턴한다.
		for (int j{ 0 }; j < str.length(); j++)
		{
				for (int k{ 0 }; k < num; k++)
					cout << str[j];
		}
		cout << endl;
	}
}