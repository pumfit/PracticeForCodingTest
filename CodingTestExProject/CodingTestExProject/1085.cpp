/*
1085 ���簢������ Ż��

�� ������ �ڹٿ��� ������ Ǯ���� �� Ʋ�Ⱦ��µ� Ǯ�̰� ���� �޶�����.
�̹� Ǯ�̴� ���׿��������ַ� Ǯ�̸� �����Ͽ���.
*/

#include <iostream>
using namespace std;

int main()
{
	int x, y, w, h ,min =0;

	cin >> x >> y >> w >> h;

	int xMin = w - x > x ? x : w - x;
	int yMin = h - y > y ? y : h - y;
	min = xMin > yMin ? yMin : xMin;
	
	cout << min;
}