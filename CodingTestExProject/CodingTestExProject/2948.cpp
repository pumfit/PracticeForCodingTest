/*
2948 2009��

����� ������ ������ �ٸ��⵵�� Ǯ� ���ִµ� �� ������ ���� �޷���
���� Ǯ �� �ִ� �������� �ñ��ϴ�..

�������� swith case���� ��︱ �� ���Ƽ� Month�� �޾ƿ� �� ������ ù���� �������� ����ϵ��� �ߴ�.
���� �� �ٸ� ���� ã�ƺ� ��� �� ���� �ϼ��� �迭�� ����� �����ϴ� ��찡 ���Ҵ�. 
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int D, M;
	string arr[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

	cin >> D >> M;
	switch (M)
	{
	case 1:
		cout << arr[(D+2) % 7];//��
		break;
	case 2:
		cout << arr[(D+5) % 7];//��
		break;
	case 3:
		cout << arr[(D+5) % 7];//��
		break;
	case 4:
		cout << arr[(D+1) % 7];//��
		break;
	case 5:
		cout << arr[(D+3) % 7];//��
		break;
	case 6:
		cout << arr[(D+6) % 7];//��
		break;
	case 7:
		cout << arr[(D + 1) % 7];//��
		break;
	case 8:
		cout << arr[(D + 4) % 7];//��
		break;
	case 9:
		cout << arr[D % 7];//ȭ
		break;
	case 10:
		cout << arr[(D + 2) % 7];//��
		break;
	case 11:
		cout << arr[(D + 5) % 7];//��
		break;
	case 12:
		cout << arr[D % 7];//ȭ
		break;
	default:
		break;
	}

}