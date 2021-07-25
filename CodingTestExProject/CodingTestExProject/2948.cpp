/*
2948 2009년

비슷한 문제를 이전에 다른년도로 풀어본 적있는데 이 문제는 정말 달력이
없이 풀 수 있는 문제인지 궁금하다..

오랫만에 swith case문이 어울릴 것 같아서 Month를 받아와 각 월마다 첫날을 기준으로 출력하도록 했다.
성공 후 다른 답을 찾아본 결과 각 월의 일수를 배열을 만들어 진행하는 경우가 많았다. 
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
		cout << arr[(D+2) % 7];//목
		break;
	case 2:
		cout << arr[(D+5) % 7];//일
		break;
	case 3:
		cout << arr[(D+5) % 7];//일
		break;
	case 4:
		cout << arr[(D+1) % 7];//수
		break;
	case 5:
		cout << arr[(D+3) % 7];//금
		break;
	case 6:
		cout << arr[(D+6) % 7];//월
		break;
	case 7:
		cout << arr[(D + 1) % 7];//수
		break;
	case 8:
		cout << arr[(D + 4) % 7];//토
		break;
	case 9:
		cout << arr[D % 7];//화
		break;
	case 10:
		cout << arr[(D + 2) % 7];//목
		break;
	case 11:
		cout << arr[(D + 5) % 7];//일
		break;
	case 12:
		cout << arr[D % 7];//화
		break;
	default:
		break;
	}

}